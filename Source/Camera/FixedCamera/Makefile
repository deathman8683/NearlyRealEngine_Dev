SRC = NRE_FixedCamera.cpp
OBJ = $(OBJDIR)NRE_FixedCamera.o
OBJDIR = ../../../obj/Debug/Camera/FixedCamera/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
