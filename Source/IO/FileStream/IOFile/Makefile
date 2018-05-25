SRC = NRE_IOFile.cpp
OBJ = $(OBJDIR)NRE_IOFile.o
OBJDIR = ../../../../obj/Debug/IO/FileStream/IOFile/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
