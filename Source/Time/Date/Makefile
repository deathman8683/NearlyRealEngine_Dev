SRC = NRE_Date.cpp
OBJ = $(OBJDIR)NRE_Date.o
OBJDIR = ../../../obj/Debug/Time/Date/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
