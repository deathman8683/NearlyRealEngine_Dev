SRC = NRE_Mesh3D.cpp
OBJ = $(OBJDIR)NRE_Mesh3D.o
OBJDIR = ../../../../obj/Debug/Object/Mesh/3D/

VOXEL = VoxelMesh

all : $(TARGET) after

debug : $(OBJ)

after:
	@(cd $(VOXEL) && $(MAKE))

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
