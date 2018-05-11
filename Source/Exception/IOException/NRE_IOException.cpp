
    #include "NRE_IOException.hpp"

    namespace NRE {
        namespace Exception {

            IOException::IOException() throw() {
            }

            IOException::IOException(std::string const& log) throw() : ExceptionHandler::ExceptionHandler("IOException : " + log) {
            }

            IOException::IOException(IOException const& e) throw() : ExceptionHandler::ExceptionHandler(e) {
            }

            IOException::IOException(IOException && e) throw() : ExceptionHandler::ExceptionHandler(std::move(e)) {
            }

            IOException::~IOException() throw() {
            }

            IOException& IOException::operator=(IOException const& e) {
                ExceptionHandler::operator=(e);
                return *this;
            }

            IOException& IOException::operator=(IOException && e) {
                ExceptionHandler::operator=(std::move(e));
                return *this;
            }

        };
    };
