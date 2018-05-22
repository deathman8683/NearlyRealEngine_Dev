
    #include "NRE_Application.hpp"

    namespace NRE {
        namespace Support {

            Application::Application() {
            }

            Application::Application(std::string const& title, Maths::Vector2D<GLuint> const& size) : Stage(title, size) {
            }

            Application::Application(Application const& app) {
            }

            Application::Application(Application && app) {
            }

            Application::~Application() {
            }

            Application& Application::operator=(Application const& app) {
                return *this;
            }

            Application& Application::operator=(Application && app) {
                return *this;
            }

        };
    };
