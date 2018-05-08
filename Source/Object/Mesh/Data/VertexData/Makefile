SRC = NRE_VertexData.cpp
OBJ = $(OBJDIR)NRE_VertexData.o
OBJDIR = ../../../../../obj/Debug/Object/Mesh/Data/VertexData/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
