SRC = NRE_Scene.cpp
OBJ = $(OBJDIR)NRE_Scene.o
OBJDIR = ../../../obj/Debug/Support/Scene/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
