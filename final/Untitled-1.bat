 cd "c:\Users\HP\OneDrive\文档\GitHub\2023-cpl-coding-2\final\" ; if ($?) { gcc test1225.c -o test1225 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer} ; if ($?) { .\test1225 }
 gcc test1225.c -o test1225 -LC:\Users\HP\OneDrive\文档\GitHub\2023-cpl-coding-2\final\SDL2-2.26.0-allinone\x86_64-w64-mingw32\bin -IC:\Users\HP\OneDrive\文档\GitHub\2023-cpl-coding-2\final\SDL2-2.26.0-allinone\x86_64-w64-mingw32\include\SDL2 -l mingw32 -l SDL2main -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer
 cd "c:\Users\HP\Desktop\cpl_final\" ; if ($?) { gcc test1225evening.c -o test1225evening -l mingw32 -l SDL2main -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer} ; if ($?) { .\test1225evening }