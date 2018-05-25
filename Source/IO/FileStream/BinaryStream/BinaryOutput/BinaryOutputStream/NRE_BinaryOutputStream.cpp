
    #include "NRE_BinaryOutputStream.hpp"

    namespace NRE {
        namespace IO {

            BinaryOutputStream::BinaryOutputStream() {
            }

            BinaryOutputStream::BinaryOutputStream(BinaryOutputStream && s) {
            }

            BinaryOutputStream::~BinaryOutputStream() {
            }

            BinaryOutputStream& BinaryOutputStream::operator=(BinaryOutputStream && s) {
                return *this;
            }

        };
    };
