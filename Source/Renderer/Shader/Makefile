SRC = NRE_Shader.cpp
OBJ = $(OBJDIR)NRE_Shader.o
OBJDIR = ../../../obj/Debug/Renderer/Shader/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
