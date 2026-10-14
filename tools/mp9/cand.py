import re, os, glob, hashlib, collections, struct, json
BASE = 'build/SSQE01'
mods = sorted(os.listdir('config/SSQE01/rels'))
nums = {}
inst = collections.defaultdict(list)   # hash -> [(mod, name, addr, size, lines)]
for m in mods:
    d = open('orig/SSQE01/files/modules/' + m + '.rel', 'rb').read()
    nums[m] = struct.unpack('>I', d[:4])[0]
    syms = {}
    for l in open(f'config/SSQE01/rels/{m}/symbols.txt'):
        r = re.match(r'(\S+) = [.]text:0x([0-9A-F]+); // type:function size:0x([0-9A-F]+)', l)
        if r: syms[r[1]] = (int(r[2], 16), int(r[3], 16))
    cur = None; body = {}
    for f in glob.glob(f'{BASE}/{m}/asm/**/*.s', recursive=True):
        for l in open(f, errors='ignore'):
            mm = re.match(r'\.fn (\S+),', l)
            if mm: cur = mm[1]; body[cur] = []
            elif cur and l.startswith('/*'): body[cur].append(re.sub(r'/\*.*?\*/\s*', '', l).strip())
            elif l.startswith('.endfn'): cur = None
    loc = re.compile(r'\b(?:fn|lbl|jumptable)_' + str(nums[m]) + r'_\w+')
    for n, ls in body.items():
        if n.startswith(('gap_', 'pad_', '_prolog', '_epilog', '_unresolved', '__')) or n not in syms or len(ls) < 2 or len(ls) > 40: continue
        txt = '\n'.join(re.sub(r'\.L_[0-9A-F]+', '.L', l) for l in ls)
        if loc.search(txt): continue          # sin referencias locales (datos/otras funciones del módulo)
        h = hashlib.sha1(txt.encode()).hexdigest()[:14]
        inst[h].append((m, n, syms[n][0], syms[n][1], ls))
rows = [(len(set(x[0] for x in v)), h, v) for h, v in inst.items() if len(set(x[0] for x in v)) >= 10]
rows.sort(key=lambda r: -r[0])
print("grupos candidatos (>=10 módulos, <=40 instr, sin refs locales):", len(rows))
print("copias totales:", sum(r[0] for r in rows), " instrucciones totales:", sum(r[0] * len(r[2][0][4]) for r in rows))
for n, h, v in rows[:12]:
    print(f"{n:4} módulos  {len(v[0][4]):3} instr  ej {v[0][0]}:{v[0][1]}   | " + " ; ".join(v[0][4][:4]))
json.dump([{'n': n, 'h': h, 'items': [(x[0], x[1], x[2], x[3]) for x in v]} for n, h, v in rows], open(os.environ['TEMP'] + '/cand.json', 'w'))
