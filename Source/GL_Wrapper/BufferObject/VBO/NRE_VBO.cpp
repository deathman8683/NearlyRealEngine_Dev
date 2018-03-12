
    #include "NRE_VBO.hpp"

    namespace NRE {
        namespace GL {

            VBO::VBO() {
            }

            VBO::VBO(bool const& generate) : NBO::NBO(generate) {
                if (generate) {
                    generateID();
                }
            }

            VBO::VBO(VBO const& buf) : NBO::NBO(buf), color(buf.getColorBuffer()) {
            }

            VBO::~VBO() {
                deleteID();
            }

            NRE::Buffer::ColorBuffer const& VBO::getColorBuffer() const {
                return color;
            }

            void VBO::setColorBuffer(NRE::Buffer::ColorBuffer const& buf) {
                color = buf;
            }

            void VBO::generateID() {
                NBO::generateID();
                color.generateID();
            }

            void VBO::deleteID() {
                color.deleteID();
                NBO::deleteID();
            }

            void VBO::reload() {
                NBO::reload();
                color.reload();
            }

            void VBO::allocate(size_t const& typeSize, size_t const& nbVertex, GLenum const& usage) {
                color.allocate(NRE::Buffer::ColorBuffer::SIZE * nbVertex * 3, usage);
                NBO::allocate(typeSize, nbVertex, usage);
            }

            void VBO::update(GLintptr const& offset, size_t const& typeSize, size_t const& nbVertex, GLvoid* const& vData, GLvoid* const& cData, GLvoid* const& nData) {
                color.update(offset, NRE::Buffer::ColorBuffer::SIZE * nbVertex * 3, cData);
                NBO::update(offset, typeSize, nbVertex, vData, nData);
            }

            void VBO::allocateAndFill(size_t typeSize, size_t const& nbVertex, GLenum const& usage, GLvoid* const& vData, GLvoid* const& cData, GLvoid* const& nData) {
                color.allocateAndFill(NRE::Buffer::ColorBuffer::SIZE * nbVertex * 3, usage, cData);
                NBO::allocateAndFill(typeSize, nbVertex, usage, vData, nData);
            }

            void VBO::access(GLenum const& vertexType, bool const& enableVAA) const {
                NBO::access(vertexType, enableVAA);
                getColorBuffer().bind();
                    glVertexAttribPointer(1, 3, NRE::Buffer::ColorBuffer::TYPE, GL_FALSE, 0, 0);
                    if (enableVAA) {
                        glEnableVertexAttribArray(1);
                    }
            }

        };
    };
