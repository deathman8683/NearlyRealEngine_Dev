SRC = NRE_AttributeBuffer.cpp
OBJ = $(OBJDIR)NRE_AttributeBuffer.o
OBJDIR = ../../../../obj/Debug/GL_Wrapper/Buffer/AttributeBuffer

ARRAY = ArrayBuffer
INDEX = IndexBuffer

all : $(TARGET) after

after:
	@(cd $(ARRAY) && $(MAKE))
	@(cd $(INDEX) && $(MAKE))

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
