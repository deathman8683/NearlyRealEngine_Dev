SRC = NRE_EventHandler.cpp
OBJ = $(OBJDIR)NRE_EventHandler.o
OBJDIR = ../../../../obj/Debug/Camera/Input/EventHandler/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
