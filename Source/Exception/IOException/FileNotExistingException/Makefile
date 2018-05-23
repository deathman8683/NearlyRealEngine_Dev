SRC = NRE_FileNotExistingException.cpp
OBJ = $(OBJDIR)NRE_FileNotExistingException.o
OBJDIR = ../../../../obj/Debug/Exception/IOException/FileNotExistingException/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
