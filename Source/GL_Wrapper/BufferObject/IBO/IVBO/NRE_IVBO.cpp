
    #include "NRE_IVBO.hpp"

    namespace NRE {
        namespace GL {

            IVBO::IVBO() {
            }

            IVBO::IVBO(bool const& generate) : VBO::VBO(generate), nb(0) {
                if (generate) {
                    generateID();
                }
            }

            IVBO::IVBO(IVBO const& buf) : VBO::VBO(buf), index(buf.getIndexBuffer()), nb(buf.getNb()) {
            }

            IVBO::~IVBO() {
                index.deleteID();
            }

            NRE::Buffer::IndexBuffer const& IVBO::getIndexBuffer() const {
                return index;
            }

            GLuint const& IVBO::getNb() const {
                return nb;
            }

            void IVBO::setIndexBuffer(NRE::Buffer::IndexBuffer const& buf) {
                index = buf;
            }

            void IVBO::setNb(GLuint const& n) {
                nb = n;
            }

            void IVBO::generateID() {
                VBO::generateID();
                index.generateID();
            }

            void IVBO::deleteID() {
                index.deleteID();
                VBO::deleteID();
            }

            void IVBO::reload() {
                VBO::reload();
                index.reload();
            }

            void IVBO::allocate(size_t const& typeSize, size_t const& nbVertex, size_t const& nbIndex, GLenum const& usage) {
                index.allocate(NRE::Buffer::IndexBuffer::SIZE * nbIndex, usage);
                VBO::allocate(typeSize, nbVertex, usage);
            }

            void IVBO::update(GLintptr const& offset, size_t const& typeSize, size_t const& nbVertex, size_t const& nbIndex, GLvoid* const& vData, GLvoid* const& cData, GLvoid* const& nData, GLvoid* const& iData) {
                index.update(offset, NRE::Buffer::IndexBuffer::SIZE * nbIndex, iData);
                setNb(nbIndex);
                VBO::update(offset, typeSize, nbVertex, vData, cData, nData);
            }

            void IVBO::allocateAndFill(size_t typeSize, size_t const& nbVertex, size_t const& nbIndex, GLenum const& usage, GLvoid* const& vData, GLvoid* const& cData, GLvoid* const& nData, GLvoid* const& iData) {
                index.allocateAndFill(NRE::Buffer::IndexBuffer::SIZE * nbIndex, usage, iData);
                setNb(nbIndex);
                VBO::allocateAndFill(typeSize, nbVertex, usage, vData, cData, nData);
            }

            void IVBO::access(GLenum const& vertexType, bool const& enableVAA) const {
                VBO::access(vertexType, enableVAA);
                getIndexBuffer().bind();
            }

        };
    };
