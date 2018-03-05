SRC = NRE_Chunk.cpp
OBJ = $(OBJDIR)NRE_Chunk.o
OBJDIR = ../../../obj/Debug/World/Chunk/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
