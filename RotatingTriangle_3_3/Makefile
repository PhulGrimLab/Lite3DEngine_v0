# 컴파일러 및 플래그
CXX = g++
CXXFLAGS = -g -Wall -Iinclude -IE:/PhulGrimLab_Works/GLFW/glfw-3.4.bin.WIN64/include

# 링크할 라이브러리 경로 및 대상
LDFLAGS = -LE:/PhulGrimLab_Works/GLFW/glfw-3.4.bin.WIN64/lib-mingw-w64 -lopengl32 -lgdi32 -luser32 -lshell32 -ladvapi32 -lglfw3dll


# 소스 및 출력 파일
SRC = main.cpp gl.c
OUT = rotate.exe

# 기본 빌드 명령
all:
	$(CXX) $(CXXFLAGS) -o $(OUT) $(SRC) $(LDFLAGS)

# 클린 명령
clean:
	del $(OUT)


