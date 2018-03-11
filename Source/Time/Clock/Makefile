SRC = NRE_Clock.cpp
OBJ = $(OBJDIR)NRE_Clock.o
OBJDIR = ../../../obj/Debug/Time/Clock/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
