
    #include "NRE_Init.hpp"

    namespace NRE {

        int Init::MAJOR_VERSION = 4;
        int Init::MINOR_VERSION = 5;
        int Init::DEPTH_SIZE = 24;

        Init::Init() {
            iniatilizeLib();
        }

        Init::~Init() {
            Light::LightsManager::free();
            Renderer::ShadersManager::free();
            Object::MergingCache::free();
            Renderer::MaterialsManager::free();
            World::VoxelTypes::free();

            SDL_Quit();
        }

        void Init::iniatilizeLib() {
            int err = SDL_Init(SDL_INIT_VIDEO);
            if (err != 0) {
                throw (Exception::SupportException(std::string(SDL_GetError())));
            }

            SDL_SetRelativeMouseMode(SDL_TRUE);
        }

        void Init::initializeOpenGL(SDL_GLContext &glContext, SDL::Window &window) {
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, MAJOR_VERSION);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, MINOR_VERSION);

            SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
            SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, DEPTH_SIZE);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

            glContext = SDL_GL_CreateContext(window.getItem());
            if (glContext == NULL) {
                throw (Exception::SDLException(std::string(SDL_GetError())));
            }

            GLenum err = glewInit();
            if (err != GLEW_OK) {
                throw (Exception::SupportException(std::string(reinterpret_cast <const char*> (glewGetErrorString(err)))));
            }

            glEnable(GL_DEPTH_TEST);
            glEnable(GL_CULL_FACE);
                glCullFace(GL_BACK);
            glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);
        }

        void Init::initializeManager() {
            World::VoxelTypes::init();
            Renderer::MaterialsManager::init();
            Object::MergingCache::init();
            Renderer::ShadersManager::init();
            Light::LightsManager::init();
        }
    };
