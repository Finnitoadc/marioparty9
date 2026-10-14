import re, subprocess, sys, os
BS = chr(92)
txt = open('build.ninja').read()
txt = re.sub(r'[$]\r?\n +', '', txt)
unit = sys.argv[1]
pat = r'build build.SSQE01.src.REL.strap.' + re.escape(unit.split('.')[0]) + r'[.]o:[^\n]*\n  mw_version = (\S+)\n  cflags = ([^\n]*)'
m = re.search(pat, txt)
ver, flags = m.group(1), m.group(2).strip()
for item in sys.argv[2:]:
    old, new = item.split('::')
    assert old in flags, old
    flags = flags.replace(old, new)
ver = ver.replace('/', BS).replace(BS, '/')
cc = 'build/compilers/' + ver + '/mwcceppc.exe'
out = os.environ['TEMP'] + '/cc2.o'
cmd = 'build/tools/sjiswrap.exe ' + cc + ' ' + flags + ' -c src/REL/strap/' + unit + ' -o ' + out
cmd = cmd.replace('/', BS)
r = subprocess.run(cmd, shell=True, capture_output=True, text=True)
print("rc", r.returncode, (r.stdout + r.stderr)[-300:] if r.returncode else "")
