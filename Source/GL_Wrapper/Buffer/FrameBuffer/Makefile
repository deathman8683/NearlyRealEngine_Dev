SRC = NRE_FrameBuffer.cpp
OBJ = $(OBJDIR)NRE_FrameBuffer.o
OBJDIR = ../../../../obj/Debug/GL_Wrapper/Buffer/FrameBuffer/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
