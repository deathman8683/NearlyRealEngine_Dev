
    #include "NRE_Keyboard.hpp"

    namespace NRE {
        namespace Camera {

            Keyboard::Keyboard() : KeyBinder::KeyBinder(SDL_NUM_SCANCODES) {
                for (unsigned int i = 0; i < SDL_NUM_SCANCODES; i = i + 1) {
                    insert(i, Key(i, false, false, 0));
                }
            }

            Keyboard::Keyboard(std::string const& path) : KeyBinder::KeyBinder(SDL_NUM_SCANCODES, path) {
            }

            Keyboard::Keyboard(Keyboard const& kb) : KeyBinder::KeyBinder(kb) {
            }

            Keyboard::~Keyboard() {
            }

        };
    };
