SRC = NRE_TangentBuffer.cpp
OBJ = $(OBJDIR)NRE_TangentBuffer.o
OBJDIR = ../../../../../../obj/Debug/GL_Wrapper/Buffer/AttributeBuffer/ArrayBuffer/TangentBuffer/

all : $(TARGET)

debug : $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
