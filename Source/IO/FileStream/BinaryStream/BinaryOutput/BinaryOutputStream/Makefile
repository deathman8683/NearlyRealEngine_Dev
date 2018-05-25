SRC = NRE_BinaryOutputStream.cpp
OBJ = $(OBJDIR)NRE_BinaryOutputStream.o
OBJDIR = ../../../../../../obj/Debug/IO/FileStream/BinaryStream/BinaryOutput/BinaryOutputStream/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
