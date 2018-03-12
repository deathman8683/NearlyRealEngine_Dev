SRC = NRE_Texture.cpp
OBJ = $(OBJDIR)NRE_Texture.o
OBJDIR = ../../../obj/Debug/GL_Wrapper/Texture/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
