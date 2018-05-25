
    #include "NRE_InputStream.hpp"

    namespace NRE {
        namespace IO {

            InputStream::InputStream() {
            }

            InputStream::InputStream(InputStream && s) {
            }

            InputStream::~InputStream() {
            }

            InputStream& InputStream::operator=(InputStream && s) {
                return *this;
            }

        };
    };
