SRC = NRE_Mesh.cpp
OBJ = $(OBJDIR)NRE_Mesh.o
OBJDIR = ../../../obj/Debug/Object/Mesh/

DATASET = DataSet

all : before $(TARGET)

before:
	@(cd $(DATASET) && $(MAKE))

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
