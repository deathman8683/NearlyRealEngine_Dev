
    namespace NRE {
        namespace IO {

            OutputStream::OutputStream() {
            }

            OutputStream::OutputStream(OutputStream && s) {
            }

            OutputStream::~OutputStream() {
            }

            template <class T>
            void OutputStream::write(T const& object) {
                getStream() << object;
            }

            OutputStream& OutputStream::operator=(OutputStream && s) {
                return *this;
            }

        };
    };
