SRC = NRE_ChunkConstructor.cpp
OBJ = $(OBJDIR)NRE_ChunkConstructor.o
OBJDIR = ../../../obj/Debug/World/ChunkConstructor/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
