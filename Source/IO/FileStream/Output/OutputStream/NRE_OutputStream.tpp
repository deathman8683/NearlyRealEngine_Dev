
    namespace NRE {
        namespace IO {

            template <class T>
            void OutputStream::write(T const& object) {
                getStream() << object;
            }
            
        };
    };
