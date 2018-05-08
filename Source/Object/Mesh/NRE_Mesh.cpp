
    #include "NRE_Mesh.hpp"

    namespace NRE {
        namespace Object {

            Mesh::Mesh() {
                push_back(new VertexData());
            }

            Mesh::Mesh(Mesh const& m) : data(m.data) {
            }

            Mesh::Mesh(Mesh && m) : data(std::move(m.data)) {
            }

            Mesh::~Mesh() {
                for (DataSet* d : data) {
                    delete d;
                }
                data.erase(data.begin(), data.end());
            }

            void Mesh::push_back(DataSet* const& d) {
                data.push_back(d);
            }

            void Mesh::add(GLuint const& index, void* value, GLuint const& nbValue) const {
                data[index]->add(value, nbValue);
            }

            void Mesh::updateVBO(GL::VBO const& buffer, std::vector<GLintptr> const& offset) const {
                for (GLuint i = 0; i < data.size(); i = i + 1) {
                    data[i]->update(buffer.getAttribute(i), offset[i]);
                }
            }

            void Mesh::updateIBO(GL::IBO const& buffer, std::vector<GLintptr> const& offset) const {
                for (GLuint i = 0; i < data.size() - 1; i = i + 1) {
                    data[i]->update(buffer.getAttribute(i), offset[i]);
                }
                data[data.size() - 1]->update(&(buffer.getIndexBuffer()), offset[data.size() - 1]);
            }

            void Mesh::allocateAndFillVBO(GL::VBO const& buffer, GLenum const& usage) const {
                for (GLuint i = 0; i < data.size(); i = i + 1) {
                    data[i]->update(buffer.getAttribute(i), usage);
                }
            }

            void Mesh::allocateAndFillIBO(GL::IBO const& buffer, GLenum const& usage) const {
                for (GLuint i = 0; i < data.size() - 1; i = i + 1) {
                    data[i]->allocateAndFill(buffer.getAttribute(i), usage);
                }
                data[data.size() - 1]->allocateAndFill(&(buffer.getIndexBuffer()), usage);
            }

            Mesh& Mesh::operator=(Mesh const& m) {
                data = m.data;
                return *this;
            }

            Mesh& Mesh::operator=(Mesh && m) {
                data = std::move(m.data);
                return *this;
            }

        };
    };
