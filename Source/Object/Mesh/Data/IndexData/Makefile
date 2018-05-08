SRC = NRE_IndexData.cpp
OBJ = $(OBJDIR)NRE_IndexData.o
OBJDIR = ../../../../../obj/Debug/Object/Mesh/Data/IndexData/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
