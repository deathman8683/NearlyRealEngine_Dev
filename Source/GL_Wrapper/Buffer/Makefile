SRC = NRE_Buffer.cpp
OBJ = $(OBJDIR)NRE_Buffer.o
OBJDIR = ../../../obj/Debug/GL_Wrapper/Buffer/

ATTRIBUTE = AttributeBuffer
DEPTH = DepthBuffer
TEXTURE = TextureBuffer
CUBEMAP = CubeMap
FRAME = FrameBuffer
RENDER = RenderBuffer
VAO = VAO

all : $(TARGET) after

after:
	@(cd $(ATTRIBUTE) && $(MAKE))
	@(cd $(DEPTH) && $(MAKE))
	@(cd $(TEXTURE) && $(MAKE))
	@(cd $(CUBEMAP) && $(MAKE))
	@(cd $(FRAME) && $(MAKE))
	@(cd $(RENDER) && $(MAKE))
	@(cd $(VAO) && $(MAKE))

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
