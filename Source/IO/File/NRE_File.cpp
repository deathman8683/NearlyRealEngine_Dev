
    #include "NRE_File.hpp"

    namespace NRE {
        namespace IO {

            File::File() : path("") {
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

            void File::setPath(std::string const& path) {
                this->path = path;
            }

            bool const File::exist() const {
                if (path.empty()) {
                    return false;
                }

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
