SRC = NRE_MoveableCamera.cpp
OBJ = $(OBJDIR)NRE_MoveableCamera.o
OBJDIR = ../../obj/Debug/Camera/

INPUT = Input
FIXEDCAMERA = FixedCamera

all : before $(TARGET)

before:
	@(cd $(INPUT) && $(MAKE))
	@(cd $(FIXEDCAMERA) && $(MAKE))

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
