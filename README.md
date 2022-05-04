# Syati
**Syati** is a coding toolkit for custom code injections in **Super Mario Galaxy 2**. It is able to compile code, link to existing functions and structures in the game and load the actual changes ingame. It was originally created by **shibbo**.

# Requirements
In order to use this toolkit, you need to prepare some software and skills:
- The **CodeWarrior PPC EABI C/C++ Compiler**, preferrably version 4.0.0. There is also a free version of that compiler, but you may have to modify the compiler options in the two build scripts.
- A build of the [**Kamek**](https://github.com/Treeki/Kamek) linker.
- **Python 3.7** or newer
- Knowledge of *C** / **C++** / **PowerPC**

Setup is easy. Put the CodeWarrior files (*mwcceppc.exe*, etc.) in ``deps/CodeWarrior`` and the Kamek files in ``deps/Kamek``. Now, try to run the build scripts to check if it recognizes the tools.

# Building
Provided you have all the requirements set up, building is very easy. To build a binary of your new custom code, run:
```python build.py REGION```, where REGION is the game's target region to build for.

To build the loader, run this instead:
```python buildloader.py REGION```, where REGION is, again, the target region to build for.

The following region targets exist:
- **PAL**: European/Australian releases
- **USA**: American releases
- **JAP**: Japanese releases
- **TWN**: Taiwanese releases
- **KOR**: Korean releases

The generated XML patches for Riivolution can be found in the *loader* folder.

# What is supplied
Four C++ code files are supplied with this kit, as a starting point for your own custom code hacks:
- **init.cpp** initializes static structures and instances when loading in the custom code.
- **archive.cpp** is an implemention of a simplified archive loader. It can be used to mount any archive from the game's filesystem and access its stored files.
- **factory.cpp** is an implementation of an extended actor list. Instead of replacing actors for new ones, we simply make our own separate table and load that if the first NameObj creation function finder fails.
- **SceneChangeArea.cpp** is a complete reimplementation of SceneChangeArea::control. It takes two arguments in, *Obj_arg0* accesses a list to which Galaxy to go to, and **Obj_arg1** determines the white fade time.