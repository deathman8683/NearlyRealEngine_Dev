SRC = NRE_RegionsManager.cpp
OBJ = $(OBJDIR)NRE_RegionsManager.o
OBJDIR = ../../../../obj/Debug/World/Region/RegionsManager/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
