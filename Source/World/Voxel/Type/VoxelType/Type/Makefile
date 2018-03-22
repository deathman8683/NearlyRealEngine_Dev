SRC = NRE_Type.cpp
OBJ = $(OBJDIR)NRE_Type.o
OBJDIR = ../../../../../../obj/Debug/World/Voxel/Type/VoxelType/Type/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
