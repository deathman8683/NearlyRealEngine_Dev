SRC = NRE_ArrayOperation.cpp
OBJ = $(OBJDIR)NRE_ArrayOperation.o
OBJDIR = ../../../obj/Debug/Generic/Array/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
