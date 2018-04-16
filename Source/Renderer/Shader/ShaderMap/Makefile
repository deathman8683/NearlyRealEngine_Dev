SRC = NRE_ShaderMap.cpp
OBJ = $(OBJDIR)NRE_ShaderMap.o
OBJDIR = ../../../../obj/Debug/Renderer/Shader/ShaderMap/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
