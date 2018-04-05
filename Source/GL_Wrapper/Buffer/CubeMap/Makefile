SRC = NRE_CubeMap.cpp
OBJ = $(OBJDIR)NRE_CubeMap.o
OBJDIR = ../../../../obj/Debug/GL_Wrapper/Buffer/CubeMap/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
