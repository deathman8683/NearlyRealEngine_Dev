SRC = NRE_VertexShader.cpp
OBJ = $(OBJDIR)NRE_VertexShader.o
OBJDIR = ../../../../../obj/Debug/Renderer/Shader/ShaderBase/VertexShader/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
