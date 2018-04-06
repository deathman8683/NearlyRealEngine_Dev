SRC = NRE_PointLight.cpp
OBJ = $(OBJDIR)NRE_PointLight.o
OBJDIR = ../../../obj/Debug/Light/PointLight/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
