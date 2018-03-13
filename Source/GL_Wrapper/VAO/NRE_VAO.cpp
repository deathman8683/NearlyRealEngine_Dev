
    #include "NRE_VAO.hpp"

    namespace NRE {
        namespace GL {

            VAO::VAO() : id(0) {
            }

            VAO::VAO(bool const& generate) : id(0) {
                if (generate) {
                    generateID();
                }
            }

            VAO::VAO(VAO const& buf) : id(buf.getID()) {
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

            void VAO::bind() const {
                glBindVertexArray(getID());
            }

            void VAO::unbind() const {
                glBindVertexArray(0);
            }

            void VAO::access(VBO const& buffer, GLenum const& vertexType, bool const& enableVAA) const {
                bind();
                    buffer.access(vertexType, enableVAA);
                unbind();
            }

        };
    };
