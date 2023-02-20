import os
import subprocess
import sys
from pathlib import Path


def err(message: str):
    print(f"Error: {message}")
    sys.exit(1)


def dep(path, name):
    path = Path(path)
    if not os.path.exists(path):
        err(f"{name} not found!")
    return path


REGIONS = ["PAL", "USA", "JPN", "TWN", "KOR"]

MWCCEPPC = dep("deps/CodeWarrior/mwcceppc.exe", "CodeWarrior compiler")
KAMEK = dep("deps/Kamek/Kamek.exe", "Kamek linker")
SYMBOLS = dep("symbols", "Symbols folder")


def build(region: str):
    compile_cmd = f"{MWCCEPPC} -c -Cpp_exceptions off -nodefaults -proc gekko -fp hard -lang=c++ -O4,s -inline on " \
                  f"-rtti off -sdata 0 -sdata2 0 -align powerpc -func_align 4 -str pool -enum int -DGEKKO " \
                  f"-i include -I- -i loader -D{region} loader/loader.cpp -o loader/loader.o"

    kamek_cmd = f"{KAMEK} loader/loader.o -static=0x80001800 -externals={SYMBOLS}/{region}.txt " \
                f"-output-riiv=loader/riivo_{region}.xml"

    print(f"Building target {region}!")

    if os.path.exists(f"dols/{region}.dol"):
        kamek_cmd += f" -input-dol=dols/{region}.dol -output-dol=loader/{region}.dol"

    if subprocess.call(compile_cmd, shell=True) != 0:
        err("Compiling failed.")
    if subprocess.call(kamek_cmd, shell=True) != 0:
        err("Linking failed.")

    print("Done!")


if __name__ == '__main__':
    if len(sys.argv) < 2:
        print("Did not specify a target region, building all targets!")

        for region in REGIONS:
            build(region)
    else:
        region = sys.argv[1]

        if region not in REGIONS:
            err(f"Invalid build target found: {region}")

        build(region)
