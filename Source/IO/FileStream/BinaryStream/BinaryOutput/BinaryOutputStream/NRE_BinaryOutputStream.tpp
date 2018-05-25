
    namespace NRE {
        namespace IO {

            BinaryOutputStream::BinaryOutputStream() {
            }

            BinaryOutputStream::BinaryOutputStream(BinaryOutputStream && s) {
            }

            BinaryOutputStream::~BinaryOutputStream() {
            }

            template <class T>
            void BinaryOutputStream::writeBinary(T const& object, size_t const& sizeInBytes) {
                getStream().write(reinterpret_cast<char* const>(&object), sizeInBytes);
            }

            BinaryOutputStream& BinaryOutputStream::operator=(BinaryOutputStream && s) {
                return *this;
            }

        };
    };
