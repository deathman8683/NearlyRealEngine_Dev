
    #include "NRE_SecurityException.hpp"

    namespace NRE {
        namespace Exception {

            SecurityException::SecurityException() throw() {
            }

            SecurityException::SecurityException(std::string const& log) throw() : ExceptionHandler::ExceptionHandler("SecurityException : " + log) {
            }

            SecurityException::SecurityException(SecurityException const& e) throw() : ExceptionHandler::ExceptionHandler(e) {
            }

            SecurityException::SecurityException(SecurityException && e) throw() : ExceptionHandler::ExceptionHandler(std::move(e)) {
            }

            SecurityException::~SecurityException() throw() {
            }

            SecurityException& SecurityException::operator=(SecurityException const& e) {
                ExceptionHandler::operator=(e);
                return *this;
            }

            SecurityException& SecurityException::operator=(SecurityException && e) {
                ExceptionHandler::operator=(std::move(e));
                return *this;
            }

        };
    };
