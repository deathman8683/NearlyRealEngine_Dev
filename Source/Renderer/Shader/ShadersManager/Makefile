SRC = NRE_ShadersManager.cpp
OBJ = $(OBJDIR)NRE_ShadersManager.o
OBJDIR = ../../../../obj/Debug/Renderer/Shader/ShadersManager/

BRDF = BRDF
CAPTURE = Capture
GBUFFER = GBuffer
IRRADIANCE = Irradiance
PBR = PBR
PREFILTER = Prefilter
SKYBOX = SkyBox
SSAO = SSAO

all : before $(TARGET)

before:
	@(cd $(BRDF) && $(MAKE))
	@(cd $(CAPTURE) && $(MAKE))
	@(cd $(GBUFFER) && $(MAKE))
	@(cd $(IRRADIANCE) && $(MAKE))
	@(cd $(PBR) && $(MAKE))
	@(cd $(PREFILTER) && $(MAKE))
	@(cd $(SKYBOX) && $(MAKE))
	@(cd $(SSAO) && $(MAKE))

debug: $(OBJ)

$(OBJDIR)%.o : %.cpp %.hpp
	@$(CXX) -o $@ -c $< $(CFLAGS) $(INC)
