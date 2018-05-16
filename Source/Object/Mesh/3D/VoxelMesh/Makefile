SRC = NRE_VoxelMesh.cpp
OBJ = $(OBJDIR)NRE_VoxelMesh.o
OBJDIR = ../../../../../obj/Debug/Object/Mesh/3D/VoxelMesh/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
