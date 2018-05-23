SRC = NRE_IOException.cpp
OBJ = $(OBJDIR)NRE_IOException.o
OBJDIR = ../../../obj/Debug/Exception/IOException/

EXISTING = FileNotExistingException
OPENING = FileNotOpeningException

all : $(TARGET) after

debug : $(OBJ)

after:
	@(cd $(OPENING) && $(MAKE))
	@(cd $(EXISTING) && $(MAKE))

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
