SRC = NRE_GLException.cpp
OBJ = $(OBJDIR)NRE_GLException.o
OBJDIR = ../../../obj/Debug/Exception/GLException/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
