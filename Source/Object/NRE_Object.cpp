
    #include "NRE_Object.hpp"

    namespace NRE {
        namespace Object {

            Object::Object() : buffer(0), vao(true), mesh(0) {
            }

            Object::Object(GL::VBO* buf, Mesh* mesh) : buffer(buf), vao(true), mesh(mesh) {
                access();
            }

            Object::Object(Object && o) : buffer(std::move(o.buffer)), vao(std::move(o.vao)), mesh(std::move(o.mesh)) {
            }

            Object::~Object() {
                if (buffer != 0) {
                    delete buffer;
                }
                if (mesh != 0) {
                    delete mesh;
                }
            }

            void Object::add(GLuint const& index, void* value, GLuint const& nbValue) const {
                mesh->add(index, value, nbValue);
            }

            void Object::update() {
                std::vector<GLintptr> offset;
                for (GLuint i = 0; i < buffer->size(); i = i + 1) {
                    offset.push_back(0);
                }
                if (buffer->getType() == GL::INDEXBUFFEROBJECT) {
                    offset.push_back(0);
                }
                mesh->update(*buffer, offset);
            }

            void Object::allocateAndFill(GLenum const& usage) {
                mesh->allocateAndFill(*buffer, usage);
            }

            void Object::draw() const {
                vao.bind();
                    buffer->draw();
                vao.unbind();
            }

            void Object::access() {
                vao.access(*buffer, mesh->getType());
            }

            Object& Object::operator=(Object && o) {
                buffer = std::move(o.buffer);
                vao = std::move(o.vao);
                mesh = std::move(o.mesh);
                return *this;
            }

        };
    };
