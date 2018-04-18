
    #include "NRE_SDLException.hpp"

    namespace NRE {
        namespace Exception {

            SDLException::SDLException() throw() {
            }

            SDLException::SDLException(std::string const& log) throw() : ExceptionHandler::ExceptionHandler("SDLException : " + log) {
            }

            SDLException::SDLException(SDLException const& e) throw() : ExceptionHandler::ExceptionHandler(e) {
            }

            SDLException::SDLException(SDLException && e) throw() : ExceptionHandler::ExceptionHandler(std::move(e)) {
            }

            SDLException::~SDLException() throw() {
            }

            SDLException& SDLException::operator=(SDLException const& e) {
                ExceptionHandler::operator=(e);
                return *this;
            }

            SDLException& SDLException::operator=(SDLException && e) {
                ExceptionHandler::operator=(std::move(e));
                return *this;
            }

        };
    };
