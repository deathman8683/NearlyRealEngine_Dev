SRC = NRE_Region.cpp
OBJ = $(OBJDIR)NRE_Region.o
OBJDIR = ../../../obj/Debug/World/Region/

MANAGER = RegionsManager

all : $(TARGET) after

debug : $(OBJ)

after:
	@(cd $(MANAGER) && $(MAKE))

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
