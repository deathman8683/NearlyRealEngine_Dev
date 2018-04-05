SRC = NRE_DepthBuffer.cpp
OBJ = $(OBJDIR)NRE_DepthBuffer.o
OBJDIR = ../../../../obj/Debug/GL_Wrapper/Buffer/DepthBuffer/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
