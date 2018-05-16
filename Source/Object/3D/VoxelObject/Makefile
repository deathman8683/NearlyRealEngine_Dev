SRC = NRE_VoxelObject.cpp
OBJ = $(OBJDIR)NRE_VoxelObject.o
OBJDIR = ../../../../obj/Debug/Object/3D/VoxelObject/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
