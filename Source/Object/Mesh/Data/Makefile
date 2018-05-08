VERTEX = VertexData
DATASET = DataSet

all : before $(TARGET)

before:
	@(cd $(DATASET) && $(MAKE))

debug:
	@(cd $(VERTEX) && $(MAKE))
