# Syati
**Syati** provides C++ headers and symbols for writing custom code injections in **Super Mario Galaxy 2**. With this, you can write code, compile code, link to existing functions and structures in the game and load the actual changes. It was originally created by **shibbo**, however, the original repository has been deleted.

# What is supplied
Syati provides C++ headers, symbols, the CustomCode loader and six sample C++ code files.

- **loader**: The source code for the CustomCode loader and crash debugger patches. The loader automatically adjusts the game's memory heaps to fit a large batch of new code. The CustomCode binary that it loads depends on the version of the game played. If a CustomCode binary doesn't exist, the loader initialization is aborted, however, the crash debugger will still be enabled.
- **init.cpp**: Calls all linked static initializers. This is necessary to initialize static variables and constants in the BSS segment of your code. Custom Nerve instances will be stored there, for example.
- **ExtNameObjFactory.cpp**: Extends the existing ``NameObjFactory`` by taking into account your table of new objects. The custom creation table with actor entries is defined in the respective header file.
- **ExtSceneChangeArea.cpp**: A reimplementation of ``SceneChangeArea``'s "control" method. It takes two arguments in, *Obj_arg0* accesses a list to which Galaxy to go to, and *Obj_arg1* determines the white screen fade time.
- **PadRecord.cpp**: Helper code for recording PAD input playback files. Requires the external tool [galaxymsbt](https://github.com/SunakazeKun/galaxypad) to produce PAD files during gameplay.
- **archive.cpp**: A simplified archive loader. It can be used to mount any archive from the game's filesystem and access its stored files. The files are stored in ``StationedHeapNapa``.

# Future Plans
The loader currently only supports ``Kamek`` version 1, which is outdated. Support for new hooks and the general format should be implemented in future versions.

# Requirements
In order to use this toolkit, you need to prepare some software and skills:

- The **CodeWarrior PPC EABI C/C++ Compiler**, preferrably application version 4.3.0.172. There is also a free version of that compiler, but you may have to modify the compiler options in the two build scripts.
- A build of the [**Kamek**](https://github.com/Treeki/Kamek) linker.
- Knowledge of **C** / **C++** / **PowerPC**.
- **Python 3.7** or newer.

# Building
Setup is easy. Put the CodeWarrior files (*mwcceppc.exe*, etc.) in ``deps/CodeWarrior`` and the Kamek files in ``deps/Kamek``. Now, try to run the build scripts to check if they recognize the tools.

Provided you have all the requirements set up, building is very easy. To build a binary of your new custom code, run:
```python build.py REGION```, where REGION is the game's target region to build for.

To build the loader, run this instead:
```python buildloader.py REGION```, where REGION is, again, the target region to build for.

The following region targets exist:
- **PAL**: European/Australian releases
- **USA**: American releases
- **JPN**: Japanese releases
- **TWN**: Taiwanese releases
- **KOR**: Korean releases

The generated XML patches for Riivolution can be found in the *bin* folder.