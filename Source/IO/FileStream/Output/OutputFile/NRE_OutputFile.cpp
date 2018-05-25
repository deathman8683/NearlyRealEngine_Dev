
    #include "NRE_OutputFile.hpp"

    namespace NRE {
        namespace IO {

            OutputFile::OutputFile(std::string const& path) : FileStream::FileStream(path) {
            }

            OutputFile::OutputFile(OutputFile && f) : FileStream::FileStream(std::move(f)) {
            }

            OutputFile::~OutputFile() {
            }

            std::fstream& OutputFile::getStream() {
                return FileStream::getStream();
            }

            std::ios_base::openmode const OutputFile::getMode() const {
                return std::ios::out;
            }

            OutputFile& OutputFile::operator=(OutputFile && f) {
                FileStream::operator=(std::move(f));
                return *this;
            }

        };
    };
