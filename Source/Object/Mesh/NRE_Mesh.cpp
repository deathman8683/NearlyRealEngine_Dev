
    #include "NRE_Mesh.hpp"

    namespace NRE {
        namespace Object {

            Mesh::Mesh() {
            }

            Mesh::Mesh(GLenum const& type) : type(type) {
                if (type == GL_INT) {
                    push_back(new IntVertexData());
                } else if (type == GL_FLOAT) {
                    push_back(new FloatVertexData());
                }
            }

            Mesh::Mesh(Mesh const& m) : data(m.data), type(m.type) {
            }

            Mesh::Mesh(Mesh && m) : data(std::move(m.data)), type(std::move(m.type)) {
            }

            Mesh::~Mesh() {
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

            void Mesh::update(GL::VBO& buffer, std::vector<GLintptr> const& offset) {
                if (buffer.getType() == GL::VERTEXBUFFEROBJECT) {
                    updateVBO(buffer, offset);
                } else {
                    updateIBO(static_cast <GL::IBO&> (buffer), offset);
                }
                clear();
            }

            void Mesh::allocateAndFill(GL::VBO& buffer, GLenum const& usage) {
                if (buffer.getType() == GL::VERTEXBUFFEROBJECT) {
                    allocateAndFillVBO(buffer, usage);
                } else {
                    allocateAndFillIBO(static_cast <GL::IBO&> (buffer), usage);
                }
                clear();
            }

            void Mesh::clear() {
                for (DataSet* d : data) {
                    d->clear();
                }
            }

            Mesh& Mesh::operator=(Mesh const& m) {
                data = m.data;
                type = m.type;
                return *this;
            }

            Mesh& Mesh::operator=(Mesh && m) {
                data = std::move(m.data);
                type = std::move(m.type);
                return *this;
            }

            void Mesh::updateVBO(GL::VBO& buffer, std::vector<GLintptr> const& offset) const {
                std::vector<GLvoid*> dataPointer;
                for (GLuint i = 0; i < data.size(); i = i + 1) {
                    dataPointer.push_back(data[i]->value());
                }
                buffer.update(offset,  data[0]->getTypeSize(), data[0]->size() / 3, dataPointer);
            }

            void Mesh::updateIBO(GL::IBO& buffer, std::vector<GLintptr> const& offset) const {
                std::vector<GLvoid*> dataPointer;
                for (GLuint i = 0; i < data.size(); i = i + 1) {
                    dataPointer.push_back(data[i]->value());
                }
                buffer.update(offset, data[0]->getTypeSize(), data[0]->size() / 3, data[data.size() - 1]->size(), dataPointer);
            }

            void Mesh::allocateAndFillVBO(GL::VBO& buffer, GLenum const& usage) const {
                std::vector<GLvoid*> dataPointer;
                for (GLuint i = 0; i < data.size(); i = i + 1) {
                    dataPointer.push_back(data[i]->value());
                }
                buffer.allocateAndFill(data[0]->getTypeSize(), data[0]->size() / 3, usage, dataPointer);
            }

            void Mesh::allocateAndFillIBO(GL::IBO& buffer, GLenum const& usage) const {
                std::vector<GLvoid*> dataPointer;
                for (GLuint i = 0; i < data.size(); i = i + 1) {
                    dataPointer.push_back(data[i]->value());
                }
                buffer.allocateAndFill(data[0]->getTypeSize(), data[0]->size() / 3, data[data.size() - 1]->size(), usage, dataPointer);
            }

        };
    };
