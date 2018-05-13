SRC = NRE_IntVertexData.cpp
OBJ = $(OBJDIR)NRE_IntVertexData.o
OBJDIR = ../../../../../obj/Debug/Object/Mesh/Data/IntVertexData/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
