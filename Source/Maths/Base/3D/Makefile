SRC = NRE_Base3D.cpp
OBJ = $(OBJDIR)NRE_Base3D.o
OBJDIR = ../../../../obj/Debug/Maths/Base/3D/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
