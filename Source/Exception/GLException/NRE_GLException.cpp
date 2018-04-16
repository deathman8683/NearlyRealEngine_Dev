
    #include "NRE_GLException.hpp"

    namespace NRE {
        namespace Exception {

            GLException::GLException() throw() {
            }

            GLException::GLException(std::string const& log) throw() : ExceptionHandler::ExceptionHandler("GLException : " + log) {
            }

            GLException::GLException(GLException const& e) throw() : ExceptionHandler::ExceptionHandler(e) {
            }

            GLException::~GLException() throw() {
            }

        };
    };
