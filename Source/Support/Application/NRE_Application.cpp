
    #include "NRE_Application.hpp"

    namespace NRE {
        namespace Support {

            Application::Application(std::string const& title, Maths::Vector2D<GLuint> const& size) : Stage(title, size) {
            }

            Application::~Application() {
            }

        };
    };
