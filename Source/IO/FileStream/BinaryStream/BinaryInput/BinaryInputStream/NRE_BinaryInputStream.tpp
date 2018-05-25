
    namespace NRE {
        namespace IO {

            template <class T>
            void BinaryInputStream::readBinary(T& object, size_t const& sizeInBytes) {
                getStream().read(reinterpret_cast<char *>(&object), sizeInBytes);
            }
            
        };
    };
