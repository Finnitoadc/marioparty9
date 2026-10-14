#!/usr/bin/env python3
"""apply_shared_batch.py <cand2.json> <gen_dir> <hashes_file> <start> <count>
Copies generated sources to src/REL/shared, splits every module copy, registers objects."""
import json, os, shutil, sys
sys.path.insert(0, os.path.dirname(__file__))
import shared_split as ss

cand, gen, hashes_file, start, count = sys.argv[1], sys.argv[2], sys.argv[3], int(sys.argv[4]), int(sys.argv[5])
groups = {g['h']: g for g in json.load(open(cand))}
hashes = [h.strip() for h in open(hashes_file) if h.strip()]
hashes.sort(key=lambda h: -groups[h]['n'])
batch = hashes[start:start + count]
SKIP = {'strap', 'Introduction'}
objs = []
for h in batch:
    g = groups[h]
    name = 'g_' + h[:8]
    src = 'REL/shared/%s.cpp' % name
    shutil.copy(os.path.join(gen, name + '.cpp'), os.path.join('src', src))
    seen, done = set(), 0
    for module, sym, addr, size in g['items']:
        if module in SKIP or module in seen or addr < 0x74:
            continue
        seen.add(module)
        if ss.add_unit(module, sym, addr, size, name, src):
            done += 1
    objs.append(src)
    print(name, g['n'], done)
open('shared_objs_batch.txt', 'w').write('\n'.join(objs))
