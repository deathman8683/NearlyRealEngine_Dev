SRC = NRE_Shader.cpp
OBJ = $(OBJDIR)NRE_Shader.o
OBJDIR = ../../../obj/Debug/Renderer/Shader/

BASE = ShaderBase
MAP = ShaderMap
ENGINE = EngineShader

all : before $(TARGET) after

before:
	@(cd $(BASE) && $(MAKE))
	@(cd $(MAP) && $(MAKE))

after:
	@(cd $(ENGINE) && $(MAKE))

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
