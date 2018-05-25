SRC = NRE_InputStream.cpp
OBJ = $(OBJDIR)NRE_InputStream.o
OBJDIR = ../../../../../obj/Debug/IO/FileStream/Input/InputStream/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
