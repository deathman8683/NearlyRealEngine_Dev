SRC = NRE_DeferredRenderer.cpp
OBJ = $(OBJDIR)NRE_DeferredRenderer.o
OBJDIR = ../../../obj/Debug/Renderer/DeferredRenderer/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
