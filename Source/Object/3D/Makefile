SRC = NRE_Object3D.cpp
OBJ = $(OBJDIR)NRE_Object3D.o
OBJDIR = ../../../obj/Debug/Object/3D/

VOXEL = VoxelObject

all : $(TARGET) after

debug : $(OBJ)

after:
	@(cd $(VOXEL) && $(MAKE))

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
