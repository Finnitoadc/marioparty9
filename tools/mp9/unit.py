import json, subprocess, sys
unit = sys.argv[1]
o = subprocess.run(["C:/Users/Juan Tobar/Desktop/objdiff/objdiff-cli-windows-x86_64.exe", "diff", "-p", ".", "-u", unit, "-o", "-", "--format", "json"], capture_output=True, text=True)
d = json.loads(o.stdout)
for s in d["left"]["symbols"]:
    mp = s.get("match_percent")
    if mp is not None or s.get("size"):
        print(f"{s['name']:28} {s.get('size','?'):>6}  {mp if mp is not None else '-'}")
