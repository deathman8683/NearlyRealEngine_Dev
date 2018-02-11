
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

            NREfloat const Window::getBrightness() const {
                return SDL_GetWindowBrightness(item);
            }

            std::string const Window::getTitle() const {
                return std::string(SDL_GetWindowTitle(item));
            }

            Maths::Vector2D<int> const Window::getSize() const {
                int w, h; SDL_GetWindowSize(item, &w, &h);

                return Maths::Vector2D<int>(w, h);
            }

            Maths::Point2D<int> const Window::getCoord() const {
                int x, y; SDL_GetWindowPosition(item, &x, &y);

                return Maths::Point2D<int>(x, y);
            }

            Maths::Vector2D<int> const Window::getMinSize() const {
                int w, h; SDL_GetWindowMinimumSize(item, &w, &h);

                return Maths::Vector2D<int>(w, h);
            }

            Maths::Vector2D<int> const Window::getMaxSize() const {
                int w, h; SDL_GetWindowMaximumSize(item, &w, &h);

                return Maths::Vector2D<int>(w, h);
            }

            void Window::setItem(SDL_Window* const& w) {
                item = w;
            }

            void Window::setBrightness(NREfloat const& brightness) {
                SDL_SetWindowBrightness(item, brightness);
            }

            void Window::setTitle(std::string const& title) {
                SDL_SetWindowTitle(item, title.c_str());
            }

            void Window::setSize(Maths::Vector2D<int> const& size) {
                SDL_SetWindowSize(item, size.getX(), size.getY());
            }

            void Window::setCoord(Maths::Point2D<int> const& coord) {
                SDL_SetWindowPosition(item, coord.getX(), coord.getY());
            }

            void Window::setMinSize(Maths::Vector2D<int> const& minSize) {
                SDL_SetWindowMinimumSize(item, minSize.getX(), minSize.getY());
            }

            void Window::setMaxSize(Maths::Vector2D<int> const& maxSize) {
                SDL_SetWindowMaximumSize(item, maxSize.getX(), maxSize.getY());
            }


        };
    };
