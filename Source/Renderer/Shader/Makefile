SRC = NRE_Shader.cpp
OBJ = $(OBJDIR)NRE_Shader.o
OBJDIR = ../../../obj/Debug/Renderer/Shader/

BASE = ShaderBase

all : before $(TARGET)

before:
	@(cd $(BASE) && $(MAKE))

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
