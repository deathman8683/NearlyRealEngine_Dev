SRC = NRE_BRDFShader.cpp
OBJ = $(OBJDIR)NRE_BRDFShader.o
OBJDIR = ../../../../../obj/Debug/Renderer/Shader/ShadersManager/BRDF/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
