SRC = NRE_VBO.cpp
OBJ = $(OBJDIR)NRE_VBO.o
OBJDIR = ../../../../obj/Debug/GL_Wrapper/BufferObject/VBO/

BUFFER = Buffer

all : before $(TARGET)

before:
	@(cd $(BUFFER) && $(MAKE))

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
