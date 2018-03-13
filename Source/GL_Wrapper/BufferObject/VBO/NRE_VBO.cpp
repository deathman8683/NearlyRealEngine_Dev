
    #include "NRE_VBO.hpp"

    namespace NRE {
        namespace GL {

            VBO::VBO() {
            }

            VBO::VBO(bool const& generate) {
                push_back(new VertexBuffer(generate));
            }

            VBO::VBO(VBO const& buf) : BufferObject::BufferObject(buf), attributes(buf.getAttributes()) {
            }

            VBO::~VBO() {
                for (ArrayBuffer* attr : attributes) {
                    delete attr;
                }
            }

            std::vector<ArrayBuffer*> const& VBO::getAttributes() const {
                return attributes;
            }

            ArrayBuffer* const& VBO::getAttribute(GLuint const& index) const {
                return attributes[index];
            }

            void VBO::setAttributes(std::vector<ArrayBuffer*> const& attr) {
                attributes = attr;
            }

            void VBO::setAttribute(GLuint const& index, ArrayBuffer* const& attr) {
                attributes[index] = attr;
            }

            void VBO::allocate(GLuint const& vertexSize, size_t const& nbVertex, GLenum const& usage) {
                getAttribute(0)->allocate(vertexSize * nbVertex * getAttribute(0)->getSize(), usage);
                for (GLuint i = 1; i < attributes.size(); i = i + 1) {
                    getAttribute(i)->allocate(getAttribute(i)->getTypeSize() * nbVertex * getAttribute(i)->getSize(), usage);
                }
                setAllocated(true);
            }

            void VBO::update(GLintptr const& offset, GLuint const& vertexSize, size_t const& nbVertex, std::vector<GLvoid*> const& data) {
                getAttribute(0)->update(offset, vertexSize * nbVertex * getAttribute(0)->getSize(), data[0]);
                for (GLuint i = 1; i < attributes.size(); i = i + 1) {
                    getAttribute(i)->update(offset, getAttribute(i)->getTypeSize() * nbVertex * getAttribute(i)->getSize(), data[i]);
                }
            }

            void VBO::allocateAndFill(GLuint const& vertexSize, size_t const& nbVertex, GLenum const& usage, std::vector<GLvoid*> const& data) {
                getAttribute(0)->allocateAndFill(vertexSize * nbVertex * getAttribute(0)->getSize(), usage, data[0]);
                std::cout << "Vertex : " << data[0] << std::endl;
                for (GLuint i = 1; i < attributes.size(); i = i + 1) {
                    getAttribute(i)->allocateAndFill(getAttribute(i)->getTypeSize() * nbVertex * getAttribute(i)->getSize(), usage, data[i]);
                    std::cout << "Element " << i << " : " << data[i] << std::endl;
                }
                setAllocated(true);
            }

            void VBO::access(GLenum const& vertexType, bool const& enableVAA) const {
                getAttribute(0)->access(vertexType, getAttribute(0)->getIndex(), getAttribute(0)->getSize(), enableVAA);
                for (GLuint i = 1; i < attributes.size(); i = i + 1) {
                    getAttribute(i)->access(getAttribute(i)->getType(), getAttribute(i)->getIndex(), getAttribute(i)->getSize(), enableVAA);
                }
            }

            void VBO::push_back(ArrayBuffer* const& attr) {
                attributes.push_back(attr);
            }

        };
    };
