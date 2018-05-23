
    #include "NRE_FileNotExistingException.hpp"

    namespace NRE {
        namespace Exception {

            FileNotExistingException::FileNotExistingException() throw() {
            }

            FileNotExistingException::FileNotExistingException(std::string const& log) throw() : IOException::IOException("FileNotExistingException : " + log) {
            }

            FileNotExistingException::FileNotExistingException(FileNotExistingException const& e) throw() : IOException::IOException(e) {
            }

            FileNotExistingException::FileNotExistingException(FileNotExistingException && e) throw() : IOException::IOException(std::move(e)) {
            }

            FileNotExistingException::~FileNotExistingException() throw() {
            }

            FileNotExistingException& FileNotExistingException::operator=(FileNotExistingException const& e) {
                IOException::operator=(e);
                return *this;
            }

            FileNotExistingException& FileNotExistingException::operator=(FileNotExistingException && e) {
                IOException::operator=(std::move(e));
                return *this;
            }

        };
    };
