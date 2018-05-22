SRC = NRE_ArrayBuffer.cpp
OBJ = $(OBJDIR)NRE_ArrayBuffer.o
OBJDIR = ../../../../../obj/Debug/GL_Wrapper/Buffer/AttributeBuffer/ArrayBuffer/

COLOR = ColorBuffer
MATERIAL = MaterialBuffer
NORMAL = NormalBuffer
TANGENT = TangentBuffer
UV = UVBuffer
VERTEX = VertexBuffer

all : $(TARGET) after

after:
	@(cd $(VERTEX) && $(MAKE))
	@(cd $(COLOR) && $(MAKE))
	@(cd $(MATERIAL) && $(MAKE))
	@(cd $(NORMAL) && $(MAKE))
	@(cd $(TANGENT) && $(MAKE))
	@(cd $(UV) && $(MAKE))

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
