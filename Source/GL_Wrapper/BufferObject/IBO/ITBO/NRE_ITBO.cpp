
    #include "NRE_ITBO.hpp"

    namespace NRE {
        namespace GL {

            ITBO::ITBO() {
            }

            ITBO::ITBO(bool const& generate) : TBO::TBO(generate), nb(0) {
                if (generate) {
                    generateID();
                }
            }

            ITBO::ITBO(ITBO const& buf) : TBO::TBO(buf), index(buf.getIndexBuffer()), nb(buf.getNb()) {
            }

            ITBO::~ITBO() {
                index.deleteID();
            }

            NRE::Buffer::IndexBuffer const& ITBO::getIndexBuffer() const {
                return index;
            }

            GLuint const& ITBO::getNb() const {
                return nb;
            }

            void ITBO::setIndexBuffer(NRE::Buffer::IndexBuffer const& buf) {
                index = buf;
            }

            void ITBO::setNb(GLuint const& n) {
                nb = n;
            }

            void ITBO::generateID() {
                TBO::generateID();
                index.generateID();
            }

            void ITBO::deleteID() {
                index.deleteID();
                TBO::deleteID();
            }

            void ITBO::reload() {
                TBO::reload();
                index.reload();
            }

            void ITBO::allocate(size_t const& typeSize, size_t const& nbVertex, size_t const& nbIndex, GLenum const& usage) {
                index.allocate(NRE::Buffer::IndexBuffer::SIZE * nbIndex, usage);
                TBO::allocate(typeSize, nbVertex, usage);
            }

            void ITBO::update(GLintptr const& offset, size_t const& typeSize, size_t const& nbVertex, size_t const& nbIndex, GLvoid* const& vData, GLvoid* const& uvData, GLvoid* const& nData, GLvoid* const& iData) {
                index.update(offset, NRE::Buffer::IndexBuffer::SIZE * nbIndex, iData);
                setNb(nbIndex);
                TBO::update(offset, typeSize, nbVertex, vData, uvData, nData);
            }

            void ITBO::allocateAndFill(size_t typeSize, size_t const& nbVertex, size_t const& nbIndex, GLenum const& usage, GLvoid* const& vData, GLvoid* const& uvData, GLvoid* const& nData, GLvoid* const& iData) {
                index.allocateAndFill(NRE::Buffer::IndexBuffer::SIZE * nbIndex, usage, iData);
                setNb(nbIndex);
                TBO::allocateAndFill(typeSize, nbVertex, usage, vData, uvData, nData);
            }

            void ITBO::access(GLenum const& vertexType, bool const& enableVAA) const {
                TBO::access(vertexType, enableVAA);
                getIndexBuffer().bind();
            }

        };
    };
