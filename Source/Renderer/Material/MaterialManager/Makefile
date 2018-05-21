SRC = NRE_MaterialManager.cpp
OBJ = $(OBJDIR)NRE_MaterialManager.o
OBJDIR = ../../../../obj/Debug/Renderer/Material/MaterialManager/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
