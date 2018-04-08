
    #include "NRE_Key.hpp"

    namespace NRE {
        namespace Camera {

            Key::Key() : Key(0, false, false, 0) {
                std::cout << "Key C" << std::endl;
            }

            Key::Key(unsigned int const& code, bool const& active, bool const& switchKey, BaseCommand* cmd) : code(code), active(active), switchKey(switchKey), action(cmd) {
                std::cout << "Key C" << std::endl;
            }

            Key::Key(Key const& k) : code(k.getCode()), active(k.isActive()), switchKey(k.isSwitch()), action(k.getAction()) {
                std::cout << "Key C" << std::endl;
            }

            Key::~Key() {
                std::cout << "Key D" << std::endl;
                delete action;
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

            BaseCommand* const Key::getAction() const {
                return action;
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

            void Key::setAction(BaseCommand* cmd) {
                action = cmd;
            }

            void Key::execute() {
                if (action != 0) {
                    action->execute();
                }
            }

        };
    };
