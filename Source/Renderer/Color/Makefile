SRC = NRE_ColorConverter.cpp
OBJ = $(OBJDIR)NRE_ColorConverter.o
OBJDIR = ../../../obj/Debug/Renderer/Color/

RGB = RGB
HSL = HSL

all : before $(TARGET)

before:
	@(cd $(RGB) && $(MAKE))
	@(cd $(HSL) && $(MAKE))

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
