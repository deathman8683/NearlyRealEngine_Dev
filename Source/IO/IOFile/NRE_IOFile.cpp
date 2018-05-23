
    #include "NRE_IOFile.hpp"

    namespace NRE {
        namespace IO {

            IOFile::IOFile(std::string const& path, std::ios_base::openmode mode) : File::File(path) {
                if (File::exists()) {
                    file.open(getPath(), mode);
                    if (!isOpen()) {
                        throw (Exception::FileNotOpeningException(path));
                    }
                } else {
                    throw (Exception::FileNotExistingException(path));
                }
            }

            IOFile::IOFile(IOFile && f) {
            }

            IOFile::~IOFile() {
            }

            bool const IOFile::isOpen() const {
                return file.is_open();
            }

            IOFile& IOFile::operator=(IOFile && f) {
                return *this;
            }

        };
    };
