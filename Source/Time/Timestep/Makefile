SRC = NRE_Timestep.cpp
OBJ = $(OBJDIR)NRE_Timestep.o
OBJDIR = ../../../obj/Debug/Time/Timestep/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
