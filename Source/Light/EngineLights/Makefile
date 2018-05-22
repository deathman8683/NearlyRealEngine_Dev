SRC = NRE_EngineLights.cpp
OBJ = $(OBJDIR)NRE_EngineLights.o
OBJDIR = ../../../obj/Debug/Light/EngineLights/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
