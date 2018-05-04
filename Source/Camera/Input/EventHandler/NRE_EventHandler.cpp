
    #include "NRE_EventHandler.hpp"

    namespace NRE {
        namespace Camera {

            EventHandler::EventHandler() : quit(false) {
            }

            EventHandler::EventHandler(EventHandler const& e) : SDL::Event(e), quit(e.getQuit()) {
            }

            EventHandler::EventHandler(EventHandler && e) : SDL::Event(std::move(e)), quit(std::move(e.getQuit())) {
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

            EventHandler& EventHandler::operator=(EventHandler const& e) {
                SDL::Event::operator=(e);
                quit = e.getQuit();
                return *this;
            }

            EventHandler& EventHandler::operator=(EventHandler && e) {
                SDL::Event::operator=(std::move(e));
                quit = std::move(e.getQuit());
                return *this;
            }

        };
    };
