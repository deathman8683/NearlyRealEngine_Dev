
    #include "NRE_InputFile.hpp"

    namespace NRE {
        namespace IO {

            InputFile::InputFile(File const& path) : FileStream::FileStream(path) {
            }

            InputFile::InputFile(InputFile && f) : FileStream::FileStream(std::move(f)) {
            }

            InputFile::~InputFile() {
            }

            std::ios_base::openmode const InputFile::getMode() const {
                return std::ios::in;
            }

            std::fstream& InputFile::getStream() {
                return FileStream::getStream();
            }

            InputFile& InputFile::operator=(InputFile && f) {
                FileStream::operator=(std::move(f));
                return *this;
            }

        };
    };
