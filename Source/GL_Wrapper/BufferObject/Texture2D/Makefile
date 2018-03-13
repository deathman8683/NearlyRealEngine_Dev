SRC = NRE_Texture2D.cpp
OBJ = $(OBJDIR)NRE_Texture2D.o
OBJDIR = ../../../../obj/Debug/GL_Wrapper/BufferObject/Texture2D/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
