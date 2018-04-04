SRC = NRE_Material.cpp
OBJ = $(OBJDIR)NRE_Material.o
OBJDIR = ../../../obj/Debug/Renderer/Material/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
