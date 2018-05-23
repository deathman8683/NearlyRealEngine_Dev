
    #include "NRE_IOFile.hpp"

    namespace NRE {
        namespace IO {

            IOFile::IOFile() {
            }

            IOFile::IOFile(IOFile && f) {
            }

            IOFile::~IOFile() {
            }

            IOFile& IOFile::operator=(IOFile && f) {
                return *this;
            }

        };
    };
