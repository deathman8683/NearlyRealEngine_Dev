SRC = NRE_Object.cpp
OBJ = $(OBJDIR)NRE_Object.o
OBJDIR = ../../obj/Debug/Object/

2D = 2D
3D = 3D
MESH = Mesh
CACHE = MergingCache
VOXEL = VoxelSet

all : before $(TARGET) after

before:
	@(cd $(MESH) && $(MAKE))
	@(cd $(CACHE) && $(MAKE))
	@(cd $(VOXEL) && $(MAKE))

after:
	@(cd $(2D) && $(MAKE))
	@(cd $(3D) && $(MAKE))

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
