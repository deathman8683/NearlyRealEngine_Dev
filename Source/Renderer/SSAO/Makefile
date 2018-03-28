SRC = NRE_SSAO.cpp
OBJ = $(OBJDIR)NRE_SSAO.o
OBJDIR = ../../../obj/Debug/Renderer/SSAO/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
