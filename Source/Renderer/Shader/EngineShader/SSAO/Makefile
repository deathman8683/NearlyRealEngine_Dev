SRC = NRE_SSAOShader.cpp
OBJ = $(OBJDIR)NRE_SSAOShader.o
OBJDIR = ../../../../../obj/Debug/Renderer/Shader/EngineShader/SSAO/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
