
    #include "NRE_Window.hpp"

    namespace NRE {
        namespace SDL {

            Window::Window() : item(0) {
            }

            Window::Window(std::string const& title, int const& x, int const& y, int const& w, int const& h, unsigned int const& flags) {
                item = SDL_CreateWindow(title.c_str(), x, y, w, h, flags);
            }

            Window::Window(Window const& w) {
                item = w.getItem();
            }

            Window::~Window() {
                SDL_DestroyWindow(getItem());
            }

            SDL_Window* const& Window::getItem() const {
                return item;
            }

        };
    };
