SRC = NRE_VAO.cpp
OBJ = $(OBJDIR)NRE_VAO.o
OBJDIR = ../../../../obj/Debug/GL_Wrapper/Buffer/VAO/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
