
    #include "NRE_VBO.hpp"

    namespace NRE {
        namespace GL {

            VBO::VBO() {
            }

            VBO::VBO(bool const& generate) {
                attributes.push_back(new VertexBuffer(generate));
            }

            VBO::VBO(VBO const& buf) : attributes(buf.getAttributes()) {
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
                for (ArrayBuffer* attr : attributes) {
                    attr->allocate(attr->getTypeSize() * nbVertex * attr->getSize(), usage);
                }
            }

            void VBO::update(GLintptr const& offset, GLuint const& typeSize, size_t const& nbVertex, std::vector<GLvoid*> const& data) {
                    getAttribute(0)->update(offset, vertexSize * nbVertex * getAttribute(0)->getSize(), data[0]);
                    for (GLuint i = 1; i < attributes.size(); i = i + 1) {
                        getAttribute(i)->update(offset, getAttribute(i)->getTypeSize() * nbVertex * getAttribute(i)->getSize(), date[i]);
                    }
            }

            void VBO::allocateAndFill(GLuint typeSize, size_t const& nbVertex, GLenum const& usage, std::vector<GLvoid*> const& data) {
                    getAttribute(0)->allocateAndFill(vertexSize * nbVertex * getAttribute(0)->getSize(), usage, data[0]);
                    for (GLuint i = 0; i < attributes.size(); i = i + 1) {
                        getAttribute(i)->allocateAndFill(getAttribute(i)->getTypeSize() * nbVertex * getAttribute(i)->getSize(), usage, date[i]);
                    }
            }

            void VBO::access(GLenum const& vertexType, bool const& enableVAA) const {
                getAttribute(0)->access(vertexType, enableVAA);
                for (GLuint i = 0; i < attributes.size(); i = i + 1) {
                    getAttribute(i)->access(enableVAA);
                }
            }

        };
    };
