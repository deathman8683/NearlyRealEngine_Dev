SRC = NRE_RenderBuffer.cpp
OBJ = $(OBJDIR)NRE_RenderBuffer.o
OBJDIR = ../../../../obj/Debug/GL_Wrapper/Buffer/RenderBuffer/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
