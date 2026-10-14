import json, os, collections
r = json.load(open(os.environ['TEMP'] + '/report.json'))
res = collections.defaultdict(list)
for u in r['units']:
    n = u['name']
    if '/REL/shared/g_' in n:
        g = n.split('/REL/shared/')[1]
        res[g].append(u['measures'].get('matched_code_percent', 0))
ok = [g for g, v in res.items() if all(x == 100 for x in v)]
bad = [g for g, v in res.items() if not all(x == 100 for x in v)]
print("grupos:", len(res), " al 100%% en todas sus copias: %d  con fallos: %d" % (len(ok), len(bad)))
print("copias totales:", sum(len(v) for v in res.values()), " al 100%%:", sum(1 for v in res.values() for x in v if x == 100))
open(os.environ['TEMP'] + '/ok.txt', 'w').write('\n'.join(ok))
print("fallan:", bad[:10])
