
    namespace NRE {
        namespace IO {

            BinaryInputStream::BinaryInputStream() {
            }

            BinaryInputStream::BinaryInputStream(BinaryInputStream && s) {
            }

            BinaryInputStream::~BinaryInputStream() {
            }

            template <class T>
            void BinaryInputStream::readBinary(T& object, size_t const& sizeInBytes) {
                getStream().read(reinterpret_cast<char *>(&object), sizeInBytes);
            }

            BinaryInputStream& BinaryInputStream::operator=(BinaryInputStream && s) {
                return *this;
            }

        };
    };
