export CXX = g++.exe
export LD = g++.exe

export CFLAGS = -Wall -std=c++14
export LDFLAGS = -lopengl32 -lglu32

export INC = -I"C:\lib\TDM-GCC-64\include" -I"C:\lib\Glew\include" -I"C:\lib\GLM" -I"C:\lib\SDL2-2.0.8\x86_64-w64-mingw32\include" -I"C:\lib\STB" -I"C:\lib\Assimp-3.1.1\include"
export LIBDIR = -L"C:\lib\TDM-GCC-64\lib" -L"C:\lib\Glew\lib" -L"C:\lib\SDL2-2.0.8\x86_64-w64-mingw32\lib" -L"C:\lib\Assimp\build\code"
export LIB = "C:\lib\TDM-GCC-64\x86_64-w64-mingw32\lib\libmingw32.a" "C:\lib\Glew\lib\libglew32.dll.a" "C:\lib\SDL2-2.0.8\x86_64-w64-mingw32\lib\libSDL2main.a" "C:\lib\SDL2-2.0.8\x86_64-w64-mingw32\lib\libSDL2.dll.a" "C:\lib\SDL2-2.0.8\x86_64-w64-mingw32\lib\libSDL2_image.dll.a" "C:\lib\Assimp-3.1.1\build\code\libassimp.dll.a"

export TARGET = debug

ifeq ($(TARGET), debug)
	OBJDIR = obj/Debug/
	BIN = bin/Debug/
	SOURCE = Source
	OBJ = $(OBJDIR)Maths/NRE_Maths.o $(OBJDIR)Generic/Command/BaseCommand/NRE_BaseCommand.o $(OBJDIR)Generic/Array/NRE_ArrayOperation.o $(OBJDIR)Generic/Init/NRE_Init.o $(OBJDIR)Exception/NRE_ExceptionHandler.o $(OBJDIR)Exception/ShaderException/NRE_ShaderException.o $(OBJDIR)Exception/SupportException/NRE_SupportException.o $(OBJDIR)Exception/SDLException/NRE_SDLException.o $(OBJDIR)Exception/GLException/NRE_GLException.o $(OBJDIR)Exception/IOException/NRE_IOException.o $(OBJDIR)Exception/AssimpException/NRE_AssimpException.o $(OBJDIR)lib/FastNoise/FastNoise.o $(OBJDIR)SDL_Wrapper/Window/NRE_Window.o $(OBJDIR)SDL_Wrapper/Event/NRE_Event.o $(OBJDIR)SDL_Wrapper/PixelFormat/NRE_PixelFormat.o $(OBJDIR)SDL_Wrapper/Surface/NRE_Surface.o $(OBJDIR)GL_Wrapper/Buffer/NRE_Buffer.o $(OBJDIR)GL_Wrapper/Buffer/AttributeBuffer/NRE_AttributeBuffer.o $(OBJDIR)GL_Wrapper/Buffer/AttributeBuffer/ArrayBuffer/NRE_ArrayBuffer.o $(OBJDIR)GL_Wrapper/Buffer/AttributeBuffer/ArrayBuffer/VertexBuffer/NRE_VertexBuffer.o $(OBJDIR)GL_Wrapper/Buffer/AttributeBuffer/ArrayBuffer/ColorBuffer/NRE_ColorBuffer.o $(OBJDIR)GL_Wrapper/Buffer/AttributeBuffer/ArrayBuffer/MaterialBuffer/NRE_MaterialBuffer.o $(OBJDIR)GL_Wrapper/Buffer/AttributeBuffer/ArrayBuffer/NormalBuffer/NRE_NormalBuffer.o $(OBJDIR)GL_Wrapper/Buffer/AttributeBuffer/ArrayBuffer/TangentBuffer/NRE_TangentBuffer.o $(OBJDIR)GL_Wrapper/Buffer/AttributeBuffer/ArrayBuffer/UVBuffer/NRE_UVBuffer.o $(OBJDIR)GL_Wrapper/Buffer/AttributeBuffer/IndexBuffer/NRE_IndexBuffer.o $(OBJDIR)GL_Wrapper/Buffer/DepthBuffer/NRE_DepthBuffer.o $(OBJDIR)GL_Wrapper/Buffer/TextureBuffer/NRE_TextureBuffer.o $(OBJDIR)GL_Wrapper/Buffer/TextureBuffer/2D/NRE_Texture2DBuffer.o $(OBJDIR)GL_Wrapper/Buffer/TextureBuffer/3D/NRE_Texture3DBuffer.o $(OBJDIR)GL_Wrapper/Buffer/CubeMap/NRE_CubeMap.o $(OBJDIR)GL_Wrapper/Buffer/FrameBuffer/NRE_FrameBuffer.o $(OBJDIR)GL_Wrapper/Buffer/RenderBuffer/NRE_RenderBuffer.o $(OBJDIR)GL_Wrapper/Buffer/VAO/NRE_VAO.o $(OBJDIR)GL_Wrapper/BufferObject/NRE_BufferObject.o $(OBJDIR)GL_Wrapper/BufferObject/VBO/NRE_VBO.o $(OBJDIR)GL_Wrapper/BufferObject/IBO/NRE_IBO.o $(OBJDIR)GL_Wrapper/BufferObject/Texture2D/NRE_Texture2D.o $(OBJDIR)GL_Wrapper/BufferObject/Texture2DArray/NRE_Texture2DArray.o $(OBJDIR)GL_Wrapper/BufferObject/SkyBox/NRE_SkyBox.o $(OBJDIR)GL_Wrapper/BufferObject/FBO/NRE_FBO.o  $(OBJDIR)Object/Mesh/Data/DataSet/NRE_DataSet.o $(OBJDIR)Object/Mesh/Data/IntVertexData/NRE_IntVertexData.o $(OBJDIR)Object/Mesh/Data/FloatVertexData/NRE_FloatVertexData.o $(OBJDIR)Object/Mesh/Data/IndexData/NRE_IndexData.o $(OBJDIR)Object/Mesh/Data/MaterialData/NRE_MaterialData.o $(OBJDIR)Object/Mesh/Data/NormalData/NRE_NormalData.o $(OBJDIR)Object/Mesh/Data/TangentData/NRE_TangentData.o $(OBJDIR)Object/Mesh/Data/UVData/NRE_UVData.o $(OBJDIR)Object/Mesh/Data/ColorData/NRE_ColorData.o $(OBJDIR)Object/MergingCache/NRE_MergingCache.o $(OBJDIR)Object/VoxelSet/NRE_VoxelSet.o $(OBJDIR)Object/Mesh/NRE_Mesh.o $(OBJDIR)Object/Mesh/2D/NRE_Mesh2D.o $(OBJDIR)Object/Mesh/3D/NRE_Mesh3D.o $(OBJDIR)Object/Mesh/3D/VoxelMesh/NRE_VoxelMesh.o $(OBJDIR)Object/NRE_Object.o $(OBJDIR)Object/2D/NRE_Object2D.o $(OBJDIR)Object/3D/NRE_Object3D.o $(OBJDIR)Object/3D/VoxelObject/NRE_VoxelObject.o $(OBJDIR)Time/Timestep/NRE_Timestep.o $(OBJDIR)Time/Date/NRE_Date.o $(OBJDIR)Time/AdvancedDate/NRE_AdvancedDate.o $(OBJDIR)Time/Clock/NRE_Clock.o $(OBJDIR)Renderer/Color/RGB/NRE_RGB.o $(OBJDIR)Renderer/Color/HSL/NRE_HSL.o $(OBJDIR)Renderer/Color/RGB/NRE_RGBA.o $(OBJDIR)Renderer/Color/HSL/NRE_HSLA.o $(OBJDIR)Renderer/Color/NRE_ColorConverter.o $(OBJDIR)Renderer/Shader/ShaderBase/NRE_ShaderBase.o $(OBJDIR)Renderer/Shader/ShaderBase/VertexShader/NRE_VertexShader.o $(OBJDIR)Renderer/Shader/ShaderBase/FragmentShader/NRE_FragmentShader.o $(OBJDIR)Renderer/Shader/ShaderMap/NRE_ShaderMap.o $(OBJDIR)Renderer/Shader/NRE_Shader.o $(OBJDIR)Renderer/Shader/EngineShader/BRDF/NRE_BRDFShader.o $(OBJDIR)Renderer/Shader/EngineShader/Capture/NRE_CaptureShader.o $(OBJDIR)Renderer/Shader/EngineShader/GBuffer/NRE_GBufferShader.o $(OBJDIR)Renderer/Shader/EngineShader/Irradiance/NRE_IrradianceShader.o $(OBJDIR)Renderer/Shader/EngineShader/PBR/NRE_PBRShader.o $(OBJDIR)Renderer/Shader/EngineShader/Prefilter/NRE_PrefilterShader.o $(OBJDIR)Renderer/Shader/EngineShader/SkyBox/NRE_SkyBoxShader.o $(OBJDIR)Renderer/Shader/EngineShader/SSAO/NRE_SSAOShader.o $(OBJDIR)Renderer/Shader/EngineShader/NRE_EngineShader.o $(OBJDIR)Renderer/SSAO/NRE_SSAO.o $(OBJDIR)Renderer/Material/NRE_Material.o $(OBJDIR)Renderer/Material/MaterialManager/NRE_MaterialManager.o $(OBJDIR)Renderer/EnvironmentMap/NRE_EnvironmentMap.o $(OBJDIR)Renderer/DeferredRenderer/NRE_DeferredRenderer.o $(OBJDIR)Light/NRE_Light.o $(OBJDIR)Light/SpotLight/NRE_SpotLight.o $(OBJDIR)Light/DirectionnalLight/NRE_DirectionnalLight.o $(OBJDIR)Light/PointLight/NRE_PointLight.o $(OBJDIR)Camera/Input/KeyBinder/Key/NRE_Key.o $(OBJDIR)Camera/Input/KeyBinder/NRE_KeyBinder.o $(OBJDIR)Camera/Input/Keyboard/NRE_Keyboard.o $(OBJDIR)Camera/Input/EventHandler/NRE_EventHandler.o $(OBJDIR)Camera/Input/Mouse/NRE_Mouse.o $(OBJDIR)Camera/Input/NRE_Input.o $(OBJDIR)Camera/FixedCamera/NRE_FixedCamera.o $(OBJDIR)Camera/NRE_MoveableCamera.o $(OBJDIR)World/Voxel/Type/VoxelType/NRE_VoxelType.o $(OBJDIR)World/Voxel/Type/VoxelType/Type/NRE_Type.o $(OBJDIR)World/Voxel/Type/VoxelTypes/NRE_VoxelTypes.o $(OBJDIR)World/Voxel/VoxelPoint/NRE_VoxelPoint.o $(OBJDIR)World/Voxel/NRE_Voxel.o $(OBJDIR)World/Chunk/NRE_Chunk.o $(OBJDIR)World/Region/NRE_Region.o $(OBJDIR)World/NRE_World.o $(OBJDIR)World/ChunkConstructor/NRE_ChunkConstructor.o $(OBJDIR)Support/Viewport/NRE_Viewport.o $(OBJDIR)Support/Stage/NRE_Stage.o $(OBJDIR)NRE_Main.o

else
	OBJDIR = obj/Test/
	BIN = bin/Test/
	SOURCE = Source_Test
	OBJ = $(OBJDIR)NRET_Main.o

endif

OUT = NearlyRealEngine_Dev

all : before out

before:
	@(cd $(SOURCE) && $(MAKE))

out : $(OBJ)
	@$(LD) $(LIBDIR) -o $(BIN)$(OUT) $^ $(LDFLAGS) $(LIB)
	@echo "Jobs done."

clean :
	@echo "Clear of obj/"
	@rm -r obj
	@mkdir obj
	@mkdir obj/Debug
	@mkdir obj/Debug/Exception
	@mkdir obj/Debug/Exception/ShaderException
	@mkdir obj/Debug/Exception/SupportException
	@mkdir obj/Debug/Exception/SDLException
	@mkdir obj/Debug/Exception/GLException
	@mkdir obj/Debug/Exception/IOException
	@mkdir obj/Debug/Exception/AssimpException
	@mkdir obj/Debug/Generic
	@mkdir obj/Debug/Generic/Array
	@mkdir obj/Debug/Generic/Init
	@mkdir obj/Debug/Generic/Command
	@mkdir obj/Debug/Generic/Command/BaseCommand
	@mkdir obj/Debug/Camera
	@mkdir obj/Debug/Camera/FixedCamera
	@mkdir obj/Debug/Camera/Input
	@mkdir obj/Debug/Camera/Input/EventHandler
	@mkdir obj/Debug/Camera/Input/Keyboard
	@mkdir obj/Debug/Camera/Input/Mouse
	@mkdir obj/Debug/Camera/Input/KeyBinder
	@mkdir obj/Debug/Camera/Input/KeyBinder/Key
	@mkdir obj/Debug/GL_Wrapper
	@mkdir obj/Debug/GL_Wrapper/Buffer
	@mkdir obj/Debug/GL_Wrapper/Buffer/AttributeBuffer
	@mkdir obj/Debug/GL_Wrapper/Buffer/AttributeBuffer/ArrayBuffer
	@mkdir obj/Debug/GL_Wrapper/Buffer/AttributeBuffer/ArrayBuffer/VertexBuffer
	@mkdir obj/Debug/GL_Wrapper/Buffer/AttributeBuffer/ArrayBuffer/ColorBuffer
	@mkdir obj/Debug/GL_Wrapper/Buffer/AttributeBuffer/ArrayBuffer/MaterialBuffer
	@mkdir obj/Debug/GL_Wrapper/Buffer/AttributeBuffer/ArrayBuffer/NormalBuffer
	@mkdir obj/Debug/GL_Wrapper/Buffer/AttributeBuffer/ArrayBuffer/TangentBuffer
	@mkdir obj/Debug/GL_Wrapper/Buffer/AttributeBuffer/ArrayBuffer/UVBuffer
	@mkdir obj/Debug/GL_Wrapper/Buffer/AttributeBuffer/IndexBuffer
	@mkdir obj/Debug/GL_Wrapper/Buffer/DepthBuffer
	@mkdir obj/Debug/GL_Wrapper/Buffer/TextureBuffer
	@mkdir obj/Debug/GL_Wrapper/Buffer/TextureBuffer/2D
	@mkdir obj/Debug/GL_Wrapper/Buffer/TextureBuffer/3D
	@mkdir obj/Debug/GL_Wrapper/Buffer/CubeMap
	@mkdir obj/Debug/GL_Wrapper/Buffer/FrameBuffer
	@mkdir obj/Debug/GL_Wrapper/Buffer/RenderBuffer
	@mkdir obj/Debug/GL_Wrapper/Buffer/VAO
	@mkdir obj/Debug/GL_Wrapper/BufferObject
	@mkdir obj/Debug/GL_Wrapper/BufferObject/VBO
	@mkdir obj/Debug/GL_Wrapper/BufferObject/IBO
	@mkdir obj/Debug/GL_Wrapper/BufferObject/Texture2D
	@mkdir obj/Debug/GL_Wrapper/BufferObject/Texture2DArray
	@mkdir obj/Debug/GL_Wrapper/BufferObject/SkyBox
	@mkdir obj/Debug/GL_Wrapper/BufferObject/FBO
	@mkdir obj/Debug/Object
	@mkdir obj/Debug/Object/2D
	@mkdir obj/Debug/Object/3D
	@mkdir obj/Debug/Object/3D/VoxelObject
	@mkdir obj/Debug/Object/MergingCache
	@mkdir obj/Debug/Object/VoxelSet
	@mkdir obj/Debug/Object/Mesh
	@mkdir obj/Debug/Object/Mesh/2D
	@mkdir obj/Debug/Object/Mesh/3D
	@mkdir obj/Debug/Object/Mesh/3D/VoxelMesh
	@mkdir obj/Debug/Object/Mesh/Data
	@mkdir obj/Debug/Object/Mesh/Data/DataSet
	@mkdir obj/Debug/Object/Mesh/Data/IntVertexData
	@mkdir obj/Debug/Object/Mesh/Data/FloatVertexData
	@mkdir obj/Debug/Object/Mesh/Data/IndexData
	@mkdir obj/Debug/Object/Mesh/Data/MaterialData
	@mkdir obj/Debug/Object/Mesh/Data/NormalData
	@mkdir obj/Debug/Object/Mesh/Data/TangentData
	@mkdir obj/Debug/Object/Mesh/Data/UVData
	@mkdir obj/Debug/Object/Mesh/Data/ColorData
	@mkdir obj/Debug/lib
	@mkdir obj/Debug/lib/FastNoise
	@mkdir obj/Debug/Maths
	@mkdir obj/Debug/Renderer
	@mkdir obj/Debug/Renderer/Color
	@mkdir obj/Debug/Renderer/Color/RGB
	@mkdir obj/Debug/Renderer/Color/HSL
	@mkdir obj/Debug/Renderer/SSAO
	@mkdir obj/Debug/Renderer/Shader
	@mkdir obj/Debug/Renderer/Shader/EngineShader
	@mkdir obj/Debug/Renderer/Shader/EngineShader/BRDF
	@mkdir obj/Debug/Renderer/Shader/EngineShader/Capture
	@mkdir obj/Debug/Renderer/Shader/EngineShader/GBuffer
	@mkdir obj/Debug/Renderer/Shader/EngineShader/Irradiance
	@mkdir obj/Debug/Renderer/Shader/EngineShader/PBR
	@mkdir obj/Debug/Renderer/Shader/EngineShader/Prefilter
	@mkdir obj/Debug/Renderer/Shader/EngineShader/SkyBox
	@mkdir obj/Debug/Renderer/Shader/EngineShader/SSAO
	@mkdir obj/Debug/Renderer/Shader/ShaderMap
	@mkdir obj/Debug/Renderer/Shader/ShaderBase
	@mkdir obj/Debug/Renderer/Shader/ShaderBase/VertexShader
	@mkdir obj/Debug/Renderer/Shader/ShaderBase/FragmentShader
	@mkdir obj/Debug/Renderer/Material
	@mkdir obj/Debug/Renderer/Material/MaterialManager
	@mkdir obj/Debug/Renderer/EnvironmentMap
	@mkdir obj/Debug/Renderer/DeferredRenderer
	@mkdir obj/Debug/Light
	@mkdir obj/Debug/Light/DirectionnalLight
	@mkdir obj/Debug/Light/PointLight
	@mkdir obj/Debug/Light/SpotLight
	@mkdir obj/Debug/SDL_Wrapper
	@mkdir obj/Debug/SDL_Wrapper/Event
	@mkdir obj/Debug/SDL_Wrapper/Window
	@mkdir obj/Debug/SDL_Wrapper/Surface
	@mkdir obj/Debug/SDL_Wrapper/PixelFormat
	@mkdir obj/Debug/Support
	@mkdir obj/Debug/Support/Viewport
	@mkdir obj/Debug/Support/Stage
	@mkdir obj/Debug/Time
	@mkdir obj/Debug/Time/Clock
	@mkdir obj/Debug/Time/Timestep
	@mkdir obj/Debug/Time/Date
	@mkdir obj/Debug/Time/AdvancedDate
	@mkdir obj/Debug/World
	@mkdir obj/Debug/World/Chunk
	@mkdir obj/Debug/World/Region
	@mkdir obj/Debug/World/ChunkConstructor
	@mkdir obj/Debug/World/Voxel
	@mkdir obj/Debug/World/Voxel/VoxelPoint
	@mkdir obj/Debug/World/Voxel/Type
	@mkdir obj/Debug/World/Voxel/Type/VoxelType
	@mkdir obj/Debug/World/Voxel/Type/VoxelType/Type
	@mkdir obj/Debug/World/Voxel/Type/VoxelTypes
	@echo "obj/-Tree creation done."
	@echo "Clean done."
