SRC = NRE_AdvancedDate.cpp
OBJ = $(OBJDIR)NRE_AdvancedDate.o
OBJDIR = ../../../obj/Debug/Time/AdvancedDate/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
