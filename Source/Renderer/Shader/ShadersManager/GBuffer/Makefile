SRC = NRE_GBufferShader.cpp
OBJ = $(OBJDIR)NRE_GBufferShader.o
OBJDIR = ../../../../../obj/Debug/Renderer/Shader/ShadersManager/GBuffer/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
