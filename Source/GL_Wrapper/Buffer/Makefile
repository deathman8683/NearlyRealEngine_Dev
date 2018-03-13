SRC = NRE_Buffer.cpp
OBJ = $(OBJDIR)NRE_Buffer.o
OBJDIR = ../../../obj/Debug/GL_Wrapper/Buffer/

ATTRIBUTE = AttributeBuffer
TEXTURE = TextureBuffer
VAO = VAO

all : $(TARGET) after

after:
	@(cd $(ATTRIBUTE) && $(MAKE))
	@(cd $(TEXTURE) && $(MAKE))

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
