SRC = NRE_Maths.cpp
OBJ = $(OBJDIR)NRE_Maths.o
OBJDIR = ../../obj/Debug/Maths/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
