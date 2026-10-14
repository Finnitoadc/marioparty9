#!/usr/bin/env python3
"""show.py <hash8> ...  -- print a group's full target asm (branch targets as relative instruction
indices, like trytext.py) and how many modules contain it."""
import json, re, sys
groups = {g['h'][:8]: g for g in json.load(open('tools/mp9/data/cand2.json'))}
for h8 in sys.argv[1:]:
    g = groups[h8]
    ls = g['asm']
    labs = [int(x, 16) for l in ls for x in re.findall(r'[.]L_([0-9A-Fa-f]+)', l)]
    base = next((it[2] for it in g['items'] if all(it[2] <= x <= it[2] + 4 * len(ls) for x in labs)), None)
    print('== g_%s  %d modules  %d instr  (e.g. %s %s)' % (h8, g['n'], len(ls), g['items'][0][0], g['items'][0][1]))
    for i, l in enumerate(ls):
        if base is not None:
            l = re.sub(r'[.]L_([0-9A-Fa-f]+)', lambda m: '.L%+d' % ((int(m.group(1), 16) - base) // 4), l)
        print('  %3d  %s' % (i, l))
