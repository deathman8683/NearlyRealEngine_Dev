
    #include "NRE_IOFile.hpp"

    namespace NRE {
        namespace IO {

            IOFile::IOFile(std::string const& path, std::ios_base::openmode mode) : File::File(path) {
                if (File::exist()) {
                    file.open(getPath(), mode);
                    if (!isOpen()) {
                        throw (Exception::FileNotOpeningException(path));
                    }
                } else {
                    throw (Exception::FileNotExistingException(path));
                }
            }

            IOFile::IOFile(IOFile && f) : File::File(std::move(f)), file(std::move(f.file)) {
            }

            IOFile::~IOFile() {
            }

            std::fstream& IOFile::getStream() {
                return file;
            }

            bool const IOFile::isOpen() const {
                return file.is_open();
            }

            IOFile& IOFile::operator=(IOFile && f) {
                File::operator=(f);
                file = std::move(f.file);
                return *this;
            }

        };
    };
