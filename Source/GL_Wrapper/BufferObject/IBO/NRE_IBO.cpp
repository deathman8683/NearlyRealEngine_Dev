
    #include "NRE_IBO.hpp"

    namespace NRE {
        namespace GL {

            IBO::IBO() {
            }

            IBO::IBO(bool const& generate) : VBO::VBO(generate), nb(0) {
                if (generate) {
                    generateID();
                }
            }

            IBO::IBO(IBO const& buf) : VBO::VBO(buf), index(buf.getIndexBuffer()), nb(buf.getNb()) {
            }

            IBO::~IBO() {
                index.deleteID();
            }

            NRE::Buffer::IndexBuffer const& IBO::getIndexBuffer() const {
                return index;
            }

            GLuint const& IBO::getNb() const {
                return nb;
            }

            void IBO::setIndexBuffer(NRE::Buffer::IndexBuffer const& buf) {
                index = buf;
            }

            void IBO::setNb(GLuint const& n) {
                nb = n;
            }

            void IBO::generateID() {
                VBO::generateID();
                index.generateID();
            }

            void IBO::deleteID() {
                index.deleteID();
                VBO::deleteID();
            }

            void IBO::reload() {
                VBO::reload();
                index.reload();
            }

            void IBO::allocate(size_t const& typeSize, size_t const& nbVertex, size_t const& nbIndex, GLenum const& usage) {
                index.allocate(NRE::Buffer::IndexBuffer::SIZE * nbIndex, usage);
                VBO::allocate(typeSize, nbVertex, usage);
            }

            void IBO::update(GLintptr const& offset, size_t const& typeSize, size_t const& nbVertex, size_t const& nbIndex, GLvoid* const& vData, GLvoid* const& cData, GLvoid* const& nData, GLvoid* const& iData) {
                index.update(offset, NRE::Buffer::IndexBuffer::SIZE * nbIndex, iData);
                setNb(nbIndex);
                VBO::update(offset, typeSize, nbVertex, vData, cData, nData);
            }

            void IBO::allocateAndFill(size_t typeSize, size_t const& nbVertex, size_t const& nbIndex, GLenum const& usage, GLvoid* const& vData, GLvoid* const& cData, GLvoid* const& nData, GLvoid* const& iData) {
                index.allocateAndFill(NRE::Buffer::IndexBuffer::SIZE * nbIndex, usage, iData);
                setNb(nbIndex);
                VBO::allocateAndFill(typeSize, nbVertex, usage, vData, cData, nData);
            }

            void IBO::access(GLenum const& vertexType, bool const& enableVAA) const {
                VBO::access(vertexType, enableVAA);
                getIndexBuffer().bind();
                    glVertexAttribPointer(3, 3, NRE::Buffer::IndexBuffer::TYPE, GL_FALSE, 0, 0);
                    if (enableVAA) {
                        glEnableVertexAttribArray(3);
                    }
                getIndexBuffer().unbind();
            }

        };
    };
