SRC = NRE_TextureBuffer.cpp
OBJ = $(OBJDIR)NRE_TextureBuffer.o
OBJDIR = ../../../../obj/Debug/GL_Wrapper/Buffer/TextureBuffer/

2D = 2D
3D = 3D

all : $(TARGET) after

after:
	@(cd $(2D) && $(MAKE))

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
