SRC = NRE_BufferObject.cpp
OBJ = $(OBJDIR)NRE_BufferObject.o
OBJDIR = ../../../obj/Debug/GL_Wrapper/BufferObject/

VBO = VBO

all : $(TARGET) after

after:
	@(cd $(VBO) && $(MAKE))

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
