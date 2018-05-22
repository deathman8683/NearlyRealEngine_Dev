SRC = NRE_PBRShader.cpp
OBJ = $(OBJDIR)NRE_PBRShader.o
OBJDIR = ../../../../../obj/Debug/Renderer/Shader/ShadersManager/PBR/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
