SRC = NRE_Chunk.cpp
OBJ = $(OBJDIR)NRE_Chunk.o
OBJDIR = ../../../obj/Debug/World/Chunk/

MANAGER = ChunksManager

all : $(TARGET) after

debug : $(OBJ)

after:
	@(cd $(MANAGER) && $(MAKE))

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
