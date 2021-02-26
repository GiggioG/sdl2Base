# sdl2Base
### A test app I began by following a youtube tutorial to explore SDL2. It will also be the base of all my future SDL2 apps.
#### Explanation
I started this project after watching [codergopher](https://www.youtube.com/channel/UCfiC4q3AahU4Io-s83-CIbQ)'s [video playlist](https://www.youtube.com/playlist?list=PL2RPjWnJduNmXHRYwdtublIPdlqocBoLS). I followed it almost exactly, with the intension of making it as a base to all my future SDL2 projects.
#### Setup
1. Install mingw-w64 from [here](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/8.1.0/threads-win32/seh/x86_64-8.1.0-release-win32-seh-rt_v6-rev0.7z/download) and put it somewhere and add the `mingw/bin` path to the `Path` enviroment variable.
2. Install msys64 and add the `msys64/urs/bin` path to the `Path` enviroment variable.
3. Download SDL2 from [here](https://www.libsdl.org/release/SDL2-devel-2.0.14-mingw.tar.gz), extract it and put the `x86_64 -w64-mingw32` subfolder in your project folder. Be sure to rename it to `SDL2-64`.
4. Download SDL2_Image from [here](https://www.libsdl.org/projects/SDL_image/release/SDL2_image-devel-2.0.5-mingw.tar.gz), extract it and copy all the things from the `x86_64 -w64-mingw32` subfolder to your `SDL2-64` folder. When it asks you do you want to replace the files, select yes.
5. If your project folder doesn't contain an `obj` folder, then create it and also create a `release` and a `debug` folders in the `obj` folder.
6. a) If you are going to use [vscode](https://code.visualstudio.com/download), then open the `sdl2Base.code-workspace` file in vscode.
6. b) If you aren't going to use [vscode](https://code.visualstudio.com/download), then delete the `.vscode` folder and delete the `sdl2Base.code-workspace` file, as you won't need them. Then open the folder in your IDE.
7. Begin writing your code, then write `build` or `build release` to build and run your code for release, `build debug` to build your code for developement, or `build clean` to clean all the build files.