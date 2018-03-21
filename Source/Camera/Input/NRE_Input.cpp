
    #include "NRE_Input.hpp"

    namespace NRE {
        namespace Input {

            Input::Input() {
            }

            Input::Input(std::string const& kbPath, std::string const& mPath) : Keyboard::Keyboard(kbPath), Mouse::Mouse(mPath) {
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
                            Key& it = Keyboard::keyMap.at(getKeyScancode());
                            Key& tmp = Keyboard::keyMap.at(it.getCode());
                            if (tmp.isSwitch()) {
                                tmp.setActive(!tmp.isActive());
                            } else {
                                tmp.setActive(true);
                            }
                            break;
                        }
                        case (SDL_KEYUP) : {
                            Key& it = Keyboard::keyMap.at(getKeyScancode());
                            Key& tmp = Keyboard::keyMap.at(it.getCode());
                            if (!tmp.isSwitch()) {
                                tmp.setActive(false);
                            }
                            break;
                        }
                        case (SDL_MOUSEBUTTONDOWN) : {
                            Key& it = Mouse::keyMap.at(getMouseButton());
                            Key& tmp = Mouse::keyMap.at(it.getCode());
                            if (tmp.isSwitch()) {
                                tmp.setActive(!tmp.isActive());
                            } else {
                                tmp.setActive(true);
                            }
                            setClick(getMouseClick());
                            break;
                        }
                        case (SDL_MOUSEBUTTONUP) : {
                            Key& it = Mouse::keyMap.at(getMouseButton());
                            Key& tmp = Mouse::keyMap.at(it.getCode());
                            tmp = Mouse::keyMap.at(tmp.getCode());
                            if (!tmp.isSwitch()) {
                                tmp.setActive(false);
                            }
                            break;
                        }
                        case (SDL_MOUSEMOTION) : {
                            if (cameraAngle) {
                                cameraAngle->setX(cameraAngle->getX() + getMotionRel().getX() * getSensitivity());
                                cameraAngle->setY(cameraAngle->getY() - getMotionRel().getY() * getSensitivity());
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
