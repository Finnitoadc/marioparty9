import json,subprocess,sys
unit,sym=sys.argv[1],sys.argv[2]
o=subprocess.run(["C:/Users/Juan Tobar/Desktop/objdiff/objdiff-cli-windows-x86_64.exe","diff","-p",".","-u",unit,"-o","-","--format","json",sym],capture_output=True,text=True)
d=json.loads(o.stdout)
for side in ("left","right"):
    for s in d[side]["symbols"]:
        if s["name"]==sym:
            print(side, "match%:", s.get("match_percent"))
            for i in s["instructions"]:
                print("  ",i["instruction"]["formatted"] if "instruction" in i and "formatted" in i["instruction"] else i, i.get("diff_kind",""))
