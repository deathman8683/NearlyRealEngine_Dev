
    #include "NRE_NBO.hpp"

    namespace NRE {
        namespace GL {

            NBO::NBO() {
            }

            NBO::NBO(bool const& generate) {
                if (generate) {
                    generateID();
                }
            }

            NBO::NBO(NBO const& buf) : vertex(buf.getVertexBuffer()), normal(buf.getNormalBuffer()) {
            }

            NBO::~NBO() {
                deleteID();
            }

            NRE::Buffer::VertexBuffer const& NBO::getVertexBuffer() const {
                return vertex;
            }

            NRE::Buffer::NormalBuffer const& NBO::getNormalBuffer() const {
                return normal;
            }

            void NBO::setVertexBuffer(NRE::Buffer::VertexBuffer const& buf) {
                vertex = buf;
            }

            void NBO::setNormalBuffer(NRE::Buffer::NormalBuffer const& buf) {
                normal = buf;
            }

            void NBO::generateID() {
                vertex.generateID();
                normal.generateID();
            }

            void NBO::deleteID() {
                vertex.deleteID();
                normal.deleteID();
                setAllocated(false);
            }

            void NBO::reload() {
                vertex.reload();
                normal.reload();
            }

            void NBO::allocate(size_t const& typeSize, size_t const& nbVertex, GLenum const& usage) {
                vertex.allocate(typeSize * nbVertex * 3, usage);
                normal.allocate(NRE::Buffer::NormalBuffer::SIZE * nbVertex * 3, usage);
                setAllocated(true);
            }

            void NBO::update(GLintptr const& offset, size_t const& typeSize, size_t const& nbVertex, GLvoid* const& vData, GLvoid* const& nData) {
                vertex.update(offset, typeSize * nbVertex * 3, vData);
                normal.update(offset, NRE::Buffer::NormalBuffer::SIZE * nbVertex * 3, nData);
            }

            void NBO::allocateAndFill(size_t typeSize, size_t const& nbVertex, GLenum const& usage, GLvoid* const& vData, GLvoid* const& nData) {
                vertex.allocateAndFill(typeSize * nbVertex * 3, usage, vData);
                normal.allocateAndFill(NRE::Buffer::NormalBuffer::SIZE * nbVertex * 3, usage, nData);
                setAllocated(true);
            }

            void NBO::access(GLenum const& vertexType, bool const& enableVAA) const {
                getVertexBuffer().bind();
                    glVertexAttribPointer(0, 3, vertexType, GL_FALSE, 0, 0);
                    if (enableVAA) {
                        glEnableVertexAttribArray(0);
                    }
                getNormalBuffer().bind();
                    glVertexAttribPointer(2, 3, NRE::Buffer::NormalBuffer::TYPE, GL_FALSE, 0, 0);
                    if (enableVAA) {
                        glEnableVertexAttribArray(2);
                    }
            }

        };
    };
