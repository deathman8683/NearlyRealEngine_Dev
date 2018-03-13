
    #include "NRE_IBO.hpp"

    namespace NRE {
        namespace GL {

            IBO::IBO() : nb(0) {
            }

            IBO::IBO(bool const& generate) : VBO::VBO(generate), index(generate), nb(0) {
            }

            IBO::IBO(IBO const& buf) : VBO::VBO(buf), index(buf.getIndexBuffer()), nb(buf.getNb()) {
            }

            IBO::~IBO() {
            }

            IndexBuffer const& IBO::getIndexBuffer() const {
                return index;
            }

            GLuint const& IBO::getNb() const {
                return nb;
            }

            void IBO::setIndexBuffer(IndexBuffer const buf) {
                index = buf;
            }

            void IBO::setNb(GLuint const& n) {
                nb = n;
            }

            void IBO::allocate(GLuint const& vertexSize, size_t const& nbVertex, size_t const& nbIndex, GLenum const& usage) {
                getIndexBuffer().allocate(nbIndex * index.getTypeSize(), usage);
                VBO::allocate(vertexSize, nbVertex, usage);
            }

            void IBO::update(GLintptr const& offset, GLuint const& vertexSize, size_t const& nbVertex, size_t const& nbIndex, std::vector<GLvoid*> const& data, GLvoid* const& iData) {
                getIndexBuffer().update(offset, nbIndex * index.getTypeSize(), iData);
                VBO::update(offset, vertexSize, nbVertex, data);
            }

            void IBO::allocateAndFill(GLuint const& vertexSize, size_t const& nbVertex, size_t const& nbIndex, GLenum const& usage, std::vector<GLvoid*> const& data, GLvoid* const& iData) {
                getIndexBuffer().allocateAndFill(nbIndex * index.getTypeSize(), usage, iData);
                VBO::allocateAndFill(vertexSize, nbVertex, usage, data);
            }

            void IBO::access(GLenum const& vertexType, bool const& enableVAA) const {
                VBO::access(vertexType, enableVAA);
                getIndexBuffer().access();
            }

        };
    };
