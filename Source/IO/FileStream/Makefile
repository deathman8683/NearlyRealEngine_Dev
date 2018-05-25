SRC = NRE_FileStream.cpp
OBJ = $(OBJDIR)NRE_FileStream.o
OBJDIR = ../../../obj/Debug/IO/FileStream/

IO = IOFile
INPUT = Input
OUTPUT = Output
BINARY = BinaryStream

all : $(TARGET) after

debug : $(OBJ)

after:
	@(cd $(INPUT) && $(MAKE))
	@(cd $(OUTPUT) && $(MAKE))
	@(cd $(IO) && $(MAKE))
	@(cd $(BINARY) && $(MAKE))

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
