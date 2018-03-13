SRC = NRE_ArrayBuffer.cpp
OBJ = $(OBJDIR)NRE_ArrayBuffer.o
OBJDIR = ../../../../../obj/Debug/GL_Wrapper/Buffer/AttributeBuffer/ArrayBuffer

COLOR = ColorBuffer
NORMAL = NormalBuffer
UV = UVBuffer
VERTEX = VertexBuffer

all : $(TARGET) after

after:
	@(cd $(VERTEX) && $(MAKE))
	@(cd $(COLOR) && $(MAKE))
	@(cd $(NORMAL) && $(MAKE))
	@(cd $(UV) && $(MAKE))

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
