SRC = NRE_OutputStream.cpp
OBJ = $(OBJDIR)NRE_OutputStream.o
OBJDIR = ../../../../../obj/Debug/IO/FileStream/Output/OutputStream/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
