
    #include "NRE_VBO.hpp"

    namespace NRE {
        namespace GL {

            VBO::VBO() {
            }

            VBO::VBO(bool const& generate) {
                push_back(new VertexBuffer(generate));
            }

            VBO::VBO(VBO && buf) : BufferObject::BufferObject(std::move(buf)), attributes(std::move(buf.attributes)) {
            }

            VBO::~VBO() {
                for (ArrayBuffer* attr : attributes) {
                    delete attr;
                }
                attributes.erase(attributes.begin(), attributes.end());
            }

            ArrayBuffer* const& VBO::getAttribute(GLuint const& index) const {
                return attributes[index];
            }

            GLuint const& VBO::getNb() const {
                return nb;
            }

            void VBO::setNb(GLuint const& n) {
                nb = n;
            }

            VBOType const VBO::getType() const {
                return VERTEXBUFFEROBJECT;
            }

            void VBO::reload() {
                for (GLuint i = 0; i < attributes.size(); i = i + 1) {
                    getAttribute(i)->reload();
                }
                setAllocated(false);
            }

            void VBO::allocate(GLuint const& vertexSize, size_t const& nbVertex, GLenum const& usage) {
                getAttribute(0)->allocate(vertexSize * nbVertex * getAttribute(0)->getSize(), usage);
                for (GLuint i = 1; i < attributes.size(); i = i + 1) {
                    getAttribute(i)->allocate(getAttribute(i)->getTypeSize() * nbVertex * getAttribute(i)->getSize(), usage);
                }
                setAllocated(true);
                setNb(nbVertex);
            }

            void VBO::update(std::vector<GLintptr> const& offset, GLuint const& vertexSize, size_t const& nbVertex, std::vector<GLvoid*> const& data) {
                getAttribute(0)->update(offset[0], vertexSize * nbVertex * getAttribute(0)->getSize(), data[0]);
                for (GLuint i = 1; i < attributes.size(); i = i + 1) {
                    getAttribute(i)->update(offset[i], getAttribute(i)->getTypeSize() * nbVertex * getAttribute(i)->getSize(), data[i]);
                }
                setNb(nbVertex);
            }

            void VBO::allocateAndFill(GLuint const& vertexSize, size_t const& nbVertex, GLenum const& usage, std::vector<GLvoid*> const& data) {
                getAttribute(0)->allocateAndFill(vertexSize * nbVertex * getAttribute(0)->getSize(), usage, data[0]);
                for (GLuint i = 1; i < attributes.size(); i = i + 1) {
                    getAttribute(i)->allocateAndFill(getAttribute(i)->getTypeSize() * nbVertex * getAttribute(i)->getSize(), usage, data[i]);
                }
                setAllocated(true);
                setNb(nbVertex);
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

            GLuint const VBO::size() const {
                return attributes.size();
            }

            void VBO::draw() const {
                glDrawArrays(GL_TRIANGLES, 0, getNb());
            }

            VBO& VBO::operator=(VBO && buf) {
                BufferObject::operator=(std::move(buf));
                attributes = std::move(buf.attributes);
                return *this;
            }

        };
    };
