
    #include "NRE_Scene.hpp"

    namespace NRE {
        namespace Support {

            Uint32 Scene::DEFAULT_FLAGS = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE;
            Uint32 Scene::SDL_INIT_FLAGS = SDL_INIT_VIDEO;
            int Scene::MAJOR_VERSION = 4;
            int Scene::MINOR_VERSION = 5;
            int Scene::DEPTH_SIZE = 24;

            Scene::Scene() : context(0) {
            }

            Scene::Scene(std::string const& title, Maths::Vector2D<int> size, Maths::Point2D<int> coord) : context(0) {
                SDL_Init(SDL_INIT_FLAGS);

                window.createWindow(title, coord, size, DEFAULT_FLAGS);
                init();
                viewport.createCurrent();
            }

            Scene::Scene(Scene const& s) : window(s.getWindow()), viewport(s.getViewport()), context(s.getContext()) {
            }

            Scene::~Scene() {
                SDL_GL_DeleteContext(getContext());

                SDL_Quit();
            }

            SDL::Window const& Scene::getWindow() const {
                return window;
            }

            Viewport const& Scene::getViewport() const {
                return viewport;
            }

            SDL_GLContext const& Scene::getContext() const {
                return context;
            }

            void Scene::setWindow(SDL::Window const& w) {
                window = w;
            }

            void Scene::setViewport(Viewport const& v) {
                viewport = v;
            }

            void Scene::setContext(SDL_GLContext const& c) {
                context = c;
            }

            void Scene::init() {
                initScreen();
                initGL();
            }

            void Scene::initScreen() {
                SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, MAJOR_VERSION);
                SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, MINOR_VERSION);

                SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
                SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, DEPTH_SIZE);
                SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

                context = SDL_GL_CreateContext(getWindow().getItem());
            }

            void Scene::initGL() {
                glewInit();
            }

        };
    };
