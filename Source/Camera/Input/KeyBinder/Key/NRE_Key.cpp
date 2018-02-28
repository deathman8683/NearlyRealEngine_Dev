
    #include "NRE_Key.hpp"

    namespace NRE {
        namespace Input {

            Key::Key() : code(0), active(false), switchKey(false) {
            }

            Key::Key(unsigned int const& code, bool const& active, bool const& switchKey) : code(code), active(active), switchKey(switchKey) {
            }

            Key::Key(Key const& k) : code(k.getCode()), active(k.isActive()), switchKey(k.isSwitch()) {
            }

            Key::~Key() {
            }

            unsigned int const& Key::getCode() const {
                return code;
            }

            bool const& Key::isActive() const {
                return active;
            }

            bool const& Key::isSwitch() const {
                return switchKey;
            }

            void Key::setCode(unsigned int const& code) {
                this->code = code;
            }

            void Key::setActive(bool const& state) {
                active = state;
            }

            void Key::setSwitch(bool const& state) {
                switchKey = state;
            }

        };
    };
