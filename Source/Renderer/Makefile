COLOR = Color
SHADER = Shader
SSAO = SSAO
MATERIAL = Material
ENVIRONMENT = EnvironmentMap
DEFERRED = DeferredRenderer

all : $(TARGET)

debug:
	@(cd $(COLOR) && $(MAKE))
	@(cd $(SHADER) && $(MAKE))
	@(cd $(SSAO) && $(MAKE))
	@(cd $(MATERIAL) && $(MAKE))
	@(cd $(ENVIRONMENT) && $(MAKE))
	@(cd $(DEFERRED) && $(MAKE))
