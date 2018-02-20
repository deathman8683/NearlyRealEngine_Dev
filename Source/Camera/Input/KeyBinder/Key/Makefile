SRC = NRE_Key.cpp
OBJ = $(OBJDIR)NRE_Key.o
OBJDIR = ../../../../../obj/Debug/Camera/Input/KeyBinder/Key/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
