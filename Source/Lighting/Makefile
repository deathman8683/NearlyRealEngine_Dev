SRC = NRE_Light.cpp
OBJ = $(OBJDIR)NRE_Light.o
OBJDIR = ../../obj/Debug/Lighting/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
