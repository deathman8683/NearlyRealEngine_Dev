SRC = NRE_BufferObject.cpp
OBJ = $(OBJDIR)NRE_BufferObject.o
OBJDIR = ../../../obj/Debug/GL_Wrapper/BufferObject/

NBO = NBO
VBO = VBO
TBO = TBO
IBO = IBO

all : $(TARGET) after

after:
	@(cd $(NBO) && $(MAKE))
	@(cd $(VBO) && $(MAKE))
	@(cd $(TBO) && $(MAKE))
	@(cd $(IBO) && $(MAKE))

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
