#!/usr/bin/env python3
"""Generate C++ for tiny straight-line functions from their asm (getters, setters, copies...).

Reads cand2.json (list of {n, ln, h, asm, items}) and writes src/REL/shared/g_<hash>.cpp for
every group whose asm is fully understood. Prints the accepted group hashes (one per line).
"""
import json
import re
import sys

LOAD = {'lwz': 'int', 'lbz': 'unsigned char', 'lhz': 'unsigned short', 'lha': 'short', 'lfs': 'float'}
STORE = {'stw': 'int', 'stb': 'unsigned char', 'sth': 'short', 'stfs': 'float'}


def num(s):
    s = s.strip()
    return int(s, 16) if s.lower().startswith(('0x', '-0x')) else int(s)


def mem(op):
    m = re.fullmatch(r'(-?(?:0x)?[0-9A-Fa-f]+)\((r\d+)\)', op.strip())
    return (num(m.group(1)), m.group(2)) if m else None


def gen(asm, name, temps=False, rev=False, struct=False):
    regs = {}        # reg -> expr
    tcount = [0]
    used_int, used_flt = set(), set()
    stmts = []

    def get(r):
        if r not in regs:
            if r.startswith('f'):
                used_flt.add(int(r[1:]))
                regs[r] = 'f%d' % int(r[1:])
            else:
                used_int.add(int(r[1:]))
                regs[r] = 'a%d' % (int(r[1:]) - 3)
        return regs[r]

    for line in asm:
        parts = line.split(None, 1)
        op = parts[0]
        args = [a.strip() for a in parts[1].split(',')] if len(parts) > 1 else []
        if op == 'blr':
            break
        if op in LOAD:
            m = mem(args[1])
            if not m:
                return None
            off, base = m
            e = '*(%s*)(%s + %d)' % (LOAD[op], get(base), off)
            if temps:
                t = 't%d' % tcount[0]
                tcount[0] += 1
                stmts.append('%s %s = %s;' % (LOAD[op], t, e))
                e = t
            regs[args[0]] = e
        elif op in STORE:
            m = mem(args[1])
            if not m:
                return None
            off, base = m
            stmts.append('*(%s*)(%s + %d) = %s;' % (STORE[op], get(base), off, get(args[0])))
        elif op == 'li':
            regs[args[0]] = str(num(args[1]))
        elif op == 'mr':
            regs[args[0]] = get(args[1])
        elif op == 'addi':
            regs[args[0]] = '(%s + %d)' % (get(args[1]), num(args[2]))
        elif op == 'subi':
            regs[args[0]] = '(%s - %d)' % (get(args[1]), num(args[2]))
        elif op == 'slwi':
            regs[args[0]] = '(%s << %d)' % (get(args[1]), num(args[2]))
        elif op == 'add':
            regs[args[0]] = '(%s + %s)' % (get(args[1]), get(args[2]))
        else:
            return None
    ret = 'void'
    retexpr = None
    # which reg was last written?  r3 / f1 decide the return
    written = {l.split(None, 1)[1].split(',')[0].strip() for l in asm
               if l.split()[0] in list(LOAD) + ['li', 'mr', 'addi', 'subi', 'slwi', 'add']}
    if 'f1' in written:
        ret, retexpr = 'float', regs['f1']
    elif 'r3' in written:
        ret, retexpr = 'int', regs['r3']
    params = []
    n_int = max(used_int) - 2 if used_int else 0
    for i in range(n_int):
        params.append('int a%d' % i)
    n_flt = max(used_flt) if used_flt else 0
    for i in range(1, n_flt + 1):
        params.append('float f%d' % i)
    if rev:
        loads = [x for x in stmts if '=' in x and x.lstrip().startswith(tuple(LOAD.values()))]
        sts = [x for x in stmts if x not in loads]
        stmts = loads + sts[::-1]
    if struct:
        pat = re.compile(r'[*][(]int[*][)][(]a0 [+] (\d+)[)] = [*][(]int[*][)][(]a1 [+] (\d+)[)];')
        m1 = [pat.fullmatch(x) for x in stmts]
        if stmts and all(m1) and all(x.group(1) == x.group(2) for x in m1):
            n = len(m1)
            NL = chr(10)
            return ('struct S%d { int w[%d]; };' % (n, n)) + NL + ('extern "C" void %s(S%d* a0, S%d* a1) {' % (name, n, n)) + NL + '    *a0 = *a1;' + NL + '}' + NL
    body = ['    ' + s for s in stmts]
    if retexpr is not None:
        body.append('    return %s;' % retexpr)
    return 'extern "C" %s %s(%s) {\n%s\n}\n' % (ret, name, ', '.join(params) or 'void', '\n'.join(body))


def main():
    groups = json.load(open(sys.argv[1]))
    out_dir = sys.argv[2]
    for g in groups:
        asm = g['asm']
        if not asm or g['ln'] > 8:
            continue
        if any(re.match(r'(b|beq|bne|blt|bgt|ble|bge|bl|bctr|bctrl|cmp)', l.split()[0]) and l.split()[0] not in ('blr',) for l in asm):
            continue
        name = 'shared_g_' + g['h'][:8]
        src = gen(asm, name)
        if src:
            open('%s/g_%s.cpp' % (out_dir, g['h'][:8]), 'w').write(src)
            print(g['h'])


if __name__ == '__main__':
    main()
