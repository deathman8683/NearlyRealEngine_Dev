SRC = NRE_Application.cpp
OBJ = $(OBJDIR)NRE_Application.o
OBJDIR = ../../../obj/Debug/Support/Application/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
