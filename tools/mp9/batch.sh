#!/bin/bash
# uso: batch.sh START COUNT
cd "C:/Users/Juan Tobar/Desktop/marioparty9"
S=$1; C=$2
python -I tools/apply_shared_batch.py "$TEMP/cand2.json" "$TEMP/gen" "$TEMP/accepted.txt" $S $C | tail -1
python - <<'PY'
p="configure.py"
s=open(p,newline='').read()
nl="\r\n" if "\r\n" in s else "\n"
objs=[l.strip() for l in open('shared_objs_batch.txt') if l.strip()]
anchor='            Object(Matching, "REL/shared/zero1.cpp"),'
s=s.replace(anchor,anchor+nl+nl.join('            Object(NonMatching, "%s"),'%o for o in objs),1)
open(p,"w",newline='').write(s)
print(len(objs),"objetos registrados")
PY
targets=$(sed 's|REL/shared/\(.*\)\.cpp|build/SSQE01/src/REL/shared/\1.o|' shared_objs_batch.txt | tr '\n' ' ')
rm -f shared_objs_batch.txt build/SSQE01/ok
ninja 2>&1 | grep -a "FAILED\|rror\|files OK" | head -3
ninja $targets 2>&1 | grep -a "FAILED\|rror" | head -3
"C:/Users/Juan Tobar/Desktop/objdiff/objdiff-cli-windows-x86_64.exe" report generate -p . -o "$TEMP/report.json" >/dev/null 2>&1
python -I "$TEMP/rep2.py" | head -2
python - <<'PY'
import os
p="configure.py"
s=open(p,newline='').read()
ok=[l.strip() for l in open(os.environ['TEMP']+'/ok.txt') if l.strip()]
n=0
for g in ok:
    old='Object(NonMatching, "REL/shared/%s.cpp")'%g
    if old in s: s=s.replace(old,'Object(Matching, "REL/shared/%s.cpp")'%g); n+=1
open(p,"w",newline='').write(s)
print(n,"pasan a Matching")
PY
rm -f build/SSQE01/ok
ninja 2>&1 | grep -a "FAILED\|files OK\|\.rel: FAILED" | head -3
