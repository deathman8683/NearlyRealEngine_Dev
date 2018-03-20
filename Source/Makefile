SRC = NRE_Main.cpp
OBJ = $(OBJDIR)NRE_Main.o
OBJDIR = ../obj/Debug/

all : before $(TARGET)

GENERIC = Generic
EXCEPTION = Exception
LIB = lib
SDL_WRAPPER = SDL_Wrapper
GL_WRAPPER = GL_Wrapper
TIME = Time
RENDERER = Renderer
LIGHTING = Lighting
CAMERA = Camera
WORLD = World
SUPPORT = Support

before :
	@(cd $(GENERIC) && $(MAKE))
	@(cd $(EXCEPTION) && $(MAKE))
	@(cd $(LIB) && $(MAKE))
	@(cd $(SDL_WRAPPER) && $(MAKE))
	@(cd $(GL_WRAPPER) && $(MAKE))
	@(cd $(TIME) && $(MAKE))
	@(cd $(RENDERER) && $(MAKE))
	@(cd $(LIGHTING) && $(MAKE))
	@(cd $(CAMERA) && $(MAKE))
	@(cd $(WORLD) && $(MAKE))
	@(cd $(SUPPORT) && $(MAKE))

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
