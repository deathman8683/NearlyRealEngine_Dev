SRC = NRE_Voxel.cpp
OBJ = $(OBJDIR)NRE_Voxel.o
OBJDIR = ../../../obj/Debug/World/Voxel/

TYPE = Type

all : before $(TARGET)

before:
	@(cd $(TYPE) && $(MAKE))

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
