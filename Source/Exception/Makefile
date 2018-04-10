SRC = NRE_ExceptionHandler.cpp
OBJ = $(OBJDIR)NRE_ExceptionHandler.o
OBJDIR = ../../obj/Debug/Exception/

SHADER = ShaderException
SUPPORT = SupportException
SDL = SDLException

all : $(TARGET) after

after:
	@(cd $(SHADER) && $(MAKE))
	@(cd $(SUPPORT) && $(MAKE))
	@(cd $(SDL) && $(MAKE))

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
