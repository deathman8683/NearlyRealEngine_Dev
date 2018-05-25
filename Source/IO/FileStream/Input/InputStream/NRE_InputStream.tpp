
    namespace NRE {
        namespace IO {

            template <class T>
            void InputStream::read(T& object) {
                getStream() >> object;
            }
            
        };
    };
