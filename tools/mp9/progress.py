#!/usr/bin/env python3
"""Quick progress report (about 1 second): how much of the REL/DOL code is matched by our C sources."""
import os, re, json
base = 'config/SSQE01/rels'
cfg = open('configure.py').read()
matching = set(re.findall(r'Object\(Matching, "(REL/[\w/]+\.cpp)"', cfg))
copies = byt = 0
groups = set()
tot_funcs = tot_bytes = 0
for m in os.listdir(base):
    sp = open(os.path.join(base, m, 'splits.txt')).read()
    for name, rng in re.findall(r'^(REL/shared/[\w]+\.cpp):\n\t\.text\s+start:0x([0-9A-Fa-f]+) end:0x([0-9A-Fa-f]+)', sp, re.M) and [(a, (int(b, 16), int(c, 16))) for a, b, c in re.findall(r'^(REL/shared/[\w]+\.cpp):\n\t\.text\s+start:0x([0-9A-Fa-f]+) end:0x([0-9A-Fa-f]+)', sp, re.M)]:
        if name in matching:
            copies += 1; byt += rng[1] - rng[0]; groups.add(name)
    sy = open(os.path.join(base, m, 'symbols.txt')).read()
    for s in re.findall(r'type:function size:0x([0-9A-F]+)', sy):
        tot_funcs += 1; tot_bytes += int(s, 16)
done = set(f[:-4] for f in os.listdir('src/REL/shared'))
cand = json.load(open('tools/mp9/data/cand2.json'))
pending = [g for g in cand if 'g_' + g['h'][:8] not in done and g['asm']]
print("Funciones de REL coincidentes: %d de %d (%.1f%%)" % (copies, tot_funcs, 100.0 * copies / tot_funcs))
print("Bytes de código REL coincidentes: %d de %d (%.2f%%)" % (byt, tot_bytes, 100.0 * byt / tot_bytes))
print("Archivos C compartidos enlazados: %d    Grupos pendientes en la cola: %d (%d copias)" % (len(groups), len(pending), sum(g['n'] for g in pending)))
