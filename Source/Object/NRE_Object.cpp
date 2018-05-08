
    #include "NRE_Object.hpp"

    namespace NRE {
        namespace Object {

            Object::Object() : buffer(0), vao(true) {
            }

            Object::Object(GL::VBO* buf, GLenum const& type) : buffer(buf), vao(true) {
                vao.access(*buffer, type);
            }

            Object::Object(Object && o) : buffer(std::move(o.buffer)), vao(std::move(o.vao)) {
            }

            Object::~Object() {
                if (buffer != 0) {
                    delete buffer;
                }
            }

            void Object::draw() const {
                vao.bind();
                    buffer->draw();
                vao.unbind();
            }

            Object& Object::operator=(Object && o) {
                buffer = std::move(o.buffer);
                vao = std::move(o.vao);
                return *this;
            }

        };
    };
