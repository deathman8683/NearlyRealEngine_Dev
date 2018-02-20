SRC = NRE_Event.cpp
OBJ = $(OBJDIR)NRE_Event.o
OBJDIR = ../../../obj/Debug/SDL_Wrapper/Event/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
