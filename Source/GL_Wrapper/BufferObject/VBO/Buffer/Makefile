SRC = NRE_Buffer.cpp
OBJ = $(OBJDIR)NRE_Buffer.o
OBJDIR = ../../../../../obj/Debug/GL_Wrapper/BufferObject/VBO/Buffer/

VERTEX = Vertex
COLOR = Color
NORMAL = Normal

all : $(TARGET) after

after:
	@(cd $(VERTEX) && $(MAKE))
	@(cd $(COLOR) && $(MAKE))
	@(cd $(NORMAL) && $(MAKE))

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
