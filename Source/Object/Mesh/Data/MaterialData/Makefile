SRC = NRE_MaterialData.cpp
OBJ = $(OBJDIR)NRE_MaterialData.o
OBJDIR = ../../../../../obj/Debug/Object/Mesh/Data/MaterialData/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
