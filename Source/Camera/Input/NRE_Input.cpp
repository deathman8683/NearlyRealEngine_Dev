
    #include "NRE_Input.hpp"

    namespace NRE {
        namespace Camera {

            Input::Input() {
            }

            Input::Input(Keyboard const& kb, Mouse const& m, EventHandler const& e) : Keyboard::Keyboard(kb), Mouse::Mouse(m), EventHandler::EventHandler(e) {
            }

            Input::Input(Input const& in) : Keyboard::Keyboard(in), Mouse::Mouse(in), EventHandler::EventHandler(in) {
            }

            Input::Input(Input && in) : Keyboard::Keyboard(std::move(in)), Mouse::Mouse(std::move(in)), EventHandler::EventHandler(std::move(in)) {
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
                            if (getMouseWhich() != SDL_TOUCH_MOUSEID) {
                                Mouse::keyDown(getMouseButton());
                                setClick(getMouseClick());
                            }
                            break;
                        }
                        case (SDL_MOUSEBUTTONUP) : {
                            if (getMouseWhich() != SDL_TOUCH_MOUSEID) {
                                Mouse::keyUp(getMouseButton());
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
                Keyboard::execute();
                Mouse::execute();
            }

            Input& Input::operator=(Input const& in) {
                Keyboard::operator=(in);
                Mouse::operator=(in);
                EventHandler::operator=(in);
                return *this;
            }

            Input& Input::operator=(Input && in) {
                Keyboard::operator=(std::move(in));
                Mouse::operator=(std::move(in));
                EventHandler::operator=(std::move(in));
                return *this;
            }
        };
    };
