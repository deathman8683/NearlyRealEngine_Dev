SRC = NRE_IBO.cpp
OBJ = $(OBJDIR)NRE_IBO.o
OBJDIR = ../../../../obj/Debug/GL_Wrapper/BufferObject/IBO/

BUFFER = Buffer

all : before $(TARGET)

before:
	@(cd $(BUFFER) && $(MAKE))

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
