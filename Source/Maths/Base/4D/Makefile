SRC = NRE_Base4D.cpp
OBJ = $(OBJDIR)NRE_Base4D.o
OBJDIR = ../../../../obj/Debug/Maths/Base/4D/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
