SRC = NRE_ColorData.cpp
OBJ = $(OBJDIR)NRE_ColorData.o
OBJDIR = ../../../../../obj/Debug/Object/Mesh/Data/ColorData/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
