SRC = NRE_IOException.cpp
OBJ = $(OBJDIR)NRE_IOException.o
OBJDIR = ../../../obj/Debug/Exception/IOException/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
