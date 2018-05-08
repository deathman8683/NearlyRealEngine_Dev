SRC = NRE_NormalData.cpp
OBJ = $(OBJDIR)NRE_NormalData.o
OBJDIR = ../../../../../obj/Debug/Object/Mesh/Data/NormalData/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
