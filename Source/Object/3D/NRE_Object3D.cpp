
    #include "NRE_Object3D.hpp"

    namespace NRE {
        namespace Object {

            Object3D::Object3D() {
            }

            Object3D::Object3D(Maths::Vector3D<GLuint> size) : model(size) {
                buffer = new GL::IBO(true);
                buffer->push_back(new GL::MaterialBuffer(true));
                buffer->push_back(new GL::NormalBuffer(true));

                mesh = new Mesh3D(&model, 0, 0, 0, 0, 0, 0);

                access(GL_INT);
            }

            Object3D::Object3D(Object3D && o) : Object::Object(std::move(o)), model(std::move(o.model)) {
            }

            Object3D::~Object3D() {
            }

            void Object3D::process(GLenum const& usage, Maths::Point2D<GLint> const& coord) {
                static_cast <Mesh3D*> (mesh)->process(*(static_cast<GL::IBO*> (buffer)), usage, coord);
            }

            void Object3D::loadVoxels(GLuint &x, GLuint &y, GLuint &z, GLuint const& nb, GLuint const& type) {
                model.loadVoxels(x, y, z, nb, type);
            }

            Object3D& Object3D::operator=(Object3D && o) {
                Object::operator=(std::move(o));
                model = std::move(o.model);
                return *this;
            }

        };
    };
