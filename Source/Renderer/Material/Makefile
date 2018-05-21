SRC = NRE_Material.cpp
OBJ = $(OBJDIR)NRE_Material.o
OBJDIR = ../../../obj/Debug/Renderer/Material/

MANAGER = MaterialManager

all : $(TARGET) after

debug : $(OBJ)

after:
	@(cd $(MANAGER) && $(MAKE))

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
