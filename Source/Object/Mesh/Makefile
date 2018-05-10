SRC = NRE_Mesh.cpp
OBJ = $(OBJDIR)NRE_Mesh.o
OBJDIR = ../../../obj/Debug/Object/Mesh/

DATA = Data
2D = 2D
3D = 3D

all : before $(TARGET) after

before:
	@(cd $(DATA) && $(MAKE))

after:
	@(cd $(2D) && $(MAKE))
	@(cd $(3D) && $(MAKE))

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
