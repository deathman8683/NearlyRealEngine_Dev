
    #include "NRE_Object.hpp"

    namespace NRE {
        namespace Object {

            Object::Object() {
            }

            Object::Object(Object && o) : meshes(std::move(o.meshes)) {
            }

            Object::~Object() {
                for (Mesh* m : meshes) {
                    delete m;
                }
                meshes.erase(meshes.begin(), meshes.end());
            }

            void Object::add(GLuint const& meshIndex, GLuint const& setIndex, void* value, GLuint const& nbValue) const {
                meshes[meshIndex]->add(setIndex, value, nbValue);
            }

            void Object::update(GLuint const& meshIndex) {
                meshes[meshIndex]->update();
            }

            void Object::allocateAndFill(GLuint const& meshIndex, GLenum const& usage) {
                meshes[meshIndex]->allocateAndFill(usage);
            }

            void Object::draw() const {
                for (Mesh* m : meshes) {
                    m->draw();
                }
            }

            void Object::reload() {
                for (Mesh* m : meshes) {
                    m->reload();
                }
            }

            void Object::push_back(Mesh* m) {
                meshes.push_back(m);
            }

            Object& Object::operator=(Object && o) {
                meshes = std::move(o.meshes);
                return *this;
            }

        };
    };
