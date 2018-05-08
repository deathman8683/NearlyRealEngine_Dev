SRC = NRE_Object.cpp
OBJ = $(OBJDIR)NRE_Object.o
OBJDIR = ../../obj/Debug/Object/

3D = 3D
MESH = Mesh

all : $(TARGET) after

after:
	@(cd $(3D) && $(MAKE))
	@(cd $(MESH) && $(MAKE))

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
