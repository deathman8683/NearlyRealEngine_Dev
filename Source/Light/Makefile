SRC = NRE_Light.cpp
OBJ = $(OBJDIR)NRE_Light.o
OBJDIR = ../../obj/Debug/Light/

POINT = PointLight
SPOT = SpotLight
DIRECTIONNAL = DirectionnalLight
ENGINE = LightsManager

all : $(TARGET) after

after:
	@(cd $(POINT) && $(MAKE))
	@(cd $(SPOT) && $(MAKE))
	@(cd $(DIRECTIONNAL) && $(MAKE))
	@(cd $(ENGINE) && $(MAKE))

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
