
    #include "NRE_EventHandler.hpp"

    namespace NRE {
        namespace Input {

            EventHandler::EventHandler() : quit(false) {
            }

            EventHandler::EventHandler(EventHandler const& e) : SDL::Event(e), quit(e.getQuit()) {
            }

            EventHandler::EventHandler(SDL::Event const& e) : SDL::Event(e), quit(false) {
            }

            EventHandler::~EventHandler() {
            }

            bool const& EventHandler::getQuit() const {
                return quit;
            }

            void EventHandler::setQuit(bool const& state) {
                quit = state;
            }

        };
    };
