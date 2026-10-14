#!/usr/bin/env python3
"""sync.py  -- register every src/REL/shared/g_<hash8>.cpp in all REL modules (idempotent).

For each shared source it makes sure that:
  * every module copy of the group has a REL/shared/g_<hash8>.cpp unit in its splits.txt
    (plus the 4-byte `blr` dtk splits off after a tail call, when present),
  * the symbol is renamed to shared_g_<hash8> in that module's symbols.txt,
  * configure.py has an Object(...) line for it (NonMatching if listed in
    tools/mp9/data/nonmatching.txt, Matching otherwise).

Use it after a merge: resolve conflicts in config/SSQE01/rels/** and configure.py by taking
one side completely (e.g. `git checkout --theirs config/SSQE01/rels configure.py`), then run
this script to add back the groups that came from the other side.
"""
import json, os, re, sys
sys.path.insert(0, 'tools')
import shared_split as ss

SKIP = {'strap', 'Introduction'}
groups = {g['h'][:8]: g for g in json.load(open('tools/mp9/data/cand2.json'))}
nm_path = 'tools/mp9/data/nonmatching.txt'
nonmatching = set(l.split()[0] for l in open(nm_path) if l.strip()) if os.path.exists(nm_path) else set()
hashes = sorted(f[2:10] for f in os.listdir('src/REL/shared') if re.match(r'g_[0-9a-f]{8}[.]cpp$', f))

syms_cache = {}
def symbols(module):
    if module not in syms_cache:
        syms_cache[module] = open('config/SSQE01/rels/%s/symbols.txt' % module).read()
    return syms_cache[module]

added_units = 0
for h8 in hashes:
    g = groups.get(h8)
    if g is None:
        print('WARNING: g_%s.cpp has no group in cand2.json, skipped' % h8)
        continue
    name = 'g_' + h8
    src = 'REL/shared/%s.cpp' % name
    tail = g['asm'] and (g['asm'][-1].startswith('b ') or g['asm'][-1].startswith('bctr'))
    seen = set()
    for module, sym, addr, size in g['items']:
        if module in SKIP or module in seen or addr < 0x74:
            continue
        seen.add(module)
        if tail:
            pat = r'^[^ ]+ = [.]text:0x%08X; // type:function size:0x4$' % (addr + size)
            if re.search(pat, symbols(module), re.M | re.I):
                size += 4
        if ss.add_unit(module, sym, addr, size, name, src):
            syms_cache.pop(module, None)
            added_units += 1

p = 'configure.py'
s = open(p, newline='').read()
nl = '\r\n' if '\r\n' in s else '\n'
anchor = '            Object(Matching, "REL/shared/zero1.cpp"),'
new = []
for h8 in hashes:
    src = 'REL/shared/g_%s.cpp' % h8
    if ('"%s"' % src) in s:
        continue
    status = 'NonMatching' if h8 in nonmatching else 'Matching'
    new.append('            Object(%s, "%s"),' % (status, src))
if new:
    s = s.replace(anchor, anchor + nl + nl.join(new), 1)
    open(p, 'w', newline='').write(s)
print('sources: %d   new module units: %d   new configure.py objects: %d' % (len(hashes), added_units, len(new)))
