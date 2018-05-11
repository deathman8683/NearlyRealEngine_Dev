SRC = NRE_VoxelPoint.cpp
OBJ = $(OBJDIR)NRE_VoxelPoint.o
OBJDIR = ../../../../obj/Debug/World/Voxel/VoxelPoint/

all : $(TARGET)

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
