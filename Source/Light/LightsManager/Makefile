SRC = NRE_LightsManager.cpp
OBJ = $(OBJDIR)NRE_LightsManager.o
OBJDIR = ../../../obj/Debug/Light/LightsManager/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
