SRC = FastNoise.cpp
OBJ = $(OBJDIR)FastNoise.o
OBJDIR = ../../../obj/Debug/lib/FastNoise/

all : $(TARGET)

debug: $(OBJ)
	
$(OBJDIR)%.o : %.cpp %.h
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
	