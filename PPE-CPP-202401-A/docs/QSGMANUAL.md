# Introduction
Welcome to Program Performer Engine (PPE)

You are reading Quick Start Guide Manual (QSGMANUAL.md)

# References
https://en.wikipedia.org/wiki/Quickstart_guide

# Design Philosophy
The design philosophy as one single header file for more easily access

I don't know much about CMAKE, so I won't use any goddamn complicated confusing over the top features

# Setup
- Create folder named "project"
- Use cd command into "project" folder
```
cd project
```
- Use CMAKE commands to craete Visual Studio project (prefer VS2022)
```
./ make
```
- Open sln project
- Check project solution setup as identical as possible from image provided

# Customization Setup
- Open CMakeLists.txt, 3rdparty.txt, PPE.txt, 
- Open Program.txt (This is yours own code, add when needed)
- There are options that you might want if needed

# API

- ProgramObject (Operate in kernal main core loop)

In any type of program you are developing, you should have a ProgramObject to work at, to manage all subsystem that you need to access

- AudioProgramObject (Inherit from ProgramObject)
- GameProgramObject (Inherit from ProgramObject)
