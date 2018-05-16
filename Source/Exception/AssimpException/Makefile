SRC = NRE_AssimpException.cpp
OBJ = $(OBJDIR)NRE_AssimpException.o
OBJDIR = ../../../obj/Debug/Exception/AssimpException/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
