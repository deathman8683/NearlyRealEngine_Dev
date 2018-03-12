SRC = NRE_IVBO.cpp
OBJ = $(OBJDIR)NRE_IVBO.o
OBJDIR = ../../../../../obj/Debug/GL_Wrapper/BufferObject/IBO/IVBO/

all : $(TARGET)

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
