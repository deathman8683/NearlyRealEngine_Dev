SRC = NRE_VoxelType.cpp
OBJ = $(OBJDIR)NRE_VoxelType.o
OBJDIR = ../../../../../obj/Debug/World/Voxel/Type/VoxelType/

TYPE = Type

all : $(TARGET) after

after:
	@(cd $(TYPE) && $(MAKE))

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
