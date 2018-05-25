
    #include "NRE_BinaryInputStream.hpp"

    namespace NRE {
        namespace IO {

            BinaryInputStream::BinaryInputStream() {
            }

            BinaryInputStream::BinaryInputStream(BinaryInputStream && s) {
            }

            BinaryInputStream::~BinaryInputStream() {
            }

            BinaryInputStream& BinaryInputStream::operator=(BinaryInputStream && s) {
                return *this;
            }

        };
    };
