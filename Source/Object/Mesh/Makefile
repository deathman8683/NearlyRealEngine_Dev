SRC = NRE_Mesh.cpp
OBJ = $(OBJDIR)NRE_Mesh.o
OBJDIR = ../../../obj/Debug/Object/Mesh/

DATA = Data

all : before $(TARGET)

before:
	@(cd $(DATA) && $(MAKE))

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
