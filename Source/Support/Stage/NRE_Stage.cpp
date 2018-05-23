
    #include "NRE_Stage.hpp"

    namespace NRE {
        namespace Support {

            Uint32 Stage::DEFAULT_FLAGS = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE;

            Stage::Stage(std::string const& title, Maths::Vector2D<int> size, Maths::Point2D<int> coord) : Init::Init(), window(title, coord, size, DEFAULT_FLAGS) {
                initializeOpenGL(context, window);
                initializeManager();
            }

            Stage::~Stage() {
                SDL_GL_DeleteContext(context);
            }

            Viewport const& Stage::getViewport() const {
                return viewport;
            }

            void Stage::updateScreen() {
                SDL_GL_SwapWindow(window.getItem());
            }

        };
    };
