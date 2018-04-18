
    #include "NRE_VAO.hpp"

    namespace NRE {
        namespace GL {

            VAO::VAO() {
            }

            VAO::VAO(bool const& generate) {
                if (generate) {
                    generateID();
                }
            }

            VAO::VAO(VAO && buf) : Buffer::Buffer(std::move(buf)) {
            }

            VAO::~VAO() {
                deleteID();
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

            VAO& VAO::operator=(VAO && buf) {
                Buffer::operator=(std::move(buf));
                return *this;
            }

        };
    };
