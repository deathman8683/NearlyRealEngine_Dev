SRC = NRE_BinaryIOFile.cpp
OBJ = $(OBJDIR)NRE_BinaryIOFile.o
OBJDIR = ../../../../../obj/Debug/IO/FileStream/BinaryStream/BinaryIOFile/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
