
    #include "NRE_Input.hpp"

    namespace NRE {
        namespace Input {

            Input::Input() {
            }

            Input::Input(Keyboard const& kb, Mouse const& m, EventHandler const& e) : Keyboard::Keyboard(kb), Mouse::Mouse(m), EventHandler::EventHandler(e) {
            }

            Input::Input(Input const& in) : Keyboard::Keyboard(in), Mouse::Mouse(in), EventHandler::EventHandler(in) {
            }

            Input::~Input() {
            }

            void Input::update() {
                while (poll()) {
                    switch(getType()) {
                        case (SDL_QUIT) : {
                            setQuit(true);
                            break;
                        }
                        case (SDL_KEYDOWN) : {
                            if (Keyboard::keyMap.at(getKeyScancode()).isSwitch()) {
                                Keyboard::keyMap.at(getKeyScancode()).setActive(!Keyboard::keyMap.at(getKeyScancode()).isActive());
                            } else {
                                Keyboard::keyMap.at(getKeyScancode()).setActive(true);
                            }
                            break;
                        }
                        case (SDL_KEYUP) : {
                            if (!Keyboard::keyMap.at(getKeyScancode()).isSwitch()) {
                                Keyboard::keyMap.at(getKeyScancode()).setActive(false);
                            }
                            break;
                        }
                        case (SDL_MOUSEBUTTONDOWN) : {
                            if (Mouse::keyMap.at(getMouseButton()).isSwitch()) {
                                Mouse::keyMap.at(getMouseButton()).setActive(!Keyboard::keyMap.at(getMouseButton()).isActive());
                            } else {
                                Mouse::keyMap.at(getMouseButton()).setActive(true);
                            }
                            setClick(getMouseClick());
                            break;
                        }
                        case (SDL_MOUSEBUTTONUP) : {
                            if (!Mouse::keyMap.at(getMouseButton()).isSwitch()) {
                                Mouse::keyMap.at(getMouseButton()).setActive(false);
                            }
                            break;
                        }
                    }
                }
            }

        };
    };
