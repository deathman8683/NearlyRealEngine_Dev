SRC = NRE_FileNotOpeningException.cpp
OBJ = $(OBJDIR)NRE_FileNotOpeningException.o
OBJDIR = ../../../../obj/Debug/Exception/IOException/FileNotOpeningException/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
