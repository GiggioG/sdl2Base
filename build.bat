@echo off
if "%1"=="" (
    goto release
)
if "%1"=="release" (
    goto release
)
if "%1"=="debug" (
    goto debug
)
if "%1"=="clean" (
    goto clean
)
goto end
:release
    cp -r res bin/release/res
    for %%s in (src\*.cpp) do (
        gcc -c %%s -std=c++14 -Wall -O3 -m64 -I include -I SDL2-64/include
    )
    mv *.o obj/release
    if not exist obj\release\*.o goto end
    g++ obj/release/*.o -o bin\release\main.exe -s -L SDL2-64\lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
    if not exist bin\release\main.exe goto end
    bin\release\main.exe
goto end
:debug
    cp -r res bin/debug/res
    for %%s in (src\*.cpp) do (
        gcc -c %%s -std=c++14 -Wall -g -m64 -I include -I SDL2-64/include
    )
    mv *.o obj/debug
    if not exist obj\debug\*.o goto end
    g++ obj/debug/*.o -o bin\debug\main.exe -L SDL2-64\lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
    if not exist bin\debug\main.exe goto end
    bin\debug\main.exe
goto end
:clean
    rm -f obj/release/*.o
    rm -f obj/debug/*.o
    rm -f bin/release/*.exe
    rm -f bin/debug/*.exe
    rm -f -r bin/release/res
    rm -f -r bin/debug/res
goto end
:end