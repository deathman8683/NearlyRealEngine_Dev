SRC = NRE_ExceptionHandler.cpp
OBJ = $(OBJDIR)NRE_ExceptionHandler.o
OBJDIR = ../../obj/Debug/Exception/

SHADER = ShaderException
SUPPORT = SupportException
SDL = SDLException
GL = GLException
IO = IOException
SECURITY = SecurityException
ASSIMP = AssimpException

all : $(TARGET) after

after:
	@(cd $(SHADER) && $(MAKE))
	@(cd $(SUPPORT) && $(MAKE))
	@(cd $(SDL) && $(MAKE))
	@(cd $(GL) && $(MAKE))
	@(cd $(IO) && $(MAKE))
	@(cd $(SECURITY) && $(MAKE))
	@(cd $(ASSIMP) && $(MAKE))

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
