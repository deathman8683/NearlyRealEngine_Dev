SRC = NRE_SkyBoxShader.cpp
OBJ = $(OBJDIR)NRE_SkyBoxShader.o
OBJDIR = ../../../../../obj/Debug/Renderer/Shader/ShadersManager/SkyBox/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
