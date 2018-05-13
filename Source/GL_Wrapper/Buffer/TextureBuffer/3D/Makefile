SRC = NRE_Texture3DBuffer.cpp
OBJ = $(OBJDIR)NRE_Texture3DBuffer.o
OBJDIR = ../../../../../obj/Debug/GL_Wrapper/Buffer/TextureBuffer/3D/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
