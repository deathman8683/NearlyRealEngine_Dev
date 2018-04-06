SRC = NRE_SpotLight.cpp
OBJ = $(OBJDIR)NRE_SpotLight.o
OBJDIR = ../../../obj/Debug/Light/SpotLight/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
