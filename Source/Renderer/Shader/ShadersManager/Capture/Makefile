SRC = NRE_CaptureShader.cpp
OBJ = $(OBJDIR)NRE_CaptureShader.o
OBJDIR = ../../../../../obj/Debug/Renderer/Shader/ShadersManager/Capture/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
