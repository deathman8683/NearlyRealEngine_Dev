SRC = NRE_FloatVertexData.cpp
OBJ = $(OBJDIR)NRE_FloatVertexData.o
OBJDIR = ../../../../../obj/Debug/Object/Mesh/Data/FloatVertexData/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
