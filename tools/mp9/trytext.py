#!/usr/bin/env python3
"""trytext.py <hash8> [srcfile]   compile src/REL/shared/g_<hash8>.cpp and compare its asm with the group's asm."""
import json, os, re, subprocess, sys
BS = chr(92)
T = os.environ['TEMP']
h8 = sys.argv[1]
src = sys.argv[2] if len(sys.argv) > 2 else 'src/REL/shared/g_%s.cpp' % h8
groups = {g['h'][:8]: g for g in json.load(open('tools/mp9/data/cand2.json'))}
g = groups[h8]
txt = re.sub(r'[$]\r?\n +', '', open('build.ninja').read())
m = re.search(r'build build.SSQE01.src.REL.shared.zero3[.]o:[^\n]*\n  mw_version = (\S+)\n  cflags = ([^\n]*)', txt)
ver, flags = m.group(1), m.group(2).strip()
cmd = ('build/tools/sjiswrap.exe build/compilers/' + ver + '/mwcceppc.exe ' + flags + ' -c ' + src + ' -o ' + T + '/tt_' + h8 + '.o').replace('/', BS)
r = subprocess.run(cmd, shell=True, capture_output=True, text=True)
if r.returncode:
    print('COMPILE ERROR', (r.stdout + r.stderr)[-500:]); sys.exit(1)
subprocess.run(('build/tools/dtk.exe elf disasm ' + T + '/tt_' + h8 + '.o ' + T + '/tt_' + h8 + '.s').replace('/', BS), shell=True, capture_output=True)
cur = None; mine = []; mbase = None
for l in open(T + '/tt_' + h8 + '.s', errors='ignore'):
    mm = re.match(r'\.fn (\S+),', l)
    if mm: cur = mm.group(1) if 'shared_g_' + h8 in mm.group(1) else None; mbase = None
    elif cur and l.startswith('/*'):
        if mbase is None: mbase = int(l.split()[1], 16)
        mine.append(re.sub(r'/[*].*?[*]/\s*', '', l).strip())
    elif l.startswith('.endfn'): cur = None
def tbase(ls):
    labs = [int(x, 16) for l in ls for x in re.findall(r'[.]L_([0-9A-Fa-f]+)', l)]
    for it in g['items']:
        if all(it[2] <= x <= it[2] + 4 * len(ls) for x in labs): return it[2]
    return None
def norm(ls, base=None):
    out = []
    for l in ls:
        if base is not None:
            l = re.sub(r'[.]L_([0-9A-Fa-f]+)', lambda m: '.L%+d' % ((int(m.group(1), 16) - base) // 4), l)
        l = re.sub(r'[.]L_[0-9A-Fa-f]+', '.L', l)
        l = re.sub(r'^(b\w*)\s+0x[0-9A-Fa-f]+', r'\1 .L', l)
        l = re.sub(r'"?@\d+"?', 'X', l)
        out.append(l)
    return out
ALIAS = {'__ptmf_test': 'fn_8020BDC8', '__ptmf_scall': 'fn_8020BE34'}  # DOL symbols renamed after cand2.json was built
mine = [re.sub(r'(' + '|'.join(ALIAS) + r')', lambda m: ALIAS[m.group(1)], l) for l in mine]
tasm = [re.sub(r'(' + '|'.join(ALIAS) + r')', lambda m: ALIAS[m.group(1)], l) for l in g['asm']]
a, b = norm(tasm, tbase(tasm)), norm(mine, mbase)
TAIL = a and (a[-1].startswith('b ') or a[-1].startswith('bctr')) and not a[-1].startswith('blr')
if TAIL and b == a + ['blr']:
    print('MATCH 100% (+blr)', len(a), 'instr'); sys.exit(0)
if a == b:
    print('MATCH 100%', len(a), 'instr'); sys.exit(0)
print('DIFF  target(%d) | mine(%d)' % (len(a), len(b)))
for i in range(max(len(a), len(b))):
    x = a[i] if i < len(a) else ''; y = b[i] if i < len(b) else ''
    print(('  ' if x == y else '* ') + '%-34s | %s' % (x, y))
