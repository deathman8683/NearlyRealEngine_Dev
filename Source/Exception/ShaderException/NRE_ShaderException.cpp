
    #include "NRE_ShaderException.hpp"

    namespace NRE {
        namespace Exception {

            ShaderException::ShaderException() throw() {
            }

            ShaderException::ShaderException(std::string const& log) throw() : ExceptionHandler::ExceptionHandler("ShaderException : " + log) {
            }

            ShaderException::ShaderException(ShaderException const& e) throw() : ExceptionHandler::ExceptionHandler(e) {
            }

            ShaderException::ShaderException(ShaderException && e) throw() : ExceptionHandler::ExceptionHandler(std::move(e)) {
            }

            ShaderException::~ShaderException() throw() {
            }

            ShaderException& ShaderException::operator=(ShaderException const& e) {
                ExceptionHandler::operator=(e);
                return *this;
            }

            ShaderException& ShaderException::operator=(ShaderException && e) {
                ExceptionHandler::operator=(std::move(e));
                return *this;
            }

        };
    };
