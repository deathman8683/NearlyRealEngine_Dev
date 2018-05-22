SRC = NRE_SSAOShader.cpp
OBJ = $(OBJDIR)NRE_SSAOShader.o
OBJDIR = ../../../../../obj/Debug/Renderer/Shader/ShadersManager/SSAO/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
