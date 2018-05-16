
    #include "NRE_Mesh.hpp"

    namespace NRE {
        namespace Object {

            Mesh::Mesh() : buffer(0), vao(true) {
            }

            Mesh::Mesh(GLenum const& type) : buffer(0), vao(true), type(type) {
                if (type == GL_INT) {
                    push_back(new IntVertexData());
                } else if (type == GL_FLOAT) {
                    push_back(new FloatVertexData());
                }
            }

            Mesh::Mesh(Mesh && m) : buffer(std::move(m.buffer)), vao(std::move(m.vao)), data(std::move(m.data)), type(std::move(m.type)) {
            }

            Mesh::~Mesh() {
                if (buffer != 0) {
                    delete buffer;
                }
                for (DataSet* d : data) {
                    delete d;
                }
                data.erase(data.begin(), data.end());
            }

            const DataSet* const Mesh::getDataSet(GLuint const& index) const {
                return data[index];
            }

            GLenum const& Mesh::getType() const {
                return type;
            }

            void Mesh::push_back(DataSet* const& d) {
                data.push_back(d);
            }

            void Mesh::add(GLuint const& index, const GLvoid* const value, GLuint const& nbValue) const {
                data[index]->add(value, nbValue);
            }

            void Mesh::update(std::vector<GLintptr> const& offset) {
                if (buffer->getType() == GL::VERTEXBUFFEROBJECT) {
                    updateVBO(offset);
                } else {
                    updateIBO(offset);
                }
                clear();
            }

            void Mesh::update() {
                std::vector<GLintptr> offset;
                for (GLuint i = 0; i < buffer->size(); i = i + 1) {
                    offset.push_back(0);
                }
                if (buffer->getType() == GL::INDEXBUFFEROBJECT) {
                    offset.push_back(0);
                }
                if (buffer->getType() == GL::VERTEXBUFFEROBJECT) {
                    updateVBO(offset);
                } else {
                    updateIBO(offset);
                }
                clear();
            }

            void Mesh::allocateAndFill(GLenum const& usage) {
                if (buffer->getType() == GL::VERTEXBUFFEROBJECT) {
                    allocateAndFillVBO(usage);
                } else {
                    allocateAndFillIBO(usage);
                }
                clear();
            }

            void Mesh::clear() {
                for (DataSet* d : data) {
                    d->clear();
                }
            }

            void Mesh::draw() const {
                vao.bind();
                    buffer->draw();
                vao.unbind();
            }

            void Mesh::access() {
                vao.access(*buffer, getType());
            }

            void Mesh::reload() {
                buffer->reload();
                vao.access(*buffer, getType());
            }

            Mesh& Mesh::operator=(Mesh && m) {
                buffer = std::move(m.buffer);
                vao = std::move(m.vao);
                data = std::move(m.data);
                type = std::move(m.type);
                return *this;
            }

            void Mesh::updateVBO(std::vector<GLintptr> const& offset) const {
                std::vector<GLvoid*> dataPointer;
                for (GLuint i = 0; i < data.size(); i = i + 1) {
                    dataPointer.push_back(data[i]->value());
                }
                buffer->update(offset,  data[0]->getTypeSize(), data[0]->size() / 3, dataPointer);
            }

            void Mesh::updateIBO(std::vector<GLintptr> const& offset) const {
                std::vector<GLvoid*> dataPointer;
                for (GLuint i = 0; i < data.size(); i = i + 1) {
                    dataPointer.push_back(data[i]->value());
                }
                static_cast <GL::IBO*> (buffer)->update(offset, data[0]->getTypeSize(), data[0]->size() / 3, data[data.size() - 1]->size(), dataPointer);
            }

            void Mesh::allocateAndFillVBO(GLenum const& usage) const {
                std::vector<GLvoid*> dataPointer;
                for (GLuint i = 0; i < data.size(); i = i + 1) {
                    dataPointer.push_back(data[i]->value());
                }
                buffer->allocateAndFill(data[0]->getTypeSize(), data[0]->size() / 3, usage, dataPointer);
            }

            void Mesh::allocateAndFillIBO(GLenum const& usage) const {
                std::vector<GLvoid*> dataPointer;
                for (GLuint i = 0; i < data.size(); i = i + 1) {
                    dataPointer.push_back(data[i]->value());
                }
                static_cast <GL::IBO*> (buffer)->allocateAndFill(data[0]->getTypeSize(), data[0]->size() / 3, data[data.size() - 1]->size(), usage, dataPointer);
            }

        };
    };
