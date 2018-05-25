
    #include "NRE_OutputStream.hpp"

    namespace NRE {
        namespace IO {

            OutputStream::OutputStream() {
            }

            OutputStream::OutputStream(OutputStream && s) {
            }

            OutputStream::~OutputStream() {
            }

            std::streampos const OutputStream::getPosition() {
                return getStream().tellp();
            }

            void OutputStream::seekBegin(size_t const& offset) {
                getStream().seekp(offset, getStream().beg);
            }

            void OutputStream::seekEnd(size_t const& offset) {
                getStream().seekp(offset, getStream().end);
            }

            OutputStream& OutputStream::operator=(OutputStream && s) {
                return *this;
            }

        };
    };
