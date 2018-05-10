SRC = NRE_Init.cpp
OBJ = $(OBJDIR)NRE_Init.o
OBJDIR = ../../../obj/Debug/Generic/Init/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
