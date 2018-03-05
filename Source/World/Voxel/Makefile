SRC = NRE_Voxel.cpp
OBJ = $(OBJDIR)NRE_Voxel.o
OBJDIR = ../../../obj/Debug/World/Voxel/

TYPE = Type
PACKED = PackedVertex

all : $(TARGET) after

after:
	@(cd $(TYPE) && $(MAKE))
	@(cd $(PACKED) && $(MAKE))

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
