SRC = NRE_Input.cpp
OBJ = $(OBJDIR)NRE_Input.o
OBJDIR = ../../../obj/Debug/Camera/Input/

KEYBINDER = KeyBinder
KEYBOARD = Keyboard
MOUSE = Mouse
EVENTHANDLER = EventHandler

all : before $(TARGET)

before:
	@(cd $(KEYBINDER) && $(MAKE))
	@(cd $(KEYBOARD) && $(MAKE))
	@(cd $(MOUSE) && $(MAKE))
	@(cd $(EVENTHANDLER) && $(MAKE))

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
