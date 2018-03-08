SRC = NRE_Surface.cpp
OBJ = $(OBJDIR)NRE_Surface.o
OBJDIR = ../../../obj/Debug/SDL_Wrapper/Surface/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
