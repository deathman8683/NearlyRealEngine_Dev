SRC = NRE_UVData.cpp
OBJ = $(OBJDIR)NRE_UVData.o
OBJDIR = ../../../../../obj/Debug/Object/Mesh/Data/UVData/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
