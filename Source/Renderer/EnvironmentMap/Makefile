SRC = NRE_EnvironmentMap.cpp
OBJ = $(OBJDIR)NRE_EnvironmentMap.o
OBJDIR = ../../../obj/Debug/Renderer/EnvironmentMap/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
