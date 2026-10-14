import re, os, glob, hashlib, collections, struct
BASE = 'build/SSQE01'
mods = os.listdir('config/SSQE01/rels')
data = {}   # mod -> {fn: [lines]}
nums = {}
for m in mods:
    d = open('orig/SSQE01/files/modules/' + m + '.rel', 'rb').read()
    nums[m] = struct.unpack('>I', d[:4])[0]
    cur = None; body = {}
    for f in glob.glob(f'{BASE}/{m}/asm/**/*.s', recursive=True):
        for l in open(f, errors='ignore'):
            mm = re.match(r'\.fn (\S+),', l)
            if mm: cur = mm[1]; body[cur] = []
            elif cur and l.startswith('/*'): body[cur].append(re.sub(r'/\*.*?\*/\s*', '', l).strip())
            elif l.startswith('.endfn'): cur = None
    data[m] = {n: ls for n, ls in body.items() if not n.startswith(('gap_', 'pad_')) and len(ls) >= 3}
fnre = {m: re.compile(r'\bfn_' + str(nums[m]) + r'_\w+') for m in mods}
lblre = {m: re.compile(r'\b(?:lbl|jumptable)_' + str(nums[m]) + r'_\w+') for m in mods}
cur_h = {m: {n: 'x' for n in data[m]} for m in mods}   # round 0: all same
def round_(prev):
    new = {}
    for m in mods:
        new[m] = {}
        for n, ls in data[m].items():
            out = []
            for l in ls:
                l = re.sub(r'\.L_[0-9A-F]+', '.L', l)
                l = lblre[m].sub('DATA', l)
                l = fnre[m].sub(lambda mo: 'F:' + prev[m].get(mo.group(0), 'ext'), l)
                out.append(l)
            new[m][n] = hashlib.sha1('\n'.join(out).encode()).hexdigest()[:12]
    return new
h = cur_h
for r in range(4):
    h = round_(h)
    cnt = collections.defaultdict(set); ln = {}
    for m in mods:
        for n, hh in h[m].items():
            cnt[hh].add(m); ln[hh] = len(data[m][n])
    tot = sum(ln[x] * len(v) for x, v in cnt.items())
    uni = sum(ln[x] for x in cnt)
    sing = sum(ln[x] for x, v in cnt.items() if len(v) == 1)
    print(f"ronda {r+1}: únicas {uni:>8} / totales {tot} = {100*uni/tot:.1f}%   (en 1 solo módulo: {100*sing/uni:.0f}% de las únicas)")
