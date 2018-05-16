
    #include "NRE_Object3D.hpp"

    namespace NRE {
        namespace Object {

            Object3D::Object3D() {
            }

            Object3D::Object3D(Object3D && o) : Object::Object(std::move(o)) {
            }

            Object3D::~Object3D() {
            }

            void Object3D::loadOBJ(std::string const& path) {
                MeshLoader loader(static_cast <Mesh3D*> (meshes[0]), path);
                static_cast <Mesh3D*> (meshes[0])->allocateAndFill(GL_STATIC_DRAW);
            }

            void Object3D::processSphere(GLenum const& usage, NREfloat const& radius, NREfloat const& rings, NREfloat const& sectors, GLubyte const& type) {
                static_cast <Mesh3D*> (meshes[0])->processSphere(usage, radius, rings, sectors, type);
            }

            Object3D& Object3D::operator=(Object3D && o) {
                Object::operator=(std::move(o));
                return *this;
            }

        };
    };
