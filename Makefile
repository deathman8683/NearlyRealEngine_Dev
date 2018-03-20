export CXX = g++.exe
export LD = g++.exe

export CFLAGS = -Wall -std=c++14
export LDFLAGS = -lopengl32 -lglu32

export INC = -I"C:\lib\TDM-GCC-64\include" -I"C:\lib\Glew\include" -I"C:\lib\GLM" -I"C:\lib\SDL2-2.0.8\x86_64-w64-mingw32\include"
export LIBDIR = -L"C:\lib\TDM-GCC-64\lib" -L"C:\lib\Glew\lib" -L"C:\lib\SDL2-2.0.8\x86_64-w64-mingw32\lib"
export LIB = "C:\lib\TDM-GCC-64\x86_64-w64-mingw32\lib\libmingw32.a" "C:\lib\Glew\lib\libglew32.dll.a" "C:\lib\SDL2-2.0.8\x86_64-w64-mingw32\lib\libSDL2main.a" "C:\lib\SDL2-2.0.8\x86_64-w64-mingw32\lib\libSDL2.dll.a" "C:\lib\SDL2-2.0.8\x86_64-w64-mingw32\lib\libSDL2_image.dll.a"

export TARGET = debug

ifeq ($(TARGET), debug)
	OBJDIR = obj/Debug/
	BIN = bin/Debug/
	SOURCE = Source
	OBJ = $(OBJDIR)Generic/Array/NRE_ArrayOperation.o $(OBJDIR)Exception/NRE_ExceptionHandler.o $(OBJDIR)Exception/ShaderException/NRE_ShaderException.o $(OBJDIR)lib/FastNoise/FastNoise.o $(OBJDIR)SDL_Wrapper/Window/NRE_Window.o $(OBJDIR)SDL_Wrapper/Event/NRE_Event.o $(OBJDIR)SDL_Wrapper/PixelFormat/NRE_PixelFormat.o $(OBJDIR)SDL_Wrapper/Surface/NRE_Surface.o $(OBJDIR)GL_Wrapper/Buffer/NRE_Buffer.o $(OBJDIR)GL_Wrapper/Buffer/AttributeBuffer/NRE_AttributeBuffer.o $(OBJDIR)GL_Wrapper/Buffer/AttributeBuffer/ArrayBuffer/NRE_ArrayBuffer.o $(OBJDIR)GL_Wrapper/Buffer/AttributeBuffer/ArrayBuffer/VertexBuffer/NRE_VertexBuffer.o $(OBJDIR)GL_Wrapper/Buffer/AttributeBuffer/ArrayBuffer/ColorBuffer/NRE_ColorBuffer.o $(OBJDIR)GL_Wrapper/Buffer/AttributeBuffer/ArrayBuffer/NormalBuffer/NRE_NormalBuffer.o $(OBJDIR)GL_Wrapper/Buffer/AttributeBuffer/ArrayBuffer/UVBuffer/NRE_UVBuffer.o $(OBJDIR)GL_Wrapper/Buffer/AttributeBuffer/IndexBuffer/NRE_IndexBuffer.o $(OBJDIR)GL_Wrapper/Buffer/TextureBuffer/NRE_TextureBuffer.o $(OBJDIR)GL_Wrapper/Buffer/FrameBuffer/NRE_FrameBuffer.o $(OBJDIR)GL_Wrapper/Buffer/RenderBuffer/NRE_RenderBuffer.o $(OBJDIR)GL_Wrapper/Buffer/VAO/NRE_VAO.o $(OBJDIR)GL_Wrapper/BufferObject/NRE_BufferObject.o $(OBJDIR)GL_Wrapper/BufferObject/VBO/NRE_VBO.o $(OBJDIR)GL_Wrapper/BufferObject/IBO/NRE_IBO.o $(OBJDIR)GL_Wrapper/BufferObject/Texture2D/NRE_Texture2D.o $(OBJDIR)GL_Wrapper/BufferObject/SkyBox/NRE_SkyBox.o $(OBJDIR)GL_Wrapper/BufferObject/FBO/NRE_FBO.o $(OBJDIR)Time/Timestep/NRE_Timestep.o $(OBJDIR)Time/Date/NRE_Date.o $(OBJDIR)Time/AdvancedDate/NRE_AdvancedDate.o $(OBJDIR)Time/Clock/NRE_Clock.o $(OBJDIR)Renderer/Color/RGB/NRE_RGB.o $(OBJDIR)Renderer/Color/HSL/NRE_HSL.o $(OBJDIR)Renderer/Color/RGB/NRE_RGBA.o $(OBJDIR)Renderer/Color/HSL/NRE_HSLA.o $(OBJDIR)Renderer/Color/NRE_ColorConverter.o $(OBJDIR)Renderer/Shader/ShaderBase/NRE_ShaderBase.o $(OBJDIR)Renderer/Shader/ShaderBase/VertexShader/NRE_VertexShader.o $(OBJDIR)Renderer/Shader/ShaderBase/FragmentShader/NRE_FragmentShader.o $(OBJDIR)Renderer/Shader/NRE_Shader.o $(OBJDIR)Renderer/DeferredRenderer/NRE_DeferredRenderer.o $(OBJDIR)Lighting/NRE_Light.o $(OBJDIR)Camera/Input/KeyBinder/Key/NRE_Key.o $(OBJDIR)Camera/Input/KeyBinder/NRE_KeyBinder.o $(OBJDIR)Camera/Input/Keyboard/NRE_Keyboard.o $(OBJDIR)Camera/Input/EventHandler/NRE_EventHandler.o $(OBJDIR)Camera/Input/Mouse/NRE_Mouse.o $(OBJDIR)Camera/Input/NRE_Input.o $(OBJDIR)Camera/FixedCamera/NRE_FixedCamera.o $(OBJDIR)Camera/NRE_MoveableCamera.o $(OBJDIR)World/Voxel/NRE_Voxel.o $(OBJDIR)World/Voxel/Type/NRE_VoxelType.o $(OBJDIR)World/Voxel/PackedVertex/NRE_PackedVertex.o $(OBJDIR)World/Mesh/NRE_Mesh.o $(OBJDIR)World/Chunk/NRE_Chunk.o $(OBJDIR)World/NRE_World.o $(OBJDIR)World/ChunkConstructor/NRE_ChunkConstructor.o $(OBJDIR)Support/Viewport/NRE_Viewport.o $(OBJDIR)Support/Scene/NRE_Scene.o $(OBJDIR)NRE_Main.o

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
	@mkdir obj/Debug/Generic
	@mkdir obj/Debug/Generic/Array
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
	@mkdir obj/Debug/GL_Wrapper/Buffer/AttributeBuffer/ArrayBuffer/NormalBuffer
	@mkdir obj/Debug/GL_Wrapper/Buffer/AttributeBuffer/ArrayBuffer/UVBuffer
	@mkdir obj/Debug/GL_Wrapper/Buffer/AttributeBuffer/IndexBuffer
	@mkdir obj/Debug/GL_Wrapper/Buffer/TextureBuffer
	@mkdir obj/Debug/GL_Wrapper/Buffer/FrameBuffer
	@mkdir obj/Debug/GL_Wrapper/Buffer/RenderBuffer
	@mkdir obj/Debug/GL_Wrapper/Buffer/VAO
	@mkdir obj/Debug/GL_Wrapper/BufferObject
	@mkdir obj/Debug/GL_Wrapper/BufferObject/VBO
	@mkdir obj/Debug/GL_Wrapper/BufferObject/IBO
	@mkdir obj/Debug/GL_Wrapper/BufferObject/Texture2D
	@mkdir obj/Debug/GL_Wrapper/BufferObject/SkyBox
	@mkdir obj/Debug/GL_Wrapper/BufferObject/FBO
	@mkdir obj/Debug/lib
	@mkdir obj/Debug/lib/FastNoise
	@mkdir obj/Debug/Renderer
	@mkdir obj/Debug/Renderer/Color
	@mkdir obj/Debug/Renderer/Color/RGB
	@mkdir obj/Debug/Renderer/Color/HSL
	@mkdir obj/Debug/Renderer/Shader
	@mkdir obj/Debug/Renderer/Shader/ShaderBase
	@mkdir obj/Debug/Renderer/Shader/ShaderBase/VertexShader
	@mkdir obj/Debug/Renderer/Shader/ShaderBase/FragmentShader
	@mkdir obj/Debug/Renderer/DeferredRenderer
	@mkdir obj/Debug/Lighting
	@mkdir obj/Debug/SDL_Wrapper
	@mkdir obj/Debug/SDL_Wrapper/Event
	@mkdir obj/Debug/SDL_Wrapper/Window
	@mkdir obj/Debug/SDL_Wrapper/Surface
	@mkdir obj/Debug/SDL_Wrapper/PixelFormat
	@mkdir obj/Debug/Support
	@mkdir obj/Debug/Support/Viewport
	@mkdir obj/Debug/Support/Scene
	@mkdir obj/Debug/Time
	@mkdir obj/Debug/Time/Clock
	@mkdir obj/Debug/Time/Timestep
	@mkdir obj/Debug/Time/Date
	@mkdir obj/Debug/Time/AdvancedDate
	@mkdir obj/Debug/World
	@mkdir obj/Debug/World/Mesh
	@mkdir obj/Debug/World/Chunk
	@mkdir obj/Debug/World/ChunkConstructor
	@mkdir obj/Debug/World/Voxel
	@mkdir obj/Debug/World/Voxel/Type
	@mkdir obj/Debug/World/Voxel/PackedVertex
	@echo "obj/-Tree creation done."
	@echo "Clean done."
