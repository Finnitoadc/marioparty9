#!/usr/bin/env python3
"""tune_shared.py <cand2.json> <bad.txt>
For each failing shared group try several source variants; keep the first that reaches 100%."""
import itertools, json, os, re, subprocess, sys
sys.path.insert(0, os.path.dirname(__file__))
import gen_shared_simple as G

OBJDIFF = 'C:/Users/Juan Tobar/Desktop/objdiff/objdiff-cli-windows-x86_64.exe'
T = os.environ['TEMP']
BS = chr(92)

# flags of an existing REL shared compile
txt = re.sub(r'[$]\r?\n +', '', open('build.ninja').read())
m = re.search(r'build build.SSQE01.src.REL.shared.zero3[.]o:[^\n]*\n  mw_version = (\S+)\n  cflags = ([^\n]*)', txt)
VER, FLAGS = m.group(1), m.group(2).strip()
cfg = {u['name']: u for u in json.load(open('objdiff.json'))['units']}


def score(src, unit, sym):
    open(T + '/tune.cpp', 'w').write(src)
    cmd = ('build/tools/sjiswrap.exe build/compilers/' + VER + '/mwcceppc.exe ' + FLAGS + ' -c ' + T + '/tune.cpp -o ' + T + '/tune.o').replace('/', BS)
    r = subprocess.run(cmd, shell=True, capture_output=True, text=True)
    if r.returncode:
        return -1
    o = subprocess.run([OBJDIFF, 'diff', '-1', cfg[unit]['target_path'], '-2', T + '/tune.o', '-o', '-', '--format', 'json', sym], capture_output=True, text=True)
    try:
        d = json.loads(o.stdout)
    except Exception:
        return -1
    for s in d['left']['symbols']:
        if s['name'] == sym:
            return s.get('match_percent') or 0
    return -1


def variants(asm, name):
    yield 'base', G.gen(asm, name)
    yield 'temps', G.gen(asm, name, temps=True)
    yield 'rev', G.gen(asm, name, rev=True)
    yield 'temps+rev', G.gen(asm, name, temps=True, rev=True)
    yield 'struct', G.gen(asm, name, struct=True)


def main():
    groups = {g['h'][:8]: g for g in json.load(open(sys.argv[1]))}
    fixed = []
    for line in open(sys.argv[2]):
        g, unit = line.split()
        h = g[2:]
        grp = groups[h]
        name = 'shared_' + g
        best = None
        for label, src in variants(grp['asm'], name):
            if not src:
                continue
            sc = score(src, unit, name)
            if sc == 100:
                best = (label, src)
                break
        print(g, best[0] if best else 'sin solución')
        if best:
            open('src/REL/shared/%s.cpp' % g, 'w').write(best[1])
            fixed.append(g)
    open(T + '/fixed.txt', 'w').write('\n'.join(fixed))
    print(len(fixed), 'arreglados')


if __name__ == '__main__':
    main()
