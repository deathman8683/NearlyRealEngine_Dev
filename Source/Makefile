SRC = NRE_Main.cpp
OBJ = $(OBJDIR)NRE_Main.o
OBJDIR = ../obj/Debug/

all : before $(TARGET)

SDL_WRAPPER = SDL_Wrapper
GL_WRAPPER = GL_Wrapper
SUPPORT = Support
RENDERER = Renderer
CAMERA = Camera
WORLD = World

before :
	@(cd $(SDL_WRAPPER) && $(MAKE))
	@(cd $(GL_WRAPPER) && $(MAKE))
	@(cd $(CAMERA) && $(MAKE))
	@(cd $(WORLD) && $(MAKE))
	@(cd $(SUPPORT) && $(MAKE))
	@(cd $(RENDERER) && $(MAKE))

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
