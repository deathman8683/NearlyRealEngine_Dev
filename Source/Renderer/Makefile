COLOR = Color
SHADER = Shader
SSAO = SSAO
MATERIAL = Material
DEFERRED = DeferredRenderer

all : $(TARGET)

debug:
	@(cd $(COLOR) && $(MAKE))
	@(cd $(SHADER) && $(MAKE))
	@(cd $(SSAO) && $(MAKE))
	@(cd $(MATERIAL) && $(MAKE))
	@(cd $(DEFERRED) && $(MAKE))
