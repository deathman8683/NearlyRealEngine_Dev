SRC = NRE_TextureBuffer.cpp
OBJ = $(OBJDIR)NRE_TextureBuffer.o
OBJDIR = ../../../../../obj/Debug/GL_Wrapper/Texture/Buffer/Texture/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
