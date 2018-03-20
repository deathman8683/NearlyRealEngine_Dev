SRC = NRE_ShaderException.cpp
OBJ = $(OBJDIR)NRE_ShaderException.o
OBJDIR = ../../../obj/Debug/Exception/ShaderException/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
