SRC = NRE_SDLException.cpp
OBJ = $(OBJDIR)NRE_SDLException.o
OBJDIR = ../../../obj/Debug/Exception/SDLException/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
