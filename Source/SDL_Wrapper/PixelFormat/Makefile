SRC = NRE_PixelFormat.cpp
OBJ = $(OBJDIR)NRE_PixelFormat.o
OBJDIR = ../../../obj/Debug/SDL_Wrapper/PixelFormat/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
