SRC = NRE_BufferObject.cpp
OBJ = $(OBJDIR)NRE_BufferObject.o
OBJDIR = ../../../obj/Debug/GL_Wrapper/BufferObject/

BUFFER = Buffer
VBO = VBO
IBO = IBO

all : $(TARGET) after

after:
	@(cd $(BUFFER) && $(MAKE))
	@(cd $(VBO) && $(MAKE))
	@(cd $(IBO) && $(MAKE))

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
