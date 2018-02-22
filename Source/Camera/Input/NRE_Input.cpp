
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

            void Input::update(Maths::Vector2D<NREfloat>* cameraAngle) {
                while (poll()) {
                    switch(getType()) {
                        case (SDL_QUIT) : {
                            setQuit(true);
                            break;
                        }
                        case (SDL_KEYDOWN) : {
                            Key& tmp = Keyboard::keyMap.at(getKeyScancode());
                            if (tmp.isSwitch()) {
                                tmp.setActive(!tmp.isActive());
                            } else {
                                tmp.setActive(true);
                            }
                            break;
                        }
                        case (SDL_KEYUP) : {
                            Key& tmp = Keyboard::keyMap.at(getKeyScancode());
                            if (!tmp.isSwitch()) {
                                tmp.setActive(false);
                            }
                            break;
                        }
                        case (SDL_MOUSEBUTTONDOWN) : {
                            Key& tmp = Mouse::keyMap.at(getMouseButton());
                            if (tmp.isSwitch()) {
                                tmp.setActive(!tmp.isActive());
                            } else {
                                tmp.setActive(true);
                            }
                            setClick(getMouseClick());
                            break;
                        }
                        case (SDL_MOUSEBUTTONUP) : {
                            Key& tmp = Mouse::keyMap.at(getMouseButton());
                            if (!tmp.isSwitch()) {
                                tmp.setActive(false);
                            }
                            break;
                        }
                        case (SDL_MOUSEMOTION) : {
                            if (cameraAngle) {
                                *cameraAngle = *cameraAngle - (getMotionRel() * getSensitivity());
                            }
                            setCursor(getMotion());
                            break;
                        }
                        default: {

                        }
                    }
                }
            }

        };
    };
