SRC = NRE_DataSet.cpp
OBJ = $(OBJDIR)NRE_DataSet.o
OBJDIR = ../../../../obj/Debug/Object/Mesh/DataSet/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
