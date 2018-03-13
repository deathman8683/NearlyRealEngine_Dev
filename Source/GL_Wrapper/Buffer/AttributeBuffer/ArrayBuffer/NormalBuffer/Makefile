SRC = NRE_NormalBuffer.cpp
OBJ = $(OBJDIR)NRE_NormalBuffer.o
OBJDIR = ../../../../../../obj/Debug/GL_Wrapper/Buffer/AttributeBuffer/ArrayBuffer/NormalBuffer

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
