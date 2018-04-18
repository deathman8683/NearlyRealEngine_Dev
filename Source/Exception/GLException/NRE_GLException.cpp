
    #include "NRE_GLException.hpp"

    namespace NRE {
        namespace Exception {

            GLException::GLException() throw() {
            }

            GLException::GLException(std::string const& log) throw() : ExceptionHandler::ExceptionHandler("GLException : " + log) {
            }

            GLException::GLException(GLException const& e) throw() : ExceptionHandler::ExceptionHandler(e) {
            }

            GLException::GLException(GLException && e) throw() : ExceptionHandler::ExceptionHandler(std::move(e)) {
            }

            GLException::~GLException() throw() {
            }

            GLException& GLException::operator=(GLException const& e) {
                ExceptionHandler::operator=(e);
                return *this;
            }

            GLException& GLException::operator=(GLException && e) {
                ExceptionHandler::operator=(std::move(e));
                return *this;
            }

        };
    };
