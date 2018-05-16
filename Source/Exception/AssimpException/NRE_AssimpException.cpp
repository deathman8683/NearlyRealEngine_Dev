
    #include "NRE_AssimpException.hpp"

    namespace NRE {
        namespace Exception {

            AssimpException::AssimpException() throw() {
            }

            AssimpException::AssimpException(std::string const& log) throw() : ExceptionHandler::ExceptionHandler("AssimpException : " + log) {
            }

            AssimpException::AssimpException(AssimpException const& e) throw() : ExceptionHandler::ExceptionHandler(e) {
            }

            AssimpException::AssimpException(AssimpException && e) throw() : ExceptionHandler::ExceptionHandler(std::move(e)) {
            }

            AssimpException::~AssimpException() throw() {
            }

            AssimpException& AssimpException::operator=(AssimpException const& e) {
                ExceptionHandler::operator=(e);
                return *this;
            }

            AssimpException& AssimpException::operator=(AssimpException && e) {
                ExceptionHandler::operator=(std::move(e));
                return *this;
            }

        };
    };
