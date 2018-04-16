
    #include "NRE_Stage.hpp"

    namespace NRE {
        namespace Support {

            Uint32 Stage::DEFAULT_FLAGS = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE;
            Uint32 Stage::SDL_INIT_FLAGS = SDL_INIT_VIDEO;
            int Stage::MAJOR_VERSION = 4;
            int Stage::MINOR_VERSION = 5;
            int Stage::DEPTH_SIZE = 24;

            Stage::Stage() : context(0) {
            }

            Stage::Stage(std::string const& title, Maths::Vector2D<int> size, Maths::Point2D<int> coord) : context(0) {
                int err = SDL_Init(SDL_INIT_FLAGS);
                if (err != 0) {
                    throw (Exception::SupportException(std::string(SDL_GetError())));
                }

                window.createWindow(title, coord, size, DEFAULT_FLAGS);
                init();
                viewport.createCurrent();
            }

            Stage::Stage(Stage const& s) : window(s.getWindow()), viewport(s.getViewport()), context(s.getContext()) {
            }

            Stage::~Stage() {
                SDL_GL_DeleteContext(getContext());

                SDL_Quit();
            }

            SDL::Window const& Stage::getWindow() const {
                return window;
            }

            Viewport const& Stage::getViewport() const {
                return viewport;
            }

            SDL_GLContext const& Stage::getContext() const {
                return context;
            }

            void Stage::setWindow(SDL::Window const& w) {
                window = w;
            }

            void Stage::setViewport(Viewport const& v) {
                viewport = v;
            }

            void Stage::setContext(SDL_GLContext const& c) {
                context = c;
            }

            void Stage::init() {
                initScreen();
                initGL();

                glEnable(GL_DEPTH_TEST);
                glEnable(GL_CULL_FACE);
                    glCullFace(GL_BACK);
                glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);

                SDL_SetRelativeMouseMode(SDL_TRUE);
            }

            void Stage::initScreen() {
                SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, MAJOR_VERSION);
                SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, MINOR_VERSION);

                SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
                SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, DEPTH_SIZE);
                SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

                context = SDL_GL_CreateContext(getWindow().getItem());
                if (context == NULL) {
                    throw (Exception::SDLException(std::string(SDL_GetError())));
                }
            }

            void Stage::initGL() {
                GLenum err = glewInit();
                if (err != GLEW_OK) {
                    throw (Exception::SupportException(std::string(reinterpret_cast <const char*> (glewGetErrorString(err)))));
                }
            }

        };
    };
