SRC = NRE_UVBuffer.cpp
OBJ = $(OBJDIR)NRE_UVBuffer.o
OBJDIR = ../../../../../../obj/Debug/GL_Wrapper/BufferObject/TBO/Buffer/UV/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
