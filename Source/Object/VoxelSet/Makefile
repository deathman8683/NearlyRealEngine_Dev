SRC = NRE_VoxelSet.cpp
OBJ = $(OBJDIR)NRE_VoxelSet.o
OBJDIR = ../../../obj/Debug/Object/VoxelSet/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
