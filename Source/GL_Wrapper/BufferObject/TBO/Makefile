SRC = NRE_TBO.cpp
OBJ = $(OBJDIR)NRE_TBO.o
OBJDIR = ../../../../obj/Debug/GL_Wrapper/BufferObject/TBO/

BUFFER = Buffer

all : before $(TARGET)

before:
	@(cd $(BUFFER) && $(MAKE))

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
