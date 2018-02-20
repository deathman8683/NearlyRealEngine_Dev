
    #include "NRE_Key.hpp"

    namespace NRE {
        namespace Input {

            Key::Key() : code(0), state(false), switchKey(false) {
            }

            Key::Key(unsigned int const& code, bool const& state, bool const& switchKey) : code(code), state(state), switchKey(switchKey) {
            }

            Key::Key(Key const& k) : code(k.getCode()), state(k.getState()), switchKey(k.isSwitch()) {
            }

            Key::~Key() {
            }

            unsigned int const& Key::getCode() const {
                return code;
            }

            bool const& Key::getState() const {
                return state;
            }

            bool const& Key::isSwitch() const {
                return switchKey;
            }

            void Key::setCode(unsigned int const& code) {
                this->code = code;
            }

            void Key::setState(bool const& state) {
                this->state = state;
            }

            void Key::setSwitch(bool const& state) {
                switchKey = state;
            }

        };
    };
