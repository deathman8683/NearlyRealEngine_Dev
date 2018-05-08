VERTEX = VertexData
INDEX = IndexData
MATERIAL = MaterialData
NORMAL = NormalData
DATASET = DataSet

all : before $(TARGET)

before:
	@(cd $(DATASET) && $(MAKE))

debug:
	@(cd $(VERTEX) && $(MAKE))
	@(cd $(INDEX) && $(MAKE))
	@(cd $(MATERIAL) && $(MAKE))
	@(cd $(NORMAL) && $(MAKE))
