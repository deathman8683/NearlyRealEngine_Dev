SRC = NRE_Keyboard.cpp
OBJ = $(OBJDIR)NRE_Keyboard.o
OBJDIR = ../../../../obj/Debug/Camera/Input/Keyboard/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
