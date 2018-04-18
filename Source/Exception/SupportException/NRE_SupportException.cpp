
    #include "NRE_SupportException.hpp"

    namespace NRE {
        namespace Exception {

            SupportException::SupportException() throw() {
            }

            SupportException::SupportException(std::string const& log) throw() : ExceptionHandler::ExceptionHandler("SupportException : " + log) {
            }

            SupportException::SupportException(SupportException const& e) throw() : ExceptionHandler::ExceptionHandler(e) {
            }

            SupportException::SupportException(SupportException && e) throw() : ExceptionHandler::ExceptionHandler(std::move(e)) {
            }

            SupportException::~SupportException() throw() {
            }

            SupportException& SupportException::operator=(SupportException const& e) {
                ExceptionHandler::operator=(e);
                return *this;
            }

            SupportException& SupportException::operator=(SupportException && e) {
                ExceptionHandler::operator=(std::move(e));
                return *this;
            }

        };
    };
