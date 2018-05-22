
    #include "NRE_File.hpp"

    namespace NRE {
        namespace IO {

            File::File() : File("") {
            }

            File::File(std::string const& path) : path(path) {
            }

            File::File(File const& f) : path(f.path) {
            }

            File::File(File && f) : path(std::move(f.path)) {
            }

            File::~File() {
            }

            std::string const& File::getPath() const {
                return path;
            }

            bool const File::exist() const {
                std::ifstream tmp(path.c_str());
                return tmp.good();
            }

            File& File::operator=(File const& f) {
                path = f.path;
                return *this;
            }

            File& File::operator=(File && f) {
                path = std::move(f.path);
                return *this;
            }

        };
    };
