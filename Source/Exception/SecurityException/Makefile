SRC = NRE_SecurityException.cpp
OBJ = $(OBJDIR)NRE_SecurityException.o
OBJDIR = ../../../obj/Debug/Exception/SecurityException/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
