
    #include "NRE_VBO.hpp"

    namespace NRE {
        namespace GL {

            VBO::VBO() {
            }

            VBO::VBO(bool const& generate) {
                if (generate) {
                    generateID();
                }
            }

            VBO::VBO(VBO const& buf) : vertex(buf.getVertexBuffer()), color(buf.getColorBuffer()), normal(buf.getNormalBuffer()) {
            }

            VBO::~VBO() {
                deleteID();
            }

            NRE::Buffer::VertexBuffer const& VBO::getVertexBuffer() const {
                return vertex;
            }

            NRE::Buffer::ColorBuffer const& VBO::getColorBuffer() const {
                return color;
            }

            NRE::Buffer::NormalBuffer const& VBO::getNormalBuffer() const {
                return normal;
            }

            void VBO::setVertexBuffer(NRE::Buffer::VertexBuffer const& buf) {
                vertex = buf;
            }

            void VBO::setColorBuffer(NRE::Buffer::ColorBuffer const& buf) {
                color = buf;
            }

            void VBO::setNormalBuffer(NRE::Buffer::NormalBuffer const& buf) {
                normal = buf;
            }

            void VBO::generateID() {
                vertex.generateID();
                color.generateID();
                normal.generateID();
            }

            void VBO::deleteID() {
                vertex.deleteID();
                color.deleteID();
                normal.deleteID();
                setAllocated(false);
            }

            void VBO::reload() {
                vertex.reload();
                color.reload();
                normal.reload();
            }

            void VBO::allocate(size_t const& typeSize, size_t const& nbVertex, GLenum const& usage) {
                vertex.allocate(typeSize * nbVertex * 3, usage);
                color.allocate(NRE::Buffer::ColorBuffer::SIZE * nbVertex * 3, usage);
                normal.allocate(NRE::Buffer::NormalBuffer::SIZE * nbVertex * 3, usage);
                setAllocated(true);
            }

            void VBO::update(GLintptr const& offset, size_t const& typeSize, size_t const& nbVertex, GLvoid* const& vData, GLvoid* const& cData, GLvoid* const& nData) {
                vertex.update(offset, typeSize * nbVertex * 3, vData);
                color.update(offset, NRE::Buffer::ColorBuffer::SIZE * nbVertex * 3, cData);
                normal.update(offset, NRE::Buffer::NormalBuffer::SIZE * nbVertex * 3, nData);
            }

            void VBO::allocateAndFill(size_t typeSize, size_t const& nbVertex, GLenum const& usage, GLvoid* const& vData, GLvoid* const& cData, GLvoid* const& nData) {
                vertex.allocateAndFill(typeSize * nbVertex * 3, usage, vData);
                color.allocateAndFill(NRE::Buffer::ColorBuffer::SIZE * nbVertex * 3, usage, cData);
                normal.allocateAndFill(NRE::Buffer::NormalBuffer::SIZE * nbVertex * 3, usage, nData);
                setAllocated(true);
            }

            void VBO::access(GLenum const& vertexType, bool const& enableVAA) const {
                getVertexBuffer().bind();
                    glVertexAttribPointer(0, 3, vertexType, GL_FALSE, 0, 0);
                    if (enableVAA) {
                        glEnableVertexAttribArray(0);
                    }
                getVertexBuffer().unbind();
                getColorBuffer().bind();
                    glVertexAttribPointer(1, 3, NRE::Buffer::ColorBuffer::TYPE, GL_FALSE, 0, 0);
                    if (enableVAA) {
                        glEnableVertexAttribArray(1);
                    }
                getColorBuffer().unbind();
                getNormalBuffer().bind();
                    glVertexAttribPointer(2, 3, NRE::Buffer::NormalBuffer::TYPE, GL_FALSE, 0, 0);
                    if (enableVAA) {
                        glEnableVertexAttribArray(2);
                    }
                getNormalBuffer().unbind();
            }

        };
    };
