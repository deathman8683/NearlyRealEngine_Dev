SRC = NRE_Window.cpp
OBJ = $(OBJDIR)NRE_Window.o
OBJDIR = ../../../obj/Debug/SDL_Wrapper/Window/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
