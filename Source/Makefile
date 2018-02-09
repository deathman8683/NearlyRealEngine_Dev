SRC = NRE_Main.cpp
OBJ = $(OBJDIR)NRE_Main.o
OBJDIR = ../obj/Debug/

all : before $(TARGET)

SDL_WRAPPER = SDL_Wrapper

before :
	@(cd $(SDL_WRAPPER) && $(MAKE))

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
