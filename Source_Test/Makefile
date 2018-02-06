SRC = NRET_Main.cpp
OBJ = $(OBJDIR)NRET_Main.o
OBJDIR = ../obj/Test/

all : $(TARGET)

test : $(OBJ)

$(OBJDIR)%.o : %.cpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
