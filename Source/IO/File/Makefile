SRC = NRE_File.cpp
OBJ = $(OBJDIR)NRE_File.o
OBJDIR = ../../../obj/Debug/IO/File/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
