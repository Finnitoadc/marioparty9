import json, subprocess, sys
unit, sym = sys.argv[1], sys.argv[2]
o = subprocess.run(["C:/Users/Juan Tobar/Desktop/objdiff/objdiff-cli-windows-x86_64.exe", "diff", "-p", ".", "-u", unit, "-o", "-", "--format", "json", sym], capture_output=True, text=True)
d = json.loads(o.stdout)
def get(side):
    for s in d[side]["symbols"]:
        if s["name"] == sym:
            return s["instructions"]
L, R = get("left"), get("right")
def fmt(i):
    if "instruction" in i:
        return i["instruction"].get("formatted", "?") + ("  <" + i.get("diff_kind", "").replace("DIFF_", "") + ">" if i.get("diff_kind") else "")
    return "-- " + i.get("diff_kind", "").replace("DIFF_", "")
n = max(len(L), len(R))
for k in range(n):
    a = fmt(L[k]) if k < len(L) else ""
    b = fmt(R[k]) if k < len(R) else ""
    mark = " " if ("<" not in a and "<" not in b and not a.startswith("--") and not b.startswith("--")) else "*"
    print(f"{mark} {a:48} | {b}")
