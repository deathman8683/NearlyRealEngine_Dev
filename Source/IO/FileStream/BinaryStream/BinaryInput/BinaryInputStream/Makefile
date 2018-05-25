SRC = NRE_BinaryInputStream.cpp
OBJ = $(OBJDIR)NRE_BinaryInputStream.o
OBJDIR = ../../../../../../obj/Debug/IO/FileStream/BinaryStream/BinaryInput/BinaryInputStream/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
