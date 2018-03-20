SRC = NRE_ShaderBase.cpp
OBJ = $(OBJDIR)NRE_ShaderBase.o
OBJDIR = ../../../../obj/Debug/Renderer/Shader/ShaderBase/

VERTEX = VertexShader
FRAGMENT = FragmentShader

all : $(TARGET) after

after:
	@(cd $(VERTEX) && $(MAKE))
	@(cd $(FRAGMENT) && $(MAKE))

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
