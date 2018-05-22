SRC = NRE_IrradianceShader.cpp
OBJ = $(OBJDIR)NRE_IrradianceShader.o
OBJDIR = ../../../../../obj/Debug/Renderer/Shader/ShadersManager/Irradiance/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
