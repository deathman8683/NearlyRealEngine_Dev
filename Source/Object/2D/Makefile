SRC = NRE_Object2D.cpp
OBJ = $(OBJDIR)NRE_Object2D.o
OBJDIR = ../../../obj/Debug/Object/2D/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
