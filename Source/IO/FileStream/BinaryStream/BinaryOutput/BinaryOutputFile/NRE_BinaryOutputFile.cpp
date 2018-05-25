
    #include "NRE_BinaryOutputFile.hpp"

    namespace NRE {
        namespace IO {

            BinaryOutputFile::BinaryOutputFile(std::string const& path) : OutputFile::OutputFile(path) {
            }

            BinaryOutputFile::BinaryOutputFile(BinaryOutputFile && f) : OutputFile::OutputFile(std::move(f)) {
            }

            BinaryOutputFile::~BinaryOutputFile() {
            }

            std::ios_base::openmode const BinaryOutputFile::getMode() const {
                return std::ios::out | std::ios::binary;
            }

            std::fstream& BinaryOutputFile::getStream() {
                return OutputFile::getStream();
            }

            BinaryOutputFile& BinaryOutputFile::operator=(BinaryOutputFile && f) {
                OutputFile::operator=(std::move(f));
                return *this;
            }

        };
    };
