#!/usr/bin/env python3

###
# Generates build files for the project.
# This file also includes the project configuration,
# such as compiler flags and the object matching status.
#
# Usage:
#   python3 configure.py
#   ninja
#
# Append --help to see available options.
###

import argparse
import sys
from pathlib import Path
from typing import Any, Dict, List

from tools.project import (
    Object,
    ProjectConfig,
    calculate_progress,
    generate_build,
    is_windows,
)

# Game versions
DEFAULT_VERSION = 0
VERSIONS = [
    "SSQE01",  # 0
]

parser = argparse.ArgumentParser()
parser.add_argument(
    "mode",
    choices=["configure", "progress"],
    default="configure",
    help="script mode (default: configure)",
    nargs="?",
)
parser.add_argument(
    "-v",
    "--version",
    choices=VERSIONS,
    type=str.upper,
    default=VERSIONS[DEFAULT_VERSION],
    help="version to build",
)
parser.add_argument(
    "--build-dir",
    metavar="DIR",
    type=Path,
    default=Path("build"),
    help="base build directory (default: build)",
)
parser.add_argument(
    "--binutils",
    metavar="BINARY",
    type=Path,
    help="path to binutils (optional)",
)
parser.add_argument(
    "--compilers",
    metavar="DIR",
    type=Path,
    help="path to compilers (optional)",
)
parser.add_argument(
    "--map",
    action="store_true",
    help="generate map file(s)",
)
parser.add_argument(
    "--no-asm",
    action="store_true",
    help="don't incorporate .s files from asm directory",
)
parser.add_argument(
    "--debug",
    action="store_true",
    help="build with debug info (non-matching)",
)
if not is_windows():
    parser.add_argument(
        "--wrapper",
        metavar="BINARY",
        type=Path,
        help="path to wibo or wine (optional)",
    )
parser.add_argument(
    "--dtk",
    metavar="BINARY | DIR",
    type=Path,
    help="path to decomp-toolkit binary or source (optional)",
)
parser.add_argument(
    "--sjiswrap",
    metavar="EXE",
    type=Path,
    help="path to sjiswrap.exe (optional)",
)
parser.add_argument(
    "--verbose",
    action="store_true",
    help="print verbose output",
)
parser.add_argument(
    "--non-matching",
    dest="non_matching",
    action="store_true",
    help="builds equivalent (but non-matching) or modded objects",
)
args = parser.parse_args()

config = ProjectConfig()
config.version = str(args.version)
version_num = VERSIONS.index(config.version)

# Apply arguments
config.build_dir = args.build_dir
config.dtk_path = args.dtk
config.binutils_path = args.binutils
config.compilers_path = args.compilers
config.debug = args.debug
config.generate_map = args.map
config.non_matching = args.non_matching
config.sjiswrap_path = args.sjiswrap
if not is_windows():
    config.wrapper = args.wrapper
if args.no_asm:
    config.asm_dir = None

# Tool versions
config.binutils_tag = "2.42-1"
config.compilers_tag = "20231018"
config.dtk_tag = "v0.9.2"
config.sjiswrap_tag = "v1.1.1"
config.wibo_tag = "0.6.11"

# Project
config.config_path = Path("config") / config.version / "config.yml"
config.check_sha_path = Path("config") / config.version / "build.sha1"
config.asflags = [
    "-mgekko",
    "--strip-local-absolute",
    "-I include",
    f"-I build/{config.version}/include",
    f"--defsym version={version_num}",
]
config.ldflags = [
    "-fp hardware",
    "-nodefaults",
    "-listclosure", # Uncomment for Wii linkers
]
# Use for any additional files that should cause a re-configure when modified
config.reconfig_deps = []

# Base flags, common to most GC/Wii games.
# Generally leave untouched, with overrides added below.
cflags_base = [
    "-nodefaults",
    "-proc gekko",
    "-align powerpc",
    "-enum int",
    "-fp hardware",
    "-Cpp_exceptions off",
    # "-W all",
    "-O4,p",
    "-inline auto",
    '-pragma "cats off"',
    '-pragma "warn_notinlined off"',
    "-maxerrors 1",
    "-nosyspath",
    "-RTTI off",
    "-fp_contract on",
    "-str reuse",
    "-enc SJIS",  # For Wii compilers, replace with `-enc SJIS`
    "-i include",
    f"-i build/{config.version}/include",
    f"-DVERSION={version_num}",
]

# Debug flags
if config.debug:
    cflags_base.extend(["-sym on", "-DDEBUG=1"])
else:
    cflags_base.append("-DNDEBUG=1")

# Metrowerks library flags
cflags_runtime = [
    *cflags_base,
    "-use_lmw_stmw on",
    "-str reuse,pool,readonly",
    "-gccinc",
    "-common off",
    "-inline auto",
]

# Game flags
cflags_game = [
    *cflags_base,
    "-O4,p",
    "-char unsigned",
    "-fp_contract off",
]

# REL flags
cflags_rel = [
    *cflags_game,
    "-sdata 0",
    "-sdata2 0",
    "-pool off",
    "-func_align 16"
]

# Some REL objects (e.g. Introduction) were built with pooled strings
cflags_rel_strpool = [*cflags_rel, "-str pool"]


config.linker_version = "GC/3.0a5.2"
config.rel_strip_partial = False
config.rel_empty_file = "REL/empty.c"

# Helper function for Dolphin libraries
def DolphinLib(lib_name: str, objects: List[Object]) -> Dict[str, Any]:
    return {
        "lib": lib_name,
        "mw_version": "GC/1.2.5n",
        "cflags": cflags_base,
        "host": False,
        "objects": objects,
    }


# Helper function for REL script objects
def Rel(lib_name: str, objects: List[Object]) -> Dict[str, Any]:
    return {
        "lib": lib_name,
        "mw_version": "GC/3.0a5.2",
        "cflags": cflags_rel,
        "host": True,
        "objects": objects,
    }


Matching = True                   # Object matches and should be linked
NonMatching = False               # Object does not match and should not be linked
Equivalent = config.non_matching  # Object should be linked when configured with --non-matching

config.warn_missing_config = True
config.warn_missing_source = False
config.libs = [
    {
        "lib": "Runtime.PPCEABI.H",
        "mw_version": config.linker_version,
        "cflags": cflags_runtime,
        "host": False,
        "objects": [
            Object(Matching, "Runtime.PPCEABI.H/global_destructor_chain.c"),
            Object(Matching, "Runtime.PPCEABI.H/__init_cpp_exceptions.cpp"),
        ],
    },
    {
        "lib": "Game",
        "mw_version": config.linker_version,
        "cflags": cflags_game,
        "host": False,
        "objects": [
            Object(Matching, "Game/test_last_elem.c"),
            Object(Matching, "Game/test_getter.c"),
        ],
    },
    {
        "lib": "REL",
        "mw_version": config.linker_version,
        "cflags": cflags_rel,
        "host": False,
        "objects": [
            # Object(Matching, "REL/empty.c"),  # Must be marked as matching
            Object(NonMatching, "REL/Introduction/Introduction.c", cflags=cflags_rel_strpool),
            Object(NonMatching, "REL/strap/strap_main.cpp"),
            Object(NonMatching, "REL/strap/strap_base.cpp"),
            Object(NonMatching, "REL/global_destructor_chain.c"),
            Object(Matching, "REL/shared/zero3.cpp"),
            Object(Matching, "REL/shared/zero1.cpp"),
            Object(Matching, "REL/shared/g_04f57eab.cpp"),
            Object(Matching, "REL/shared/g_07757e4c.cpp"),
            Object(Matching, "REL/shared/g_07d4877d.cpp"),
            Object(Matching, "REL/shared/g_07e0b8c9.cpp"),
            Object(Matching, "REL/shared/g_083f6c5e.cpp"),
            Object(Matching, "REL/shared/g_0e2f7d38.cpp"),
            Object(Matching, "REL/shared/g_102d78cb.cpp"),
            Object(Matching, "REL/shared/g_11eba2f4.cpp"),
            Object(Matching, "REL/shared/g_1292a20d.cpp"),
            Object(Matching, "REL/shared/g_16b2cf36.cpp"),
            Object(Matching, "REL/shared/g_1dc14d27.cpp"),
            Object(Matching, "REL/shared/g_1e01b9b4.cpp"),
            Object(Matching, "REL/shared/g_279e4f7d.cpp"),
            Object(Matching, "REL/shared/g_28836af6.cpp"),
            Object(Matching, "REL/shared/g_2b81419d.cpp"),
            Object(Matching, "REL/shared/g_2fab7d6a.cpp"),
            Object(Matching, "REL/shared/g_34fb7e50.cpp"),
            Object(Matching, "REL/shared/g_38cb0e9b.cpp"),
            Object(Matching, "REL/shared/g_3c6dca95.cpp"),
            Object(Matching, "REL/shared/g_5702c3ca.cpp"),
            Object(Matching, "REL/shared/g_5fc49bca.cpp"),
            Object(Matching, "REL/shared/g_6fffdefd.cpp"),
            Object(Matching, "REL/shared/g_8f243731.cpp"),
            Object(Matching, "REL/shared/g_a1ad74a1.cpp"),
            Object(Matching, "REL/shared/g_a57e5b0b.cpp"),
            Object(Matching, "REL/shared/g_a840b38e.cpp"),
            Object(Matching, "REL/shared/g_a84a6503.cpp"),
            Object(Matching, "REL/shared/g_b3b5c172.cpp"),
            Object(Matching, "REL/shared/g_b7d21b28.cpp"),
            Object(Matching, "REL/shared/g_c52f4b03.cpp"),
            Object(Matching, "REL/shared/g_c77ac150.cpp"),
            Object(Matching, "REL/shared/g_ce9b1a7d.cpp"),
            Object(Matching, "REL/shared/g_e0e78600.cpp"),
            Object(Matching, "REL/shared/g_e1422d63.cpp"),
            Object(Matching, "REL/shared/g_e81a5b7e.cpp"),
            Object(Matching, "REL/shared/g_f01b8095.cpp"),
            Object(Matching, "REL/shared/g_fbb1947c.cpp"),
            Object(Matching, "REL/shared/g_fddeff6a.cpp"),
            Object(Matching, "REL/shared/g_e7bf8439.cpp"),
            Object(Matching, "REL/shared/g_a2dd42cc.cpp"),
            Object(Matching, "REL/shared/g_75dbd570.cpp"),
            Object(Matching, "REL/shared/g_22a07450.cpp"),
            Object(Matching, "REL/shared/g_042c20ba.cpp"),
            Object(Matching, "REL/shared/g_d51a2006.cpp"),
            Object(Matching, "REL/shared/g_3d33f69b.cpp"),
            Object(Matching, "REL/shared/g_5236930c.cpp"),
            Object(Matching, "REL/shared/g_bdcee978.cpp"),
            Object(Matching, "REL/shared/g_19ec8442.cpp"),
            Object(Matching, "REL/shared/g_42c3756b.cpp"),
            Object(Matching, "REL/shared/g_7875277f.cpp"),
            Object(Matching, "REL/shared/g_7a70034e.cpp"),
            Object(Matching, "REL/shared/g_c1ab5c7a.cpp"),
            Object(Matching, "REL/shared/g_ea257b7c.cpp"),
            Object(Matching, "REL/shared/g_cadf1cd8.cpp"),
            Object(Matching, "REL/shared/g_0a501a14.cpp"),
            Object(Matching, "REL/shared/g_e6faee76.cpp"),
            Object(Matching, "REL/shared/g_377b72b0.cpp"),
            Object(Matching, "REL/shared/g_03f0f2ae.cpp"),
            Object(Matching, "REL/shared/g_594a08e0.cpp"),
            Object(Matching, "REL/shared/g_01f27c84.cpp"),
            Object(Matching, "REL/shared/g_11e271f9.cpp"),
            Object(Matching, "REL/shared/g_16f8c90a.cpp"),
            Object(Matching, "REL/shared/g_17a45aea.cpp"),
            Object(Matching, "REL/shared/g_293055ae.cpp"),
            Object(Matching, "REL/shared/g_2a575f22.cpp"),
            Object(Matching, "REL/shared/g_2b34b325.cpp"),
            Object(Matching, "REL/shared/g_2d0d7b71.cpp"),
            Object(Matching, "REL/shared/g_3b2d403f.cpp"),
            Object(Matching, "REL/shared/g_3b5a3f0e.cpp"),
            Object(Matching, "REL/shared/g_406a62da.cpp"),
            Object(Matching, "REL/shared/g_565758fc.cpp"),
            Object(Matching, "REL/shared/g_5ccc98af.cpp"),
            Object(Matching, "REL/shared/g_63894e59.cpp"),
            Object(Matching, "REL/shared/g_671f8bfd.cpp"),
            Object(Matching, "REL/shared/g_6c3db20a.cpp"),
            Object(Matching, "REL/shared/g_7543d211.cpp"),
            Object(Matching, "REL/shared/g_86ca03d7.cpp"),
            Object(Matching, "REL/shared/g_8afe8ef7.cpp"),
            Object(Matching, "REL/shared/g_8df7e362.cpp"),
            Object(Matching, "REL/shared/g_9b37621c.cpp"),
            Object(Matching, "REL/shared/g_9f80cc13.cpp"),
            Object(Matching, "REL/shared/g_a02e02d4.cpp"),
            Object(Matching, "REL/shared/g_a80cfa61.cpp"),
            Object(Matching, "REL/shared/g_a94ae5ef.cpp"),
            Object(Matching, "REL/shared/g_aa6fa5e5.cpp"),
            Object(Matching, "REL/shared/g_ac27d302.cpp"),
            Object(Matching, "REL/shared/g_b12cfaea.cpp"),
            Object(Matching, "REL/shared/g_be8174a3.cpp"),
            Object(Matching, "REL/shared/g_c821974a.cpp"),
            Object(Matching, "REL/shared/g_ca3000b3.cpp"),
            Object(Matching, "REL/shared/g_cc9431c0.cpp"),
            Object(Matching, "REL/shared/g_d56e9ead.cpp"),
            Object(Matching, "REL/shared/g_d81af600.cpp"),
            Object(Matching, "REL/shared/g_d97f9cae.cpp"),
            Object(Matching, "REL/shared/g_e128b414.cpp"),
            Object(Matching, "REL/shared/g_e4f40a20.cpp"),
            Object(Matching, "REL/shared/g_ebf52cfa.cpp"),
            Object(Matching, "REL/shared/g_f22e61cd.cpp"),
            Object(Matching, "REL/shared/g_f05dcbd3.cpp"),
            Object(Matching, "REL/shared/g_ef139bc0.cpp"),
            Object(Matching, "REL/shared/g_fcdc4bbc.cpp"),
            Object(Matching, "REL/shared/g_cb89c715.cpp"),
            Object(Matching, "REL/shared/g_ba7a6941.cpp"),
            Object(Matching, "REL/shared/g_23fc310e.cpp"),
            Object(Matching, "REL/shared/g_1087bded.cpp"),
            Object(Matching, "REL/shared/g_af1cfa4f.cpp"),
            Object(Matching, "REL/shared/g_13ac7a27.cpp"),
            Object(Matching, "REL/shared/g_4314a11d.cpp"),
            Object(Matching, "REL/shared/g_807a1934.cpp"),
            Object(Matching, "REL/shared/g_98a2ed67.cpp"),
            Object(Matching, "REL/shared/g_c9686c3b.cpp"),
            Object(Matching, "REL/shared/g_83da6437.cpp"),
            Object(Matching, "REL/shared/g_584ef421.cpp"),
            Object(Matching, "REL/shared/g_16623138.cpp"),
            Object(Matching, "REL/shared/g_99034325.cpp"),
            Object(Matching, "REL/shared/g_9d1b87ed.cpp"),
            Object(Matching, "REL/shared/g_2d538699.cpp"),
            Object(Matching, "REL/shared/g_71c0e71f.cpp"),
            Object(Matching, "REL/shared/g_2b726490.cpp"),
            Object(Matching, "REL/shared/g_b640e006.cpp"),
            Object(Matching, "REL/shared/g_d8067967.cpp"),
            Object(Matching, "REL/shared/g_049107ea.cpp"),
            Object(Matching, "REL/shared/g_21cf1dfc.cpp"),
            Object(Matching, "REL/shared/g_627244bb.cpp"),
            Object(Matching, "REL/shared/g_1df1645b.cpp"),
            Object(Matching, "REL/shared/g_fd2109c2.cpp"),
            Object(Matching, "REL/shared/g_fec66df8.cpp"),
            Object(Matching, "REL/shared/g_56f7e213.cpp"),
            Object(Matching, "REL/shared/g_1f9b5725.cpp"),
            Object(Matching, "REL/shared/g_7d81d4ca.cpp"),
            Object(Matching, "REL/shared/g_f3a4f2c4.cpp"),
            Object(Matching, "REL/shared/g_b8ceb19a.cpp"),
            Object(Matching, "REL/shared/g_2e618b25.cpp"),
            Object(Matching, "REL/shared/g_8cb08d35.cpp"),
            Object(Matching, "REL/shared/g_f8a5d806.cpp"),
            Object(Matching, "REL/shared/g_22e700c0.cpp"),
            Object(Matching, "REL/shared/g_6a879dc5.cpp"),
            Object(Matching, "REL/shared/g_89c5a19c.cpp"),
            Object(Matching, "REL/shared/g_dea68e37.cpp"),
            Object(Matching, "REL/shared/g_589a5fc2.cpp"),
            Object(Matching, "REL/shared/g_794e5e1e.cpp"),
            Object(Matching, "REL/shared/g_d19bf2ca.cpp"),
            Object(Matching, "REL/shared/g_3fe2a69f.cpp"),
            Object(Matching, "REL/shared/g_a331a900.cpp"),
            Object(Matching, "REL/shared/g_ebf86107.cpp"),
            Object(Matching, "REL/shared/g_504a8a1e.cpp"),
            Object(Matching, "REL/shared/g_d34615b2.cpp"),
            Object(Matching, "REL/shared/g_c5dd114a.cpp"),
            Object(Matching, "REL/shared/g_b4a2d221.cpp"),
            Object(Matching, "REL/shared/g_b03b2d34.cpp"),
            Object(Matching, "REL/shared/g_24b87a71.cpp"),
            Object(Matching, "REL/shared/g_b722b7d7.cpp"),
            Object(Matching, "REL/shared/g_4d821a34.cpp"),
            Object(Matching, "REL/shared/g_c2dc4201.cpp"),
            Object(Matching, "REL/shared/g_390976de.cpp"),
            Object(Matching, "REL/shared/g_86b330a1.cpp"),
            Object(Matching, "REL/shared/g_7076ed87.cpp"),
            Object(Matching, "REL/shared/g_6bd46a27.cpp"),
            Object(Matching, "REL/shared/g_48cd6dcc.cpp"),
            Object(Matching, "REL/shared/g_bd738156.cpp"),
            Object(Matching, "REL/shared/g_16f8004f.cpp"),
            Object(Matching, "REL/shared/g_e54d7280.cpp"),
            Object(Matching, "REL/shared/g_1993e0fc.cpp"),
            Object(Matching, "REL/shared/g_1d958c68.cpp"),
            Object(NonMatching, "REL/shared/g_d950a34b.cpp"),
            Object(Matching, "REL/shared/g_1eb63bea.cpp"),
            Object(Matching, "REL/shared/g_4e08146a.cpp"),
            Object(Matching, "REL/shared/g_f9359739.cpp"),
            Object(Matching, "REL/shared/g_844b747a.cpp"),
            Object(Matching, "REL/shared/g_059e7501.cpp"),
            Object(Matching, "REL/shared/g_b3cdb0bd.cpp"),
            Object(Matching, "REL/shared/g_f29714d4.cpp"),
            Object(Matching, "REL/shared/g_0d4996b0.cpp"),
            Object(Matching, "REL/shared/g_ce964089.cpp"),
            Object(Matching, "REL/shared/g_563a1633.cpp"),
            Object(Matching, "REL/shared/g_fc7bf8eb.cpp"),
            Object(Matching, "REL/shared/g_03663ab7.cpp"),
            Object(Matching, "REL/shared/g_b18e4b3c.cpp"),
            Object(Matching, "REL/shared/g_ceafd3dc.cpp"),
            Object(Matching, "REL/shared/g_495a1f5a.cpp"),
            Object(Matching, "REL/shared/g_e98f68b6.cpp"),
            Object(Matching, "REL/shared/g_66a7638c.cpp"),
            Object(Matching, "REL/shared/g_5047ec7a.cpp"),
            Object(Matching, "REL/shared/g_93e02619.cpp"),
            Object(Matching, "REL/shared/g_13993621.cpp"),
            Object(Matching, "REL/shared/g_ef24cb79.cpp"),
            Object(Matching, "REL/shared/g_d4900f40.cpp"),
            Object(Matching, "REL/shared/g_3615e78a.cpp"),
            Object(Matching, "REL/shared/g_fcdef631.cpp"),
            Object(Matching, "REL/shared/g_1ca0266a.cpp"),
            Object(Matching, "REL/shared/g_94c187f0.cpp"),
            Object(Matching, "REL/shared/g_d571a091.cpp"),
            Object(Matching, "REL/shared/g_d3cd0c51.cpp"),
            Object(Matching, "REL/shared/g_2b773072.cpp"),
            Object(Matching, "REL/shared/g_e214da4e.cpp"),
            Object(Matching, "REL/shared/g_979be3e8.cpp"),
            Object(Matching, "REL/shared/g_11502c38.cpp"),
            Object(Matching, "REL/shared/g_bcb2bd13.cpp"),
            Object(NonMatching, "REL/shared/g_541f0a5f.cpp"),
            Object(Matching, "REL/shared/g_dda170d1.cpp"),
            Object(Matching, "REL/shared/g_681da66f.cpp"),
            Object(Matching, "REL/shared/g_7b05cd3b.cpp"),
            Object(Matching, "REL/shared/g_852e1a82.cpp"),
            Object(Matching, "REL/shared/g_d8a5d800.cpp"),
            Object(Matching, "REL/shared/g_5897f13e.cpp"),
            Object(Matching, "REL/shared/g_aa0516c2.cpp"),
            Object(Matching, "REL/shared/g_5659a363.cpp"),
            Object(Matching, "REL/shared/g_996f4301.cpp"),
            Object(Matching, "REL/shared/g_0c1cf328.cpp"),
            Object(Matching, "REL/shared/g_70063773.cpp"),
            Object(Matching, "REL/shared/g_01f57131.cpp"),
            Object(Matching, "REL/shared/g_40e3f266.cpp"),
            Object(Matching, "REL/shared/g_ffbd7fc5.cpp"),
            Object(Matching, "REL/shared/g_d24b02fa.cpp"),
            Object(Matching, "REL/shared/g_cdf3910e.cpp"),
            Object(Matching, "REL/shared/g_a8973041.cpp"),
            Object(NonMatching, "REL/shared/g_591af319.cpp"),
            Object(Matching, "REL/shared/g_473b1e35.cpp"),
            Object(Matching, "REL/shared/g_44eac84b.cpp"),
            Object(Matching, "REL/shared/g_bdfb4694.cpp"),
            Object(Matching, "REL/shared/g_d5181cf5.cpp"),
            Object(Matching, "REL/shared/g_6f937d49.cpp"),
            Object(Matching, "REL/shared/g_75c7b5bf.cpp"),
            Object(Matching, "REL/shared/g_25c67f26.cpp"),
            Object(Matching, "REL/shared/g_3d91970c.cpp"),
            Object(Matching, "REL/shared/g_df44fc6d.cpp"),
            Object(Matching, "REL/shared/g_efbfd0c0.cpp"),
            Object(NonMatching, "REL/shared/g_74390f8c.cpp"),
            Object(NonMatching, "REL/shared/g_754fe1b3.cpp"),
            Object(Matching, "REL/shared/g_fb9fba3a.cpp"),
            Object(NonMatching, "REL/shared/g_8a12be01.cpp"),
            Object(NonMatching, "REL/shared/g_fd0b328f.cpp"),
            Object(Matching, "REL/shared/g_aa471703.cpp"),
            Object(NonMatching, "REL/shared/g_d5328f45.cpp"),
            Object(NonMatching, "REL/shared/g_fcc70827.cpp"),
            Object(Matching, "REL/shared/g_084f8da9.cpp"),
            Object(NonMatching, "REL/shared/g_496e983a.cpp"),
            Object(Matching, "REL/shared/g_1b9dec27.cpp"),
            Object(Matching, "REL/shared/g_b8234db0.cpp"),
            Object(Matching, "REL/shared/g_2c3cba6d.cpp"),
            Object(Matching, "REL/shared/g_0c2e890e.cpp"),
            Object(Matching, "REL/shared/g_657ac52d.cpp"),
            Object(Matching, "REL/shared/g_19445f93.cpp"),
            Object(Matching, "REL/shared/g_b96a24cd.cpp"),
            Object(Matching, "REL/shared/g_a7eaf92b.cpp"),
            Object(Matching, "REL/shared/g_02401e1d.cpp"),
            Object(Matching, "REL/shared/g_07a35f99.cpp"),
            Object(Matching, "REL/shared/g_f9077e23.cpp"),
            Object(Matching, "REL/shared/g_47c182d7.cpp"),
            Object(Matching, "REL/shared/g_b1a4f58b.cpp"),
            Object(Matching, "REL/shared/g_051f6eeb.cpp"),
            Object(Matching, "REL/shared/g_2fc41df9.cpp"),
            Object(Matching, "REL/shared/g_994c077a.cpp"),
            Object(Matching, "REL/shared/g_72252398.cpp"),
            Object(Matching, "REL/shared/g_4781a7b4.cpp"),
            Object(Matching, "REL/shared/g_5dc834d0.cpp"),
            Object(Matching, "REL/shared/g_3c4a6199.cpp"),
            Object(NonMatching, "REL/shared/g_62ae1061.cpp"),
            Object(NonMatching, "REL/shared/g_e52545a9.cpp"),
            Object(NonMatching, "REL/shared/g_d1c5d877.cpp"),
            Object(Matching, "REL/shared/g_9dfc75be.cpp"),
            Object(Matching, "REL/shared/g_39ffbb84.cpp"),
            Object(Matching, "REL/shared/g_540a52a9.cpp"),
            Object(Matching, "REL/shared/g_6c4fdaac.cpp"),
            Object(NonMatching, "REL/shared/g_54a9d7f1.cpp"),
            Object(NonMatching, "REL/shared/g_f85c67f8.cpp"),
            Object(Matching, "REL/shared/g_238591b6.cpp"),
            Object(Matching, "REL/shared/g_ac9db33d.cpp"),
            Object(Matching, "REL/shared/g_1aaf35ad.cpp"),
            Object(Matching, "REL/shared/g_d7ef838a.cpp"),
            Object(Matching, "REL/shared/g_31f859ef.cpp"),
            Object(Matching, "REL/shared/g_b19014e2.cpp"),
            Object(Matching, "REL/shared/g_aa3db2a9.cpp"),
            Object(Matching, "REL/shared/g_f1895b2a.cpp"),
            Object(Matching, "REL/shared/g_e8c06196.cpp"),
            Object(Matching, "REL/shared/g_3fbfb018.cpp"),
            Object(Matching, "REL/shared/g_69a65eca.cpp"),
            Object(Matching, "REL/shared/g_81cb76c8.cpp"),
            Object(Matching, "REL/shared/g_d95c1e8f.cpp"),
            Object(Matching, "REL/shared/g_3cde767d.cpp"),
            Object(Matching, "REL/shared/g_5d8179ee.cpp"),
            Object(NonMatching, "REL/shared/g_0a05fc45.cpp"),
            Object(NonMatching, "REL/shared/g_c68a324e.cpp"),
            Object(Matching, "REL/shared/g_e06888f4.cpp"),
            Object(NonMatching, "REL/shared/g_57936626.cpp"),
            Object(Matching, "REL/shared/g_fc9c1319.cpp"),
            Object(Matching, "REL/shared/g_19422d87.cpp"),
            Object(Matching, "REL/shared/g_f70b5267.cpp"),
            Object(NonMatching, "REL/shared/g_50f59e2c.cpp"),
            Object(Matching, "REL/shared/g_a7758c89.cpp"),
            Object(Matching, "REL/shared/g_e6e20ed2.cpp"),
            Object(Matching, "REL/shared/g_37973916.cpp"),
            Object(Matching, "REL/shared/g_b16f939d.cpp"),
            Object(Matching, "REL/shared/g_5271f895.cpp"),
            Object(Matching, "REL/shared/g_bc670686.cpp"),
            Object(Matching, "REL/shared/g_627d51a5.cpp"),
            Object(Matching, "REL/shared/g_0690c1d2.cpp"),
            Object(Matching, "REL/shared/g_c42efecb.cpp"),
            Object(Matching, "REL/shared/g_5dbd6fb9.cpp"),
            Object(Matching, "REL/shared/g_fd9d935e.cpp"),
            Object(Matching, "REL/shared/g_93ba57d6.cpp"),
            Object(Matching, "REL/shared/g_ce90315b.cpp"),
            Object(Matching, "REL/shared/g_e3c5293e.cpp"),
            Object(Matching, "REL/shared/g_7396c9af.cpp"),
            Object(Matching, "REL/shared/g_ea440d20.cpp"),
            Object(Matching, "REL/shared/g_c28ef4b7.cpp"),
            Object(Matching, "REL/shared/g_ee0cc563.cpp"),
            Object(Matching, "REL/shared/g_d473868d.cpp"),
            Object(Matching, "REL/shared/g_76e25039.cpp"),
            Object(Matching, "REL/shared/g_1689cde3.cpp"),
            Object(Matching, "REL/shared/g_a15a3cb2.cpp"),
            Object(Matching, "REL/shared/g_68684f68.cpp"),
            Object(Matching, "REL/shared/g_c8083e32.cpp"),
            Object(Matching, "REL/shared/g_d6475ed7.cpp"),
            Object(Matching, "REL/shared/g_0fa37654.cpp"),
            Object(Matching, "REL/shared/g_e0d7926f.cpp"),
            Object(Matching, "REL/shared/g_9ab287e8.cpp"),
            Object(Matching, "REL/shared/g_7dd4f0e7.cpp"),
            Object(Matching, "REL/shared/g_606c8d19.cpp"),
            Object(Matching, "REL/shared/g_48b778da.cpp"),
            Object(Matching, "REL/shared/g_a2ec4680.cpp"),
            Object(Matching, "REL/shared/g_6a124713.cpp"),
            Object(Matching, "REL/shared/g_c441db34.cpp"),
            Object(Matching, "REL/shared/g_f11e7fb3.cpp"),
            Object(Matching, "REL/shared/g_bdfb3b9f.cpp"),
            Object(Matching, "REL/shared/g_bee893b6.cpp"),
            Object(Matching, "REL/shared/g_49c141e5.cpp"),
            Object(Matching, "REL/shared/g_bd5023e9.cpp"),
            Object(Matching, "REL/shared/g_b1975310.cpp"),
            Object(Matching, "REL/shared/g_88ef1243.cpp"),
            Object(Matching, "REL/shared/g_f01bcde1.cpp"),
            Object(Matching, "REL/shared/g_0b252612.cpp"),
            Object(Matching, "REL/shared/g_1094066b.cpp"),
            Object(Matching, "REL/shared/g_a46aff92.cpp"),
            Object(Matching, "REL/shared/g_4d5518fb.cpp"),
            Object(NonMatching, "REL/shared/g_2a994496.cpp"),
            Object(Matching, "REL/shared/g_ff0ea99e.cpp"),
            Object(Matching, "REL/shared/g_be9c79f7.cpp"),
            Object(Matching, "REL/shared/g_337fd4e0.cpp"),
            Object(Matching, "REL/shared/g_8ce78503.cpp"),
            Object(Matching, "REL/shared/g_6566c143.cpp"),
            Object(Matching, "REL/shared/g_2b9ea4c2.cpp"),
            Object(Matching, "REL/shared/g_bc2bfeb0.cpp"),
            Object(Matching, "REL/shared/g_9cb1aa21.cpp"),
            Object(Matching, "REL/shared/g_073e8e41.cpp"),
            Object(Matching, "REL/shared/g_d7cb249d.cpp"),
            Object(Matching, "REL/shared/g_1a9847c6.cpp"),
            Object(NonMatching, "REL/shared/g_dd67ff80.cpp"),
            Object(Matching, "REL/shared/g_526fe2bf.cpp"),
            Object(Matching, "REL/shared/g_08918d04.cpp"),
            Object(Matching, "REL/shared/g_1c8acefe.cpp"),
            Object(Matching, "REL/shared/g_0a315e44.cpp"),
            Object(Matching, "REL/shared/g_ed5b9fcb.cpp"),
            Object(Matching, "REL/shared/g_1f818a75.cpp"),
            Object(Matching, "REL/shared/g_4ec41020.cpp"),
            Object(Matching, "REL/shared/g_5d6d3818.cpp"),
            Object(Matching, "REL/shared/g_3f8674bc.cpp"),
            Object(NonMatching, "REL/shared/g_71e4e6b1.cpp"),
            Object(Matching, "REL/shared/g_4e0b62d3.cpp"),
            Object(Matching, "REL/shared/g_44b02eb2.cpp"),
            Object(Matching, "REL/shared/g_e33dff9d.cpp"),
            Object(Matching, "REL/shared/g_f0882af3.cpp"),
            Object(Matching, "REL/shared/g_76e11079.cpp"),
            Object(Matching, "REL/shared/g_6c6c8c8f.cpp"),
            Object(Matching, "REL/shared/g_52b651ba.cpp"),
            Object(Matching, "REL/shared/g_6ee7942b.cpp"),
            Object(Matching, "REL/shared/g_a7e478d5.cpp"),
            Object(Matching, "REL/shared/g_a91cb0f2.cpp"),
            Object(Matching, "REL/shared/g_40f6f4db.cpp"),
            Object(Matching, "REL/shared/g_75e81303.cpp"),
            Object(Matching, "REL/shared/g_3951b4e8.cpp"),
            Object(Matching, "REL/shared/g_3d46be7d.cpp"),
            Object(Matching, "REL/shared/g_0ec4bd51.cpp"),
            Object(Matching, "REL/shared/g_72c227e6.cpp"),
            Object(NonMatching, "REL/shared/g_22803c57.cpp"),
            Object(Matching, "REL/shared/g_0ddf656c.cpp"),
            Object(Matching, "REL/shared/g_43b503da.cpp"),
            Object(Matching, "REL/shared/g_9ee354d6.cpp"),
            Object(Matching, "REL/shared/g_b841497c.cpp"),
            Object(Matching, "REL/shared/g_19121d07.cpp"),
            Object(Matching, "REL/shared/g_2a66679b.cpp"),
            Object(Matching, "REL/shared/g_b49efece.cpp"),
            Object(Matching, "REL/shared/g_c9b7496b.cpp"),
            Object(Matching, "REL/shared/g_4f257b54.cpp"),
            Object(Matching, "REL/shared/g_2c2450b8.cpp"),
            Object(Matching, "REL/shared/g_afca3b89.cpp"),
            Object(Matching, "REL/shared/g_621889d0.cpp"),
            Object(Matching, "REL/shared/g_e27cabd3.cpp"),
            Object(Matching, "REL/shared/g_1ed87e2d.cpp"),
            Object(Matching, "REL/shared/g_150e3fd1.cpp"),
            Object(Matching, "REL/shared/g_1d7a99d6.cpp"),
            Object(Matching, "REL/shared/g_8f5d335f.cpp"),
            Object(Matching, "REL/shared/g_8373b269.cpp"),
            Object(NonMatching, "REL/shared/g_78119963.cpp"),
            Object(Matching, "REL/shared/g_4fc48305.cpp"),
            Object(Matching, "REL/shared/g_f6bdecd7.cpp"),
            Object(Matching, "REL/shared/g_6682a869.cpp"),
            Object(Matching, "REL/shared/g_9ef082af.cpp"),
            Object(Matching, "REL/shared/g_478fec3d.cpp"),
            Object(Matching, "REL/shared/g_6d4e649d.cpp"),
            Object(Matching, "REL/shared/g_04f6cca6.cpp"),
            Object(Matching, "REL/shared/g_8365ee7b.cpp"),
            Object(Matching, "REL/shared/g_7b1c71df.cpp"),
        ],
    },
    {
        "lib": "board",
        "mw_version": config.linker_version,
        "cflags": cflags_rel,
        "host": False,
        "objects": [
            # Object(NonMatching, "REL/board/board_process.cpp"),
            # Object(NonMatching, "REL/board/game_object.cpp"),
        ],
    },
]

if args.mode == "configure":
    # Write build.ninja and objdiff.json
    generate_build(config)
elif args.mode == "progress":
    # Print progress and write progress.json
    config.progress_each_module = args.verbose
    calculate_progress(config)
else:
    sys.exit("Unknown mode: " + args.mode)
