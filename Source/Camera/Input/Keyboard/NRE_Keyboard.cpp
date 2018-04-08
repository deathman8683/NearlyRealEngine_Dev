
    #include "NRE_Keyboard.hpp"

    namespace NRE {
        namespace Camera {

            Keyboard::Keyboard() : KeyBinder::KeyBinder(SDL_NUM_SCANCODES) {
            }

            Keyboard::Keyboard(Keyboard const& kb) : KeyBinder::KeyBinder(kb) {
            }

            Keyboard::~Keyboard() {
            }

        };
    };
