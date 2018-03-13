SRC = NRE_IBO.cpp
OBJ = $(OBJDIR)NRE_IBO.o
OBJDIR = ../../../../obj/Debug/GL_Wrapper/BufferObject/IBO/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
