SRC = NRE_Region.cpp
OBJ = $(OBJDIR)NRE_Region.o
OBJDIR = ../../../obj/Debug/World/Region/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
