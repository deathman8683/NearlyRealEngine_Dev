
    #include "NRE_ExceptionHandler.hpp"

    namespace NRE {
        namespace Exception {

            ExceptionHandler::ExceptionHandler() throw() : log("") {
            }

            ExceptionHandler::ExceptionHandler(std::string const& log) throw() : log(log) {
            }

            ExceptionHandler::ExceptionHandler(ExceptionHandler const& e) throw() : log(e.getLog()) {
            }

            ExceptionHandler::ExceptionHandler(ExceptionHandler && e) throw() : log(std::move(e.getLog())) {
            }

            ExceptionHandler::~ExceptionHandler() throw() {
            }

            std::string const& ExceptionHandler::getLog() const throw() {
                return log;
            }

            const char* ExceptionHandler::what() const throw() {
                return getLog().c_str();
            }

            ExceptionHandler& ExceptionHandler::operator=(ExceptionHandler const& e) {
                log = e.getLog();
                return *this;
            }

            ExceptionHandler& ExceptionHandler::operator=(ExceptionHandler && e) {
                log = std::move(e.getLog());
                return *this;
            }

        };
    };
