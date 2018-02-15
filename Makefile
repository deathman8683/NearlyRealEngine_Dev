export CXX = g++.exe
export LD = g++.exe

export CFLAGS = -Wall -std=c++14
export LDFLAGS = -lopengl32 -lglu32

export INC = -I"C:\lib\TDM-GCC-64\include" -I"C:\lib\Glew\include" -I"C:\lib\GLM" -I"C:\lib\SDL2-2.0.7\x86_64-w64-mingw32\include"
export LIBDIR = -L"C:\lib\TDM-GCC-64\lib" -L"C:\lib\Glew\lib" -L"C:\lib\SDL2-2.0.7\x86_64-w64-mingw32\lib"
export LIB = "C:\lib\TDM-GCC-64\x86_64-w64-mingw32\lib\libmingw32.a" "C:\lib\Glew\lib\libglew32.dll.a" "C:\lib\SDL2-2.0.7\x86_64-w64-mingw32\lib\libSDL2main.a" "C:\lib\SDL2-2.0.7\x86_64-w64-mingw32\lib\libSDL2.dll.a"

export TARGET = debug

ifeq ($(TARGET), debug)
	OBJDIR = obj/Debug/
	BIN = bin/Debug/
	SOURCE = Source
	OBJ =  $(OBJDIR)SDL_Wrapper/Window/NRE_Window.o $(OBJDIR)GL_Wrapper/BufferObject/NRE_BufferObject.o $(OBJDIR)GL_Wrapper/BufferObject/VBO/NRE_VBO.o $(OBJDIR)Support/Viewport/NRE_Viewport.o $(OBJDIR)Support/Scene/NRE_Scene.o $(OBJDIR)Renderer/Shader/NRE_Shader.o $(OBJDIR)NRE_Main.o

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
	@mkdir obj/Debug/GL_Wrapper
	@mkdir obj/Debug/GL_Wrapper/BufferObject
	@mkdir obj/Debug/GL_Wrapper/BufferObject/VBO
	@mkdir obj/Debug/Renderer
	@mkdir obj/Debug/Renderer/Shader
	@mkdir obj/Debug/SDL_Wrapper
	@mkdir obj/Debug/SDL_Wrapper/Window
	@mkdir obj/Debug/Support
	@mkdir obj/Debug/Support/Viewport
	@mkdir obj/Debug/Support/Scene
	@echo "obj/-Tree creation done."
	@echo "Clean done."

clean_Test :
	@echo "Clear of obj/"
	@rm -r obj
	@mkdir obj
	@mkdir obj/Test
	@mkdir obj/Test/GL_Wrapper
	@mkdir obj/Test/GL_Wrapper/BufferObject
	@mkdir obj/Test/GL_Wrapper/BufferObject/VBO
	@mkdir obj/Test/Renderer
	@mkdir obj/Test/Renderer/Shader
	@mkdir obj/Test/SDL_Wrapper
	@mkdir obj/Test/SDL_Wrapper/Window
	@mkdir obj/Test/Support
	@mkdir obj/Test/Support/Viewport
	@mkdir obj/Test/Support/Scene
	@echo "obj/-Tree creation done."
	@echo "Clean done."
