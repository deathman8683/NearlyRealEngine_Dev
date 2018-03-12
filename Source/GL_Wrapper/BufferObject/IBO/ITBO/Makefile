SRC = NRE_ITBO.cpp
OBJ = $(OBJDIR)NRE_ITBO.o
OBJDIR = ../../../../../obj/Debug/GL_Wrapper/BufferObject/IBO/ITBO/

all : $(TARGET)

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
