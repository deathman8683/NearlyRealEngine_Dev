export CXX = g++.exe
export LD = g++.exe

export CFLAGS = -Wall -std=c++14
export LDFLAGS =

export INC = -I"C:\lib\MinGW\include"
export LIBDIR = -L"C:\lib\MinGW\lib"
export LIB = "C:\lib\MinGW\lib\libmingw32.a"

export TARGET = debug

OBJDIR = obj/Debug/
BIN = bin/Debug/
OBJ = $(OBJDIR)NRE_Main.o
OUT = NearlyRealEngine_Dev

SOURCE = Source

all : before $(TARGET)

before:
	@(cd $(SOURCE) && $(MAKE))

debug : $(OBJ)
	@$(LD) $(LIBDIR) -o $(BIN)$(OUT) $^ $(LDFLAGS) $(LIB)
	@echo "Jobs done."

clean :
	@echo "Clear of obj/"
	@rm -r obj
	@mkdir obj
	@mkdir obj/Debug
	@echo "obj/-Tree creation done."
	@echo "Clean done."
