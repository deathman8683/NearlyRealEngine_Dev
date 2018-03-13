SRC = NRE_TextureBuffer.cpp
OBJ = $(OBJDIR)NRE_TextureBuffer.o
OBJDIR = ../../../../obj/Debug/GL_Wrapper/Buffer/TextureBuffer/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
