
    #include "NRE_ShaderException.hpp"

    namespace NRE {
        namespace Exception {

            ShaderException::ShaderException() throw() {
            }

            ShaderException::ShaderException(std::string const& log) throw() : ExceptionHandler::ExceptionHandler("ShaderException : " + log) {
            }

            ShaderException::ShaderException(ShaderException const& e) throw() : ExceptionHandler::ExceptionHandler(e) {
            }

            ShaderException::~ShaderException() throw() {
            }

        };
    };
