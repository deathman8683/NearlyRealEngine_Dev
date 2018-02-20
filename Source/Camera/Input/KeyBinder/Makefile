SRC = NRE_KeyBinder.cpp
OBJ = $(OBJDIR)NRE_KeyBinder.o
OBJDIR = ../../../../obj/Debug/Camera/Input/KeyBinder/

KEY = Key

all : before $(TARGET)

before:
	@(cd $(KEY) && $(MAKE))

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
