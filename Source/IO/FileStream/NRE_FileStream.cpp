
    #include "NRE_FileStream.hpp"

    namespace NRE {
        namespace IO {

            FileStream::FileStream(std::string const& path) : File::File(path) {
            }

            FileStream::FileStream(FileStream && f) : File::File(std::move(f)), file(std::move(f.file)) {
            }

            FileStream::~FileStream() {
            }

            bool const FileStream::isOpen() const {
                return file.is_open();
            }

            void FileStream::open() {
                if (exist()) {
                    file.open(path, getMode());
                    if (!isOpen()) {
                        throw (Exception::FileNotOpeningException(path));
                    }
                } else {
                    throw (Exception::FileNotExistingException(path));
                }
            }

            void FileStream::openEmpty() {
                file.open(path, std::ios::trunc | getMode());
                if (!isOpen()) {
                    throw (Exception::FileNotOpeningException(path));
                }
            }

            FileStream& FileStream::operator=(FileStream && f) {
                File::operator=(std::move(f));
                file = std::move(f.file);
                return *this;
            }

            std::fstream& FileStream::getStream() {
                return file;
            }

        };
    };
