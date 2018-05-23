
    #include "NRE_FileNotOpeningException.hpp"

    namespace NRE {
        namespace Exception {

            FileNotOpeningException::FileNotOpeningException() throw() {
            }

            FileNotOpeningException::FileNotOpeningException(std::string const& log) throw() : IOException::IOException("FileNotOpeningException : " + log) {
            }

            FileNotOpeningException::FileNotOpeningException(FileNotOpeningException const& e) throw() : IOException::IOException(e) {
            }

            FileNotOpeningException::FileNotOpeningException(FileNotOpeningException && e) throw() : IOException::IOException(std::move(e)) {
            }

            FileNotOpeningException::~FileNotOpeningException() throw() {
            }

            FileNotOpeningException& FileNotOpeningException::operator=(FileNotOpeningException const& e) {
                IOException::operator=(e);
                return *this;
            }

            FileNotOpeningException& FileNotOpeningException::operator=(FileNotOpeningException && e) {
                IOException::operator=(std::move(e));
                return *this;
            }

        };
    };
