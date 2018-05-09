
    #include "NRE_Object3D.hpp"

    namespace NRE {
        namespace Object {

            Object3D::Object3D() {
            }

            Object3D::Object3D(Object3D && o) : Object::Object(std::move(o)) {
            }

            Object3D::~Object3D() {
            }

            Object3D& Object3D::operator=(Object3D && o) {
                Object::operator=(std::move(o));
                return *this;
            }

        };
    };
