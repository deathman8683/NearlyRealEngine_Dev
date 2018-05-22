
    #include "NRE_Application.hpp"

    namespace NRE {
        namespace Support {

            Application::Application() {
            }

            Application::Application(std::string const& title, Maths::Vector2D<GLuint> const& size) : Stage(title, size) {
            }

            Application::Application(Application && app) : Stage(std::move(app)) {
            }

            Application::~Application() {
            }

            Application& Application::operator=(Application && app) {
                Stage::operator=(std::move(app));
                return *this;
            }

        };
    };
