
    #include "NRE_Key.hpp"

    namespace NRE {
        namespace Camera {

            Key::Key() : Key(false, false, 0) {
            }

            Key::Key(bool const& active, bool const& switchKey, BaseCommand* cmd) : active(active), switchKey(switchKey), action(cmd) {
            }

            Key::Key(Key const& k) : active(k.isActive()), switchKey(k.isSwitch()), action(k.getAction()) {
            }

            Key::~Key() {
                delete action;
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
