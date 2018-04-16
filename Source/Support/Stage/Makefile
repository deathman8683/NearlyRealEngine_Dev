SRC = NRE_Stage.cpp
OBJ = $(OBJDIR)NRE_Stage.o
OBJDIR = ../../../obj/Debug/Support/Stage/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
