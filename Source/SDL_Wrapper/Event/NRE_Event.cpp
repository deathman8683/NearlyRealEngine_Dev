
    #include "NRE_Event.hpp"

    namespace NRE {
        namespace SDL {

            Event::Event() {
            }

            Event::Event(Event const& e) : item(e.getItem()) {
            }

            Event::Event(SDL_Event const& e) : item(e) {
            }

            Event::~Event() {
            }

            SDL_Event const& Event::getItem() const {
                return item;
            }

            Uint32 const& Event::getType() const {
                return getItem().type;
            }

            SDL_Scancode const& Event::getKeyScancode() const {
                return getItem().key.keysym.scancode;
            }

            SDL_Keycode const& Event::getKeyKeycode() const {
                return getItem().key.keysym.sym;
            }

            Uint8 const& Event::getMouseButton() const {
                return getItem().button.button;
            }

            Maths::Point2D<unsigned short int> const Event::getMouseClick() const {
                return Maths::Point2D<unsigned short int>(getItem().button.x, getItem().button.y);
            }

            void Event::setItem(SDL_Event const& e) {
                item = e;
            }

            int Event::poll() {
                return SDL_PollEvent(&item);
            }

            int Event::wait() {
                return SDL_WaitEvent(&item);
            }

        };
    };
