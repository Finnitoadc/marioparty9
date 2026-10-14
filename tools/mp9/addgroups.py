#!/usr/bin/env python3
"""addgroups.py <hash8>[+] ...   split + register groups whose source already exists in src/REL/shared.
A trailing '+' means the unit must also cover the 4-byte `blr` that dtk split off after a tail call."""
import json, os, re, sys
sys.path.insert(0, 'tools')
import shared_split as ss
T = os.environ['TEMP']
groups = {g['h'][:8]: g for g in json.load(open('tools/mp9/data/cand2.json'))}
SKIP = {'strap', 'Introduction'}
objs = []
for arg in sys.argv[1:]:
    extra = arg.endswith('+')
    h8 = arg.rstrip('+')
    g = groups[h8]
    name = 'g_' + h8
    src = 'REL/shared/%s.cpp' % name
    seen, done = set(), 0
    for module, sym, addr, size in g['items']:
        if module in SKIP or module in seen or addr < 0x74:
            continue
        if extra:
            t = open('config/SSQE01/rels/%s/symbols.txt' % module).read()
            pat = r'^[^ ]+ = [.]text:0x%08X; // type:function size:0x4$' % (addr + size)
            if not re.search(pat, t, re.M | re.I):
                continue
            size += 4
        seen.add(module)
        if ss.add_unit(module, sym, addr, size, name, src):
            done += 1
    objs.append(src)
    print(name, g['n'], done)
p = 'configure.py'
s = open(p, newline='').read()
nl = '\r\n' if '\r\n' in s else '\n'
anchor = '            Object(Matching, "REL/shared/zero1.cpp"),'
add = nl.join('            Object(Matching, "%s"),' % o for o in objs if ('"%s"' % o) not in s)
s = s.replace(anchor, anchor + nl + add, 1)
open(p, 'w', newline='').write(s)
