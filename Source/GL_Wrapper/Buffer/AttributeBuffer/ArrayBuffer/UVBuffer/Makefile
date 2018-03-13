SRC = NRE_UVBuffer.cpp
OBJ = $(OBJDIR)NRE_UVBuffer.o
OBJDIR = ../../../../../../obj/Debug/GL_Wrapper/Buffer/AttributeBuffer/ArrayBuffer/UVBuffer/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
