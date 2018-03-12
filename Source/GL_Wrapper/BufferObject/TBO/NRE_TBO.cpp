
    #include "NRE_TBO.hpp"

    namespace NRE {
        namespace GL {

            TBO::TBO() {
            }

            TBO::TBO(bool const& generate) : NBO::NBO(generate) {
                if (generate) {
                    generateID();
                }
            }

            TBO::TBO(TBO const& buf) : NBO::NBO(buf), uv(buf.getUVBuffer()) {
            }

            TBO::~TBO() {
                deleteID();
            }

            NRE::Buffer::UVBuffer const& TBO::getUVBuffer() const {
                return uv;
            }

            void TBO::setUVBuffer(NRE::Buffer::UVBuffer const& buf) {
                uv = buf;
            }

            void TBO::generateID() {
                NBO::generateID();
                uv.generateID();
            }

            void TBO::deleteID() {
                uv.deleteID();
                NBO::deleteID();
            }

            void TBO::reload() {
                NBO::reload();
                uv.reload();
            }

            void TBO::allocate(size_t const& typeSize, size_t const& nbVertex, GLenum const& usage) {
                uv.allocate(NRE::Buffer::UVBuffer::SIZE * nbVertex * 2, usage);
                NBO::allocate(typeSize, nbVertex, usage);
            }

            void TBO::update(GLintptr const& offset, size_t const& typeSize, size_t const& nbVertex, GLvoid* const& vData, GLvoid* const& uvData, GLvoid* const& nData) {
                uv.update(offset, NRE::Buffer::UVBuffer::SIZE * nbVertex * 2, uvData);
                NBO::update(offset, typeSize, nbVertex, vData, nData);
            }

            void TBO::allocateAndFill(size_t typeSize, size_t const& nbVertex, GLenum const& usage, GLvoid* const& vData, GLvoid* const& uvData, GLvoid* const& nData) {
                uv.allocateAndFill(NRE::Buffer::UVBuffer::SIZE * nbVertex * 2, usage, uvData);
                NBO::allocateAndFill(typeSize, nbVertex, usage, vData, nData);
            }

            void TBO::access(GLenum const& vertexType, bool const& enableVAA) const {
                NBO::access(vertexType, enableVAA);
                getUVBuffer().bind();
                    glVertexAttribPointer(3, 2, NRE::Buffer::UVBuffer::TYPE, GL_FALSE, 0, 0);
                    if (enableVAA) {
                        glEnableVertexAttribArray(3);
                    }
            }

        };
    };
