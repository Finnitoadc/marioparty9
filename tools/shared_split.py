#!/usr/bin/env python3
"""Split one shared function group into its own unit in every REL module.

Usage: shared_split.py <group-name> <cand-json-key-file> <key>
Items are (module, symbol, address, size). The symbol is renamed to
shared_<group> in each module's symbols.txt and a unit REL/shared/<group>.cpp
covering [addr, addr+size) of .text is added to the module's splits.txt.
"""
import json
import os
import re
import sys

REL_CFG = 'config/SSQE01/rels'


def parse_splits(text):
    nl = '\r\n' if '\r\n' in text else '\n'
    parts = re.split(r'(?:\r?\n){2,}', text.strip('\r\n'))
    header = parts[0]
    units = []
    for blk in parts[1:]:
        lines = blk.splitlines()
        m = re.search(r'\.text\s+start:0x([0-9A-Fa-f]+)', blk)
        start = int(m.group(1), 16) if m else 1 << 60
        units.append((start, lines[0].rstrip(':'), blk))
    return nl, header, units


def add_unit(module, sym, addr, size, group, src):
    sp = os.path.join(REL_CFG, module, 'splits.txt')
    text = open(sp, newline='').read()
    nl, header, units = parse_splits(text)
    if any(u[1] == src for u in units):
        return False
    blk = nl.join([src + ':', '\t.text       start:0x%08X end:0x%08X' % (addr, addr + size)])
    units.append((addr, src, blk))
    units.sort(key=lambda u: u[0])
    out = nl.join([header] + [u[2] for u in units])
    out = out.replace(nl, nl + nl) if False else (header + nl + nl + (nl + nl).join(u[2] for u in units) + nl)
    open(sp, 'w', newline='').write(out)

    sy = os.path.join(REL_CFG, module, 'symbols.txt')
    t = open(sy, newline='').read()
    new, n = re.subn(r'^' + re.escape(sym) + r' = ', 'shared_' + group + ' = ', t, count=1, flags=re.M)
    if n != 1:
        raise SystemExit('symbol not found: %s in %s' % (sym, module))
    open(sy, 'w', newline='').write(new)
    return True


def main():
    group, jf, key = sys.argv[1:4]
    data = json.load(open(jf))
    src = 'REL/shared/%s.cpp' % group
    seen = set()
    done = 0
    for module, sym, addr, size in data[key]['items']:
        if module in seen:
            continue
        seen.add(module)
        if add_unit(module, sym, addr, size, group, src):
            done += 1
    print('%s: %d modules split' % (group, done))


if __name__ == '__main__':
    main()
