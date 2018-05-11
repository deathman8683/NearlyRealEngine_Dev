SRC = NRE_Voxel.cpp
OBJ = $(OBJDIR)NRE_Voxel.o
OBJDIR = ../../../obj/Debug/World/Voxel/

TYPE = Type
POINT = VoxelPoint

all : before $(TARGET)

before:
	@(cd $(TYPE) && $(MAKE))
	@(cd $(POINT) && $(MAKE))

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
