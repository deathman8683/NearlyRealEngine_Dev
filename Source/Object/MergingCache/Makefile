SRC = NRE_MergingCache.cpp
OBJ = $(OBJDIR)NRE_MergingCache.o
OBJDIR = ../../../obj/Debug/Object/MergingCache/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
