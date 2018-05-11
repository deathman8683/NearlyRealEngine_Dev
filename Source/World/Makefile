SRC = NRE_World.cpp
OBJ = $(OBJDIR)NRE_World.o
OBJDIR = ../../obj/Debug/World/

VOXEL = Voxel
CHUNK = Chunk
REGION = Region
CONSTRUCTOR = ChunkConstructor

all : before $(TARGET) after

before:
	@(cd $(VOXEL) && $(MAKE))
	@(cd $(CHUNK) && $(MAKE))
	@(cd $(REGION) && $(MAKE))

after:
	@(cd $(CONSTRUCTOR) && $(MAKE))

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
