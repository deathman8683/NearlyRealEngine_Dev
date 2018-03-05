SRC = NRE_PackedVertex.cpp
OBJ = $(OBJDIR)NRE_PackedVertex.o
OBJDIR = ../../../../obj/Debug/World/Voxel/PackedVertex/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
