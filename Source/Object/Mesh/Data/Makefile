IVERTEX = IntVertexData
FVERTEX = FloatVertexData
INDEX = IndexData
MATERIAL = MaterialData
NORMAL = NormalData
TANGENT = TangentData
UV = UVData
COLOR = ColorData
DATASET = DataSet

all : before $(TARGET)

before:
	@(cd $(DATASET) && $(MAKE))

debug:
	@(cd $(IVERTEX) && $(MAKE))
	@(cd $(FVERTEX) && $(MAKE))
	@(cd $(INDEX) && $(MAKE))
	@(cd $(MATERIAL) && $(MAKE))
	@(cd $(NORMAL) && $(MAKE))
	@(cd $(TANGENT) && $(MAKE))
	@(cd $(UV) && $(MAKE))
	@(cd $(COLOR) && $(MAKE))
