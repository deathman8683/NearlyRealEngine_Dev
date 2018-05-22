SRC = NRE_ChunksManager.cpp
OBJ = $(OBJDIR)NRE_ChunksManager.o
OBJDIR = ../../../../obj/Debug/World/Chunk/ChunksManager/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
