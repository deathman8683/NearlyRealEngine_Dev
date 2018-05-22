SRC = NRE_TangentData.cpp
OBJ = $(OBJDIR)NRE_TangentData.o
OBJDIR = ../../../../../obj/Debug/Object/Mesh/Data/TangentData/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
