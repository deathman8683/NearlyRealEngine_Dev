SRC = NRE_MaterialsManager.cpp
OBJ = $(OBJDIR)NRE_MaterialsManager.o
OBJDIR = ../../../../obj/Debug/Renderer/Material/MaterialsManager/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
