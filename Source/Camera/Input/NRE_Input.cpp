
    #include "NRE_Input.hpp"

    namespace NRE {
        namespace Input {

            Input::Input() {
            }

            Input::Input(Keyboard const& kb, Mouse const& m) : Keyboard::Keyboard(kb), Mouse::Mouse(m) {
            }

            Input::Input(Input const& in) : Keyboard::Keyboard(in), Mouse::Mouse(in) {
            }

            Input::~Input() {
            }

        };
    };
