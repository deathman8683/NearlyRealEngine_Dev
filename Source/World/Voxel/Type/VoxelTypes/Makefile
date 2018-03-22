SRC = NRE_VoxelTypes.cpp
OBJ = $(OBJDIR)NRE_VoxelTypes.o
OBJDIR = ../../../../../obj/Debug/World/Voxel/Type/VoxelTypes/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
