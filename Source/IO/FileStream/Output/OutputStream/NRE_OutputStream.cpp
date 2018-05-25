
    #include "NRE_OutputStream.hpp"

    namespace NRE {
        namespace IO {

            OutputStream::OutputStream() {
            }

            OutputStream::OutputStream(OutputStream && s) {
            }

            OutputStream::~OutputStream() {
            }

            OutputStream& OutputStream::operator=(OutputStream && s) {
                return *this;
            }

        };
    };
