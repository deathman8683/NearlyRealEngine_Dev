SRC = NRE_NBO.cpp
OBJ = $(OBJDIR)NRE_NBO.o
OBJDIR = ../../../../obj/Debug/GL_Wrapper/BufferObject/NBO/

BUFFER = Buffer

all : before $(TARGET)

before:
	@(cd $(BUFFER) && $(MAKE))

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
