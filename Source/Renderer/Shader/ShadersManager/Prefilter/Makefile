SRC = NRE_PrefilterShader.cpp
OBJ = $(OBJDIR)NRE_PrefilterShader.o
OBJDIR = ../../../../../obj/Debug/Renderer/Shader/ShadersManager/Prefilter/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
