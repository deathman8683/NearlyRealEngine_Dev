
    namespace NRE {
        namespace IO {

            InputStream::InputStream() {
            }

            InputStream::InputStream(InputStream && s) {
            }

            InputStream::~InputStream() {
            }

            template <class T>
            void InputStream::read(T& object) {
                getStream() >> object;
            }

            InputStream& InputStream::operator=(InputStream && s) {
                return *this;
            }

        };
    };
