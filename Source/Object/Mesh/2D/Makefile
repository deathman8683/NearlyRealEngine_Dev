SRC = NRE_Mesh2D.cpp
OBJ = $(OBJDIR)NRE_Mesh2D.o
OBJDIR = ../../../../obj/Debug/Object/Mesh/2D/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
