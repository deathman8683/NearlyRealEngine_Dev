SRC = NRE_Texture2DBuffer.cpp
OBJ = $(OBJDIR)NRE_Texture2DBuffer.o
OBJDIR = ../../../../../obj/Debug/GL_Wrapper/Buffer/TextureBuffer/2D/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
