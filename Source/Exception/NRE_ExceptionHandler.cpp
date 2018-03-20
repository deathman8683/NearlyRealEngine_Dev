
    #include "NRE_ExceptionHandler.hpp"

    namespace NRE {
        namespace Exception {

            ExceptionHandler::ExceptionHandler() throw() : log("") {
            }

            ExceptionHandler::ExceptionHandler(std::string const& log) throw() : log(log) {
            }

            ExceptionHandler::ExceptionHandler(ExceptionHandler const& e) throw() : log(e.getLog()) {
            }

            ExceptionHandler::~ExceptionHandler() throw() {
            }

            std::string const& ExceptionHandler::getLog() const throw() {
                return log;
            }

            void ExceptionHandler::setLog(std::string const& log) throw() {
                this->log = log;
            }

            const char* ExceptionHandler::what() const throw() {
                return getLog().c_str();
            }

        };
    };
