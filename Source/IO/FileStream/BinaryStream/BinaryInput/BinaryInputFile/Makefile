SRC = NRE_BinaryInputFile.cpp
OBJ = $(OBJDIR)NRE_BinaryInputFile.o
OBJDIR = ../../../../../../obj/Debug/IO/FileStream/BinaryStream/BinaryInput/BinaryInputFile/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
