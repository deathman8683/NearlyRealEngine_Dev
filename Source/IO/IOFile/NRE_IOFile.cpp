
    #include "NRE_IOFile.hpp"

    namespace NRE {
        namespace IO {

            IOFile::IOFile(std::string const& path) : File::File(path) {
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

            void IOFile::open(std::ios_base::openmode mode, bool const& truncate) {
                if (truncate || exist()) {
                    if (truncate) {
                        mode = std::ios::trunc | mode;
                    }
                    file.open(path, mode);
                    if (!isOpen()) {
                        throw (Exception::FileNotOpeningException(path));
                    }
                } else {
                    throw (Exception::FileNotExistingException(path));
                }
            }

            void IOFile::write(std::stringstream& data) {
                file << data.rdbuf();
            }

            IOFile& IOFile::operator=(IOFile && f) {
                File::operator=(f);
                file = std::move(f.file);
                return *this;
            }

        };
    };
