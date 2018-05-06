SRC = NRE_Object.cpp
OBJ = $(OBJDIR)NRE_Object.o
OBJDIR = ../../obj/Debug/Object/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
