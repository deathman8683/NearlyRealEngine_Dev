
    #include "NRE_Key.hpp"

    namespace NRE {
        namespace Input {

            Key::Key() : code(0), state(false), isSwitch(false) {
            }

            Key::Key(SDL_Scancode const& code, bool const& state, bool const& isSwitch) : code(code), state(state), isSwitch(isSwitch) {
            }

            Key::Key(Key const& k) : code(k.getCode()), state(k.getState()), isSwitch(k.isSwitch()) {
            }

            Key::~Key() {
            }

            SDL_Scancode const& Key::getCode() const {
                return code;
            }

            bool const& Key::getState() const {
                return state;
            }

            bool const& Key::isSwitch() const {
                return isSwitch;
            }

            void Key::setCode(SDL_Scancode const& code) {
                this->code = code;
            }

            void Key::setState(bool const& state) {
                this->state = state;
            }

            void Key::setSwitch(bool const& state) {
                isSwitch = state;
            }

        };
    };
