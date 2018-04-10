
    #include "NRE_SDLException.hpp"

    namespace NRE {
        namespace Exception {

            SDLException::SDLException() throw() {
            }

            SDLException::SDLException(std::string const& log) throw() : ExceptionHandler::ExceptionHandler("SDLException : " + log) {
            }

            SDLException::SDLException(SDLException const& e) throw() : ExceptionHandler::ExceptionHandler(e) {
            }

            SDLException::~SDLException() throw() {
            }

        };
    };
