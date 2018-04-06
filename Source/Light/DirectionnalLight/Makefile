SRC = NRE_DirectionnalLight.cpp
OBJ = $(OBJDIR)NRE_DirectionnalLight.o
OBJDIR = ../../../obj/Debug/Light/DirectionnalLight/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
