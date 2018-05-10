SRC = NRE_Mesh3D.cpp
OBJ = $(OBJDIR)NRE_Mesh3D.o
OBJDIR = ../../../../obj/Debug/Object/Mesh/3D/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
