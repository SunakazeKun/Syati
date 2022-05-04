# All target regions
REGIONS = ["PAL", "USA", "JAP", "TWN", "KOR"]

# First, we define the offsets that we have to apply to some symbols to get the proper addresses in the other regions.
# All of these offsets are relative to the symbol's location in the PAL map. For PAL, USA and JAP, all the code lines up
# 1:1, however, the data and static data addresses are different due to the ErrorMessageArchive having a different size
# in all regions.
# Each entry is a pair consisting of the starting PAL address to apply an offset to and the offset to apply to all the
# symbol addresses.
USA_OFFSETS = [
    (0x806599A0, -0x5700)  # After ErrorMessageArchive
]

JAP_OFFSETS = [
    (0x806599A0, -0x5F20),  # After ErrorMessageArchive
    (0x8072DD80, -0x5F40)  # BSS Start
]

TWN_OFFSETS = [
    # .text
    (0x8047B110, 0x10),  # initTextBoxPane__14LayoutCoreUtilFPQ34nw4r3lyt7TextBoxPCcUl
    (0x80492340, 0x50),  # appear__9StaffRollFv
    (0x80494AA0, 0x70),
    (0x804BD390, 0x90),  # getLanguageNum__2MRFv
    (0x8054B440, 0x100),
    (0x805E7BE0, 0x110),  # wpad.a
    (0x805E8140, 0x120),  # wpad.a
    (0x805E8DF0, 0x1B0),  # wpad.a
    (0x805EA130, 0x1D0),  # WPADStartFastSimpleSync
    (0x805EA390, 0x300),
    (0x805EAC60, 0x480),
    (0x805F08C0, 0x490),
    (0x805F0FD0, 0x4A0),
    (0x805F3B00, 0x4C0),
    (0x805F43D0, 0x4E0),
    (0x805F46A0, 0x4F0),
    (0x805F6DC0, 0x570),
    # .ctors, also applies to .dtors and .rodata
    (0x80643D20, 0x580),
    # .rodata
    (0x8064CBB0, 0x590),  # After language-related table
    (0x8064CF18, 0x598),  # cLanguages__22@unnamed@Language_cpp@
    (0x8064CF80, 0x5A0),
    (0x806599A0, -0x5460),  # After ErrorMessageArchive
    # .data
    (0x806F920C, -0x5464),  # "TxtGalaxyNameU"
    (0x806F9220, -0x5468),  # "Unknown"
    (0x80700E18, -0x5458),  # "English"
    (0x80700F00, -0x5460),
    (0x807024B0, -0x5448),  # "/ObjectData/Yoshi.arc"
    (0x8070260C, -0x5468),  # "/ObjectData/PlanetMapDataTable.arc"
    (0x80702758, -0x5448),  # "/LayoutData/GameOver.arc"
    (0x8070C560, -0x5440),
    (0x8070CB58, -0x5438),
    (0x80721960, -0x5440),
    (0x807255C4, -0x5434),
    (0x807255C4, -0x543C),
    (0x807258D8, -0x5430),
    # .bss
    (0x8072DD80, 0xEA40),
    # .sdata
    (0x807D4A20, -0xAC100),
    (0x807D59B8, -0xAC0F8),
    (0x807D59D8, -0xAC0F0),
    (0x807D5DEC, -0xAC0E8),
    # .sbss
    (0x807D6480, -0xAC100),
    (0x807DBA48, -0xAC0F8),
    (0x807DBFE0, -0xAC0E0),
    (0x807DC1F4, -0xAC0DC),
    (0x807DC210, -0xAC0D8),
    (0x807DC3A0, -0xAC0E0),
    # .sdata2
    (0x807E7880, -0xAC0D0),
    # .sbss2
    (0x807E86C0, -0xAC0E0),
]

KOR_OFFSETS = [
    # .text
    (0x8047B110, 0x10),  # initTextBoxPane__14LayoutCoreUtilFPQ34nw4r3lyt7TextBoxPCcUl
    (0x80492340, 0x50),  # appear__9StaffRollFv
    (0x80494AA0, 0x70),
    (0x804BD390, 0x90),  # getLanguageNum__2MRFv
    (0x8054B440, 0x100),
    (0x805E7BE0, 0x110),  # wpad.a
    (0x805E8140, 0x120),  # wpad.a
    (0x805E8DF0, 0x1B0),  # wpad.a
    (0x805EA130, 0x1D0),  # WPADStartFastSimpleSync
    (0x805EA390, 0x300),
    (0x805EAC60, 0x480),
    (0x805F08C0, 0x490),
    (0x805F0FD0, 0x4A0),
    (0x805F3B00, 0x4C0),
    (0x805F43D0, 0x4E0),
    (0x805F46A0, 0x4F0),
    (0x805F6DC0, 0x570),
    # .ctors, also applies to .dtors and .rodata
    (0x80643D20, 0x580),
    # .rodata
    (0x8064CBB0, 0x590),  # After language-related table
    (0x8064CF18, 0x598),  # cLanguages__22@unnamed@Language_cpp@
    (0x8064CF80, 0x5A0),
    (0x806599A0, -0x68C0),  # After ErrorMessageArchive
    # .data
    (0x806F920C, -0x5464),  # "TxtGalaxyNameU"
    (0x806F9220, -0x5468),  # "Unknown"
    (0x80700E18, -0x5458),  # "English"
    (0x80700F00, -0x5460),
    (0x807024B0, -0x5448),  # "/ObjectData/Yoshi.arc"
    (0x8070260C, -0x5468),  # "/ObjectData/PlanetMapDataTable.arc"
    (0x80702758, -0x5448),  # "/LayoutData/GameOver.arc"
    # .data
    (0x806F920C, -0x68C4),  # "TxtGalaxyNameU"
    (0x806F9220, -0x68C8),  # "Unknown"
    (0x80700E18, -0x68B8),  # "English"
    (0x80700F00, -0x68C0),
    (0x807024B0, -0x68A8),  # "/ObjectData/Yoshi.arc"
    (0x8070260C, -0x68C8),  # "/ObjectData/PlanetMapDataTable.arc"
    (0x80702758, -0x68A8),  # "/LayoutData/GameOver.arc"
    (0x8070C560, -0x68A0),
    (0x8070CB58, -0x6898),
    (0x80721960, -0x68A0),
    (0x807255C4, -0x6894),
    (0x807255C4, -0x689C),
    (0x807258D8, -0x6890),
    # .bss
    (0x8072DD80, 0xD600),
    # .sdata
    (0x807D4A20, -0xAD560),
    (0x807D59B8, -0xAD558),
    (0x807D59D8, -0xAD550),
    (0x807D5DEC, -0xAD548),
    # .sbss
    (0x807D6480, -0xAD560),
    (0x807DBA48, -0xAD558),
    (0x807DBFE0, -0xAD540),
    (0x807DC1F4, -0xAD53C),
    (0x807DC210, -0xAD538),
    (0x807DC3A0, -0xAD540),
    # .sdata2
    (0x807E7880, -0xAD530),
    # .sbss2
    (0x807E86C0, -0xAD540),
]

# Stores current offset information for all non-PAL regions. Each element is a list of three values. First is the offset
# to apply to addresses, second is the next index into the offsets table and third is the offsets table.
CUR_OFFSET_INFO = {
    "USA": [0x0, 0, USA_OFFSETS],
    "JAP": [0x0, 0, JAP_OFFSETS],
    "TWN": [0x0, 0, TWN_OFFSETS],
    "KOR": [0x0, 0, KOR_OFFSETS]
}


# This function goes through all regions and tries to find the next offset to apply to symbol addresses. If a new offset
# has been found, the current offset info for the corresponding region will be updated.
def try_advance_offsets(address: int):
    for region in REGIONS:
        # PAL is used as the base, so we do not have to calculate offsets for that region
        if region == "PAL":
            continue

        offset_info = CUR_OFFSET_INFO[region]
        _, next_index, all_offsets = offset_info

        if next_index >= len(all_offsets):
            continue

        next_off_address, next_offset = all_offsets[next_index]

        if address >= next_off_address:
            offset_info[0] = next_offset
            offset_info[1] = next_index + 1


# Returns the offset to apply to addresses for the specified target region
def get_offset(region: str) -> int:
    return CUR_OFFSET_INFO[region][0]


# Stores all the symbols and their addresses for each target region
SYMBOLS = {
    "PAL": list(),
    "USA": list(),
    "JAP": list(),
    "TWN": list(),
    "KOR": list(),
}

# Read all symbols from the MAP file, adjust their offsets and append them to the respective symbol lists. Note that
# this script was designed specifically for IDA map files. I'm pretty sure that Ghidra uses a different format so these
# are very likely not compatible with this.
with open("SB4P01.map", "r") as f:
    found_addresses = False
    is_data = False

    for line in f:
        line = line.strip("\n")

        # First of all, we have to find the start of addresses. The header is always the same, so we look for its
        # contents.
        if not found_addresses and "Publics by Value" in line:
            found_addresses = True
            continue
        # Skip any non-symbol line
        if not found_addresses or not line.startswith(" "):
            continue

        # Get address and symbol from line
        address_str, symbol = line[6:].split("       ")
        address_int = int(address_str, 16)

        # Try to advance the offsets for all regions
        try_advance_offsets(address_int)

        # Discard nullsubs, defs and jumps
        if symbol.find("nullsub") == 0 or symbol.find("def_") == 0 or symbol.find("j_") == 0:
            continue

        # "sub" has been renamed to "subtract" since sub is used as a special keyword in IDA. We have to take this into
        # account and rename corresponding symbols.
        if symbol.find("subtract") != -1:
            symbolr = symbol.split("__")[1]
            symbol = f"sub__{symbolr}"

        # Treat and filter data symbols differently. Most of the time, we remove useless data such as strings
        if is_data:
            # Replace __vtbl__ with __vt__
            if symbol.startswith("__vtbl__"):
                symbol = f"__vt__{symbol[8:]}"
            # Keep static instances, objects, etc.
            elif "__" in symbol:
                pass
            # Discard useless data
            else:
                continue

        # "__DBEXIWriteRam" is the last function symbol in SMG2. After this comes all data
        if address_int > 0x80643C38:
            is_data = True

        for region in REGIONS:
            if region == "PAL":
                symbol_str = f"{symbol}=0x{address_str}\n"
            else:
                symbol_str = f"{symbol}=0x{address_int + get_offset(region):08X}\n"

            SYMBOLS[region].append(symbol_str)


# Write all symbol files
for region in REGIONS:
    with open(f"deps/symbols/{region}.txt", "w") as f:
        for line in SYMBOLS[region]:
            f.write(line)
