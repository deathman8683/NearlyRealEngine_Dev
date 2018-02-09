export CXX = g++.exe
export LD = g++.exe

export CFLAGS = -Wall -std=c++14
export LDFLAGS =

export INC = -I"C:\lib\MinGW\include" -I"C:\lib\SDL2-2.0.5\i686-w64-mingw32\include"
export LIBDIR = -L"C:\lib\MinGW\lib"  -L"C:\lib\SDL2-2.0.5\i686-w64-mingw32\lib"
export LIB = "C:\lib\MinGW\lib\libmingw32.a" "C:\lib\SDL2-2.0.5\i686-w64-mingw32\lib\libSDL2main.a" "C:\lib\SDL2-2.0.5\i686-w64-mingw32\lib\libSDL2.dll.a"

export TARGET = debug

ifeq ($(TARGET), debug)
	OBJDIR = obj/Debug/
	BIN = bin/Debug/
	SOURCE = Source
	OBJ = $(OBJDIR)SDL_Wrapper/Window/NRE_Window.o $(OBJDIR)NRE_Main.o

else
	OBJDIR = obj/Test/
	BIN = bin/Test/
	SOURCE = Source_Test
	OBJ = $(OBJDIR)NRET_Main.o

endif

OUT = NearlyRealEngine_Dev

all : before out

before:
	@(cd $(SOURCE) && $(MAKE))

out : $(OBJ)
	@$(LD) $(LIBDIR) -o $(BIN)$(OUT) $^ $(LDFLAGS) $(LIB)
	@echo "Jobs done."

clean :
	@echo "Clear of obj/"
	@rm -r obj
	@mkdir obj
	@mkdir obj/Debug
	@mkdir obj/Debug/SDL_Wrapper
	@mkdir obj/Debug/SDL_Wrapper/Window
	@echo "obj/-Tree creation done."
	@echo "Clean done."

clean_Test :
	@echo "Clear of obj/"
	@rm -r obj
	@mkdir obj
	@mkdir obj/Test
	@mkdir obj/Test/SDL_Wrapper
	@mkdir obj/Test/SDL_Wrapper/Window
	@echo "obj/-Tree creation done."
	@echo "Clean done."
