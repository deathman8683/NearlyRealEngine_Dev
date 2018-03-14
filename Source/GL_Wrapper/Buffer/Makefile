SRC = NRE_Buffer.cpp
OBJ = $(OBJDIR)NRE_Buffer.o
OBJDIR = ../../../obj/Debug/GL_Wrapper/Buffer/

ATTRIBUTE = AttributeBuffer
TEXTURE = TextureBuffer
FRAME = FrameBuffer
RENDER = RenderBuffer
VAO = VAO

all : $(TARGET) after

after:
	@(cd $(ATTRIBUTE) && $(MAKE))
	@(cd $(TEXTURE) && $(MAKE))
	@(cd $(FRAME) && $(MAKE))
	@(cd $(RENDER) && $(MAKE))
	@(cd $(VAO) && $(MAKE))

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
