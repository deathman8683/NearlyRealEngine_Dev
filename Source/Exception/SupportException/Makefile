SRC = NRE_SupportException.cpp
OBJ = $(OBJDIR)NRE_SupportException.o
OBJDIR = ../../../obj/Debug/Exception/SupportException/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
