SRC = NRE_Base2D.cpp
OBJ = $(OBJDIR)NRE_Base2D.o
OBJDIR = ../../../../obj/Debug/Maths/Base/2D/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
