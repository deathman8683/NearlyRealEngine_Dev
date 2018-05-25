
    namespace NRE {
        namespace IO {

            template <class T>
            void BinaryOutputStream::writeBinary(T const& object, size_t const& sizeInBytes) {
                getStream().write(reinterpret_cast<char* const>(&object), sizeInBytes);
            }

        };
    };
