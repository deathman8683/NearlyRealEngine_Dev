SRC = NRE_Light.cpp
OBJ = $(OBJDIR)NRE_Light.o
OBJDIR = ../../obj/Debug/Light/

POINT = PointLight
DIRECTIONNAL = DirectionnalLight

all : $(TARGET) after

after:
	@(cd $(POINT) && $(MAKE))
	@(cd $(DIRECTIONNAL) && $(MAKE))

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
