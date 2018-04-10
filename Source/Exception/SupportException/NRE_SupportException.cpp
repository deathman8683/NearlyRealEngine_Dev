
    #include "NRE_SupportException.hpp"

    namespace NRE {
        namespace Exception {

            SupportException::SupportException() throw() {
            }

            SupportException::SupportException(std::string const& log) throw() : ExceptionHandler::ExceptionHandler("SupportException : " + log) {
            }

            SupportException::SupportException(SupportException const& e) throw() : ExceptionHandler::ExceptionHandler(e) {
            }

            SupportException::~SupportException() throw() {
            }

        };
    };
