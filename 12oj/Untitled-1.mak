CXXFLAGS += -IC:\Users\HP\OneDrive\文档\GitHub\2023-cpl-coding-2\project_prepare\mingw(CLion+VSC)\SDL2-2.26.0-allinone\x86_64-w64-mingw32\include #改成你电脑上的include路径
# CXXFLAGS += -fexec-charset=GBK -finput-charset=UTF-8
LDFLAGS +=  -LC:\Users\HP\OneDrive\文档\GitHub\2023-cpl-coding-2\project_prepare\mingw(CLion+VSC)\SDL2-2.26.0-allinone\x86_64-w64-mingw32\lib  # 改成你电脑上的lib路径

CXXFLAGS += -std=c++23 
# 如果不用特别新的C++特性，上面这行不用写
LDLIBS += -lSDL2

LDLIBS += -mwindows # 用于去除运行时命令行窗口


main.exe: main.o
    $(CXX) $^ -o $(basename $@) $(LDFLAGS) $(LDLIBS)

.PHONY: run clean

run: main.exe
    $<

clean:
    $(RM) *.exe *.o