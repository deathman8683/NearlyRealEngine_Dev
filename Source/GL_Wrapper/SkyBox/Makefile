SRC = NRE_SkyBox.cpp
OBJ = $(OBJDIR)NRE_SkyBox.o
OBJDIR = ../../../obj/Debug/GL_Wrapper/SkyBox/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
