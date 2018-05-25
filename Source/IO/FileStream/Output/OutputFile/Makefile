SRC = NRE_OutputFile.cpp
OBJ = $(OBJDIR)NRE_OutputFile.o
OBJDIR = ../../../../../obj/Debug/IO/FileStream/Output/OutputFile/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
