
    #include "NRE_BinaryIOFile.hpp"

    namespace NRE {
        namespace IO {

            BinaryIOFile::BinaryIOFile(File const& path) : IOFile::IOFile(path) {
            }

            BinaryIOFile::BinaryIOFile(BinaryIOFile && f) : IOFile::IOFile(std::move(f)) {
            }

            BinaryIOFile::~BinaryIOFile() {
            }

            std::ios_base::openmode const BinaryIOFile::getMode() const {
                return std::ios::in | std::ios::out | std::ios::binary;
            }

            std::fstream& BinaryIOFile::getStream() {
                return IOFile::getStream();
            }

            BinaryIOFile& BinaryIOFile::operator=(BinaryIOFile && f) {
                IOFile::operator=(std::move(f));
                return *this;
            }

        };
    };
