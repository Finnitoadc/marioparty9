#!/usr/bin/env python3
"""unregister.py <hash8> ...  -- undo sync/addgroups for a group: remove its unit from every
module's splits.txt, restore the original symbol name and drop its configure.py Object line.
The source file is left alone (move it to tools/mp9/wip/ if it does not match yet)."""
import json, re, sys

groups = {g['h'][:8]: g for g in json.load(open('tools/mp9/data/cand2.json'))}
for h8 in sys.argv[1:]:
    g = groups[h8]
    src = 'REL/shared/g_%s.cpp' % h8
    removed = 0
    seen = set()
    for module, sym, addr, size in g['items']:
        if module in seen:
            continue
        seen.add(module)
        sp = 'config/SSQE01/rels/%s/splits.txt' % module
        t = open(sp, newline='').read()
        nl = '\r\n' if '\r\n' in t else '\n'
        new, n = re.subn(re.escape(nl + nl + src + ':' + nl) + r'[^\r\n]*', '', t)
        if n:
            open(sp, 'w', newline='').write(new)
            removed += 1
            sy = 'config/SSQE01/rels/%s/symbols.txt' % module
            t = open(sy, newline='').read()
            t = re.sub(r'^shared_g_%s = ' % h8, sym + ' = ', t, count=1, flags=re.M)
            open(sy, 'w', newline='').write(t)
    p = 'configure.py'
    s = open(p, newline='').read()
    s = re.sub(r'[ ]+Object\(\w+, "%s"\),\r?\n' % re.escape(src), '', s)
    open(p, 'w', newline='').write(s)
    print('g_%s: removed from %d modules' % (h8, removed))
