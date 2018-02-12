SRC = NRE_Viewport.cpp
OBJ = $(OBJDIR)NRE_Viewport.o
OBJDIR = ../../../obj/Debug/Support/Viewport/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
