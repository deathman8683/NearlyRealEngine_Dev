SRC = NRE_VertexBuffer.cpp
OBJ = $(OBJDIR)NRE_VertexBuffer.o
OBJDIR = ../../../../../../obj/Debug/GL_Wrapper/BufferObject/VBO/Buffer/Vertex/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
