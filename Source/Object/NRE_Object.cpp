
    #include "NRE_Object.hpp"

    namespace NRE {
        namespace Object {

            Object::Object() : mesh(0) {
            }

            Object::Object(Mesh* mesh) : mesh(mesh) {
            }

            Object::Object(Object && o) : mesh(std::move(o.mesh)) {
            }

            Object::~Object() {
                if (mesh != 0) {
                    delete mesh;
                }
            }

            void Object::add(GLuint const& index, void* value, GLuint const& nbValue) const {
                mesh->add(index, value, nbValue);
            }

            void Object::update() {
                mesh->update();
            }

            void Object::allocateAndFill(GLenum const& usage) {
                mesh->allocateAndFill(usage);
            }

            void Object::draw() const {
                mesh->draw();
            }

            void Object::reload() {
                mesh->reload();
            }

            Object& Object::operator=(Object && o) {
                mesh = std::move(o.mesh);
                return *this;
            }

        };
    };
