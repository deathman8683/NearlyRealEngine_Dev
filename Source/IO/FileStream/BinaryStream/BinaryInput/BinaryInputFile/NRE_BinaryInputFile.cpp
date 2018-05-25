
    #include "NRE_BinaryInputFile.hpp"

    namespace NRE {
        namespace IO {

            BinaryInputFile::BinaryInputFile(File const& path) : InputFile::InputFile(path) {
            }

            BinaryInputFile::BinaryInputFile(BinaryInputFile && f) : InputFile::InputFile(std::move(f)) {
            }

            BinaryInputFile::~BinaryInputFile() {
            }

            std::ios_base::openmode const BinaryInputFile::getMode() const {
                return std::ios::out | std::ios::binary;
            }

            std::fstream& BinaryInputFile::getStream() {
                return InputFile::getStream();
            }

            BinaryInputFile& BinaryInputFile::operator=(BinaryInputFile && f) {
                InputFile::operator=(std::move(f));
                return *this;
            }

        };
    };
