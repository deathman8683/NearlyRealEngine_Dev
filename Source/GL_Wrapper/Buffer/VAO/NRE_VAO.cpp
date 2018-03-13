
    #include "NRE_VAO.hpp"

    namespace NRE {
        namespace GL {

            VAO::VAO() {
            }

            VAO::VAO(bool const& generate) : {
                if (generate) {
                    generateID();
                }
            }

            VAO::VAO(VAO const& buf) : Buffer::Buffer(buf) {
            }

            VAO::~VAO() {
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
                    VBO.access(vertexType, enableVAA);
                unbind();
            }

        };
    };
