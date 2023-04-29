import os
import shutil
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


def prepare_bin():
    if os.path.exists("bin"):
        shutil.rmtree("bin")
    os.makedirs("bin")


REGIONS = ["PAL", "USA", "JPN", "TWN", "KOR"]
LETTERS = ['P', 'E', 'J', 'W', 'K']

MWCCEPPC = dep("deps/CodeWarrior/mwcceppc.exe", "CodeWarrior compiler")
KAMEK = dep("deps/Kamek/Kamek.exe", "Kamek linker")
SYMBOLS = dep("symbols", "Symbols folder")

def getregionletter(region: str):
    for i in range(0, len(REGIONS)):
        reg = REGIONS[i]
        if region == reg:
            return LETTERS[i]

def build(region: str):
    compile_cmd = f"{MWCCEPPC} -c -Cpp_exceptions off -nodefaults -proc gekko -fp hard -lang=c++ -O4,s -inline on " \
                  f"-rtti off -sdata 0 -sdata2 0 -align powerpc -func_align 4 -str pool -enum int -DGEKKO " \
                  f"-i include -I- -i loader -D{region} loader/loader.cpp -o loader/loader.o"

    kamek_cmd = f"{KAMEK} loader/loader.o -static=0x80001800 -externals={SYMBOLS}/{region}.txt " \
                f"-output-riiv=loader/riivo_{region}.xml " \
                f"-output-kamek=loader/Loader{getregionletter(region)}.bin" \
                f"-output-dolphin=loader/Dolphin{getregionletter(region)}.ini"

    print(f"Building target {region}!")


    if subprocess.call(compile_cmd, shell=True) != 0:
        err("Compiling failed.")

    if subprocess.call(kamek_cmd, shell=True) != 0:
        err("Linking failed.")

    if os.path.exists(f"deps/{region}.dol"):
        kamek_cmd = f"{KAMEK} loader/loader.o -static=0x80001800 -externals={SYMBOLS}/{region}.txt" \
        f" -input-dol=deps/{region}.dol -output-dol=bin/{region}.dol"
        if subprocess.call(kamek_cmd, shell=True) != 0:
            err("Linking failed.")

    print("Done!")


if __name__ == '__main__':
    if len(sys.argv) < 2:
        print("Did not specify a target region, building all targets!")

        prepare_bin()

        for region in REGIONS:
            build(region)

    else:
        region = sys.argv[1]

        if region not in REGIONS:
            err(f"Invalid build target found: {region}")

        prepare_bin()
        build(region)
