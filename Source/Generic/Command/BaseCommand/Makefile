SRC = NRE_BaseCommand.cpp
OBJ = $(OBJDIR)NRE_BaseCommand.o
OBJDIR = ../../../../obj/Debug/Generic/Command/BaseCommand/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
