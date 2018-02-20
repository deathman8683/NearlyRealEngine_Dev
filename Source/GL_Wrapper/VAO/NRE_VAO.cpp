
    #include "NRE_VAO.hpp"

    namespace NRE {
        namespace GL {

            VAO::VAO(bool const& generate) {
                if (generate) {
                    generateID();
                }
            }

            VAO::VAO(VAO const& arr) : id(arr.getID()) {
            }

            VAO::~VAO() {
                deleteID();
            }

            GLuint const& VAO::getID() const {
                return id;
            }

            void VAO::setID(GLuint const& id) {
                this->id = id;
            }

            void VAO::generateID() {
                glGenVertexArrays(1, &id);
            }

            void VAO::deleteID() {
                glDeleteVertexArrays(1, &id);
            }

            void VAO::reload() {
                generateID();
                deleteID();
            }

            void VAO::bind() const {
                glBindVertexArray(getID());
            }

            void VAO::unbind() const {
                glBindVertexArray(0);
            }

            std::ostream& operator<<(std::ostream &stream, VAO const& arr) {
                stream << "(" << arr.getID() << ")";
                return stream;
            }

        };
    };
