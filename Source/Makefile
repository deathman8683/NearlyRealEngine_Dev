SRC = NRE_Main.cpp
OBJ = $(OBJDIR)NRE_Main.o
OBJDIR = ../obj/Debug/

all : before $(TARGET)

GENERIC = Generic
SDL_WRAPPER = SDL_Wrapper
GL_WRAPPER = GL_Wrapper
SUPPORT = Support
RENDERER = Renderer
CAMERA = Camera
WORLD = World
LIB = lib

before :
	@(cd $(GENERIC) && $(MAKE))
	@(cd $(LIB) && $(MAKE))
	@(cd $(SDL_WRAPPER) && $(MAKE))
	@(cd $(GL_WRAPPER) && $(MAKE))
	@(cd $(RENDERER) && $(MAKE))
	@(cd $(CAMERA) && $(MAKE))
	@(cd $(WORLD) && $(MAKE))
	@(cd $(SUPPORT) && $(MAKE))

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
