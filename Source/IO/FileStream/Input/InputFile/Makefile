SRC = NRE_InputFile.cpp
OBJ = $(OBJDIR)NRE_InputFile.o
OBJDIR = ../../../../../obj/Debug/IO/FileStream/Input/InputFile/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
