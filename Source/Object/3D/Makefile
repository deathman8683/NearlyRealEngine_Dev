SRC = NRE_Object3D.cpp
OBJ = $(OBJDIR)NRE_Object3D.o
OBJDIR = ../../../obj/Debug/Object/3D/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
