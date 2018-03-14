SRC = NRE_BufferObject.cpp
OBJ = $(OBJDIR)NRE_BufferObject.o
OBJDIR = ../../../obj/Debug/GL_Wrapper/BufferObject/

VBO = VBO
IBO = IBO
TEXTURE2D = Texture2D
SKYBOX = SkyBox
FBO = FBO

all : $(TARGET) after

after:
	@(cd $(VBO) && $(MAKE))
	@(cd $(IBO) && $(MAKE))
	@(cd $(TEXTURE2D) && $(MAKE))
	@(cd $(SKYBOX) && $(MAKE))
	@(cd $(FBO) && $(MAKE))

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
