
    #include "NRE_InputStream.hpp"

    namespace NRE {
        namespace IO {

            InputStream::InputStream() {
            }

            InputStream::InputStream(InputStream && s) {
            }

            InputStream::~InputStream() {
            }

            std::streampos const InputStream::getPosition() {
                return getStream().tellg();
            }

            bool const InputStream::readLine(std::string &line) {
                return (std::getline(getStream(), line)) ? true : false;
            }

            void InputStream::seekBegin(size_t const& offset) {
                getStream().seekg(offset, getStream().beg);
            }

            void InputStream::seekEnd(size_t const& offset) {
                getStream().seekg(offset, getStream().end);
            }

            InputStream& InputStream::operator=(InputStream && s) {
                return *this;
            }

        };
    };
