SRC = NRE_VoxelType.cpp
OBJ = $(OBJDIR)NRE_VoxelType.o
OBJDIR = ../../../../obj/Debug/World/Voxel/Type/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
