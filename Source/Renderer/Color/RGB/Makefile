SRC = NRE_RGB.cpp NRE_RGBA.cpp
OBJ = $(OBJDIR)NRE_RGB.o $(OBJDIR)NRE_RGBA.o
OBJDIR = ../../../../obj/Debug/Renderer/Color/RGB/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
