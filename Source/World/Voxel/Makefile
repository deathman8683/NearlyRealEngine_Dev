SRC = NRE_Voxel.cpp
OBJ = $(OBJDIR)NRE_Voxel.o
OBJDIR = ../../../obj/Debug/World/Voxel/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
