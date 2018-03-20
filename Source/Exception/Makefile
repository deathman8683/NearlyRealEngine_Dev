SRC = NRE_ExceptionHandler.cpp
OBJ = $(OBJDIR)NRE_ExceptionHandler.o
OBJDIR = ../../obj/Debug/Exception/

SHADER = ShaderException

all : $(TARGET) after

after:
	@(cd $(SHADER) && $(MAKE))

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
