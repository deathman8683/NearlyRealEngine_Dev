SRC = NRE_Texture2DArray.cpp
OBJ = $(OBJDIR)NRE_Texture2DArray.o
OBJDIR = ../../../../obj/Debug/GL_Wrapper/BufferObject/Texture2DArray/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
