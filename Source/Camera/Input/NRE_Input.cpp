
    #include "NRE_Input.hpp"

    namespace NRE {
        namespace Camera {

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
                            Keyboard::keyDown(getKeyScancode());
                            break;
                        }
                        case (SDL_KEYUP) : {
                            Keyboard::keyUp(getKeyScancode());
                            break;
                        }
                        case (SDL_MOUSEBUTTONDOWN) : {
                            Mouse::keyDown(getKeyScancode());
                            setClick(getMouseClick());
                            break;
                        }
                        case (SDL_MOUSEBUTTONUP) : {
                            Mouse::keyUp(getKeyScancode());
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
                Keyboard::execute();
                Mouse::execute();
            }
        };
    };
