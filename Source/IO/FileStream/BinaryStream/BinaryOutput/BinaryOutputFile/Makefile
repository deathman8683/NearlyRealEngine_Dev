SRC = NRE_BinaryOutputFile.cpp
OBJ = $(OBJDIR)NRE_BinaryOutputFile.o
OBJDIR = ../../../../../../obj/Debug/IO/FileStream/BinaryStream/BinaryOutput/BinaryOutputFile/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
