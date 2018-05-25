
    #include "NRE_IOFile.hpp"

    namespace NRE {
        namespace IO {

            IOFile::IOFile(File const& path) : FileStream::FileStream(path) {
            }

            IOFile::IOFile(IOFile && f) : FileStream::FileStream(std::move(f)) {
            }

            IOFile::~IOFile() {
            }

            std::ios_base::openmode const IOFile::getMode() const {
                return std::ios::in | std::ios::out;
            }

            std::fstream& IOFile::getStream() {
                return FileStream::getStream();
            }

            IOFile& IOFile::operator=(IOFile && f) {
                FileStream::operator=(std::move(f));
                return *this;
            }

        };
    };
