SRC = NRE_FragmentShader.cpp
OBJ = $(OBJDIR)NRE_FragmentShader.o
OBJDIR = ../../../../../obj/Debug/Renderer/Shader/ShaderBase/FragmentShader/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
