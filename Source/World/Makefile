SRC = NRE_World.cpp
OBJ = $(OBJDIR)NRE_World.o
OBJDIR = ../../obj/Debug/World/

VOXEL = Voxel
CHUNK = Chunk
REGION = Region

all : before $(TARGET)

before:
	@(cd $(VOXEL) && $(MAKE))
	@(cd $(CHUNK) && $(MAKE))
	@(cd $(REGION) && $(MAKE))

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
