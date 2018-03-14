SRC = NRE_FBO.cpp
OBJ = $(OBJDIR)NRE_FBO.o
OBJDIR = ../../../../obj/Debug/GL_Wrapper/BufferObject/FBO/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
