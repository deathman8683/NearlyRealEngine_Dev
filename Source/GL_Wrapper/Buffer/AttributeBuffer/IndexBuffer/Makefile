SRC = NRE_IndexBuffer.cpp
OBJ = $(OBJDIR)NRE_IndexBuffer.o
OBJDIR = ../../../../../obj/Debug/GL_Wrapper/Buffer/AttributeBuffer/IndexBuffer/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
