#!/usr/bin/env python3
"""queue.py [N] [skip]  -- next N pending groups ordered by number of module copies (skip = hashes in tools/mp9/data/skip.txt)."""
import json, os, re, sys
n = int(sys.argv[1]) if len(sys.argv) > 1 else 10
done = set(f[:-4] for f in os.listdir('src/REL/shared'))
skip = set(l.split()[0] for l in open('tools/mp9/data/skip.txt')) if os.path.exists('tools/mp9/data/skip.txt') else set()
cand = [g for g in json.load(open('tools/mp9/data/cand2.json')) if g['asm'] and 'g_' + g['h'][:8] not in done and g['h'][:8] not in skip]
cand.sort(key=lambda g: (-g['n'], g['h']))
for g in cand[:n]:
    body = [re.sub(r'[.]L_[0-9A-F]+', '.L', l) for l in g['asm'] if not l.startswith(('lwz r31, 0xc', 'lwz r30, 0x8', 'lwz r0, 0x14', 'mtlr', 'addi r1', 'stw r0, 0x14', 'mflr', 'stwu r1, -0x10'))]
    print('== %s  %d módulos  %d instr' % (g['h'][:8], g['n'], g['ln']))
    print('   ' + ' | '.join(body))
