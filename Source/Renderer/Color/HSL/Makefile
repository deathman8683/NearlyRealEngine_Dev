SRC = NRE_HSL.cpp NRE_HSLA.cpp
OBJ = $(OBJDIR)NRE_HSL.o $(OBJDIR)NRE_HSLA.o
OBJDIR = ../../../../obj/Debug/Renderer/Color/HSL/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
