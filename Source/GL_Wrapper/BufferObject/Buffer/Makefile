SRC = NRE_Buffer.cpp
OBJ = $(OBJDIR)NRE_Buffer.o
OBJDIR = ../../../../obj/Debug/GL_Wrapper/BufferObject/Buffer/

COLOR = Color
INDEX = Index
NORMAL = Normal

all : $(TARGET) after

after:
	@(cd $(COLOR) && $(MAKE))
	@(cd $(INDEX) && $(MAKE))
	@(cd $(NORMAL) && $(MAKE))

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
