
    #include "NRE_IBO.hpp"

    namespace NRE {
        namespace GL {

            GLenum IBO::TYPE = GL_UNSIGNED_INT;

            IBO::IBO() : nb(0) {
            }

            IBO::IBO(bool const& generate) : VBO::VBO(generate), index(generate), nb(0) {
            }

            IBO::IBO(IBO && buf) : VBO::VBO(std::move(buf)), index(std::move(buf.index)), nb(std::move(buf.nb)) {
            }

            IBO::~IBO() {
            }

            IndexBuffer const& IBO::getIndexBuffer() const {
                return index;
            }

            GLuint const& IBO::getNb() const {
                return nb;
            }

            void IBO::setNb(GLuint const& n) {
                nb = n;
            }

            VBOType const IBO::getType() const {
                return INDEXBUFFEROBJECT;
            }

            void IBO::reload() {
                index.reload();
                VBO::reload();
            }

            void IBO::allocate(GLuint const& vertexSize, size_t const& nbVertex, size_t const& nbIndex, GLenum const& usage) {
                getIndexBuffer().allocate(nbIndex * index.getTypeSize(), usage);
                VBO::allocate(vertexSize, nbVertex, usage);
                setNb(nbIndex);
            }

            void IBO::update(std::vector<GLintptr> const& offset, GLuint const& vertexSize, size_t const& nbVertex, size_t const& nbIndex, std::vector<GLvoid*> const& data) {
                getIndexBuffer().update(offset[offset.size() - 1], nbIndex * index.getTypeSize(), data[data.size() - 1]);
                VBO::update(offset, vertexSize, nbVertex, data);
                setNb(nbIndex);
            }

            void IBO::allocateAndFill(GLuint const& vertexSize, size_t const& nbVertex, size_t const& nbIndex, GLenum const& usage, std::vector<GLvoid*> const& data) {
                getIndexBuffer().allocateAndFill(nbIndex * index.getTypeSize(), usage, data[data.size() - 1]);
                VBO::allocateAndFill(vertexSize, nbVertex, usage, data);
                setNb(nbIndex);
            }

            void IBO::access(GLenum const& vertexType, bool const& enableVAA) const {
                VBO::access(vertexType, enableVAA);
                getIndexBuffer().access();
            }

            void IBO::draw() const {
                glDrawElements(GL_TRIANGLES, getNb(), TYPE, 0);
            }

            IBO& IBO::operator=(IBO && buf) {
                VBO::operator=(std::move(buf));
                index = std::move(buf.index);
                nb = std::move(buf.nb);
                return *this;
            }

        };
    };
