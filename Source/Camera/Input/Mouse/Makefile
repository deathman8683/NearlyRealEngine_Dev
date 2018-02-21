SRC = NRE_Mouse.cpp
OBJ = $(OBJDIR)NRE_Mouse.o
OBJDIR = ../../../../obj/Debug/Camera/Input/Mouse/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
