SRC = NRE_MaterialBuffer.cpp
OBJ = $(OBJDIR)NRE_MaterialBuffer.o
OBJDIR = ../../../../../../obj/Debug/GL_Wrapper/Buffer/AttributeBuffer/ArrayBuffer/MaterialBuffer/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
