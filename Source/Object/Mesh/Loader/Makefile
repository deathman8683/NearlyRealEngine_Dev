SRC = NRE_MeshLoader.cpp
OBJ = $(OBJDIR)NRE_MeshLoader.o
OBJDIR = ../../../../obj/Debug/Object/Mesh/Loader/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
