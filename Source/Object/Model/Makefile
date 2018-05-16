SRC = NRE_Model.cpp
OBJ = $(OBJDIR)NRE_Model.o
OBJDIR = ../../../obj/Debug/Object/Model/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
