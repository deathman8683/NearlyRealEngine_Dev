
    #include "NRE_Keyboard.hpp"

    namespace NRE {
        namespace Camera {

            Keyboard::Keyboard() : KeyBinder::KeyBinder(SDL_NUM_SCANCODES) {
            }

            Keyboard::Keyboard(Keyboard const& kb) : KeyBinder::KeyBinder(kb) {
            }

            Keyboard::Keyboard(Keyboard && kb) : KeyBinder::KeyBinder(std::move(kb)) {
            }

            Keyboard::~Keyboard() {
            }

            Keyboard& Keyboard::operator=(Keyboard const& kb) {
                KeyBinder::operator=(kb);
                return *this;
            }

            Keyboard& Keyboard::operator=(Keyboard && kb) {
                KeyBinder::operator=(std::move(kb));
                return *this;
            }

        };
    };
