
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

            VertexBuffer const& VBO::getVertexBuffer() const {
                return vertex;
            }

            ColorBuffer const& VBO::getColorBuffer() const {
                return color;
            }

            NormalBuffer const& VBO::getNormalBuffer() const {
                return normal;
            }

            void VBO::setVertexBuffer(VertexBuffer const& buf) {
                vertex = buf;
            }

            void VBO::setColorBuffer(ColorBuffer const& buf) {
                color = buf;
            }

            void VBO::setNormalBuffer(NormalBuffer const& buf) {
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
                color.allocate(COLOR_BUFFER_SIZE * nbVertex * 3, usage);
                normal.allocate(NORMAL_BUFFER_SIZE * nbVertex * 3, usage);
                setAllocated(true);
            }

            void VBO::update(GLintptr const& offset, size_t const& typeSize, size_t const& nbVertex, GLvoid* const& vData, GLvoid* const& cData, GLvoid* const& nData) {
                vertex.update(offset, typeSize * nbVertex * 3, vData);
                color.update(offset, COLOR_BUFFER_SIZE * nbVertex * 3, cData);
                normal.update(offset, NORMAL_BUFFER_SIZE * nbVertex * 3, cData);
            }

            void VBO::bind() const {
                vertex.bind();
                color.bind();
                normal.bind();
            }
            void VBO::unbind() const {
                vertex.unbind();
                color.unbind();
                normal.unbind();
            }

            std::ostream& operator<<(std::ostream &stream, VBO const& buf) {
                stream << "(" << buf.getVertexBuffer() << buf.getColorBuffer() << buf.getNormalBuffer() << ")";
                return stream;
            }

        };
    };
