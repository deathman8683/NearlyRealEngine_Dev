
    #include "NRE_Object2D.hpp"

    namespace NRE {
        namespace Object {

            Object2D::Object2D() : Object(new GL::VBO(true), new Mesh2D(), GL_INT) {
                buffer->push_back(new GL::UVBuffer(true));
            }

            Object2D::Object2D(GLenum const& usage, Maths::Point2D<GLint> const& coord, Maths::Vector2D<GLint> size) : Object2D() {
                process(usage, coord, size);
            }

            Object2D::Object2D(Object2D && o) : Object::Object(std::move(o)) {
            }

            Object2D::~Object2D() {
            }

            void Object2D::process(GLenum const& usage, Maths::Point2D<GLint> const& coord, Maths::Vector2D<GLint> size) {
                static_cast <Mesh2D*> (mesh)->process(*buffer, usage, coord, size);
            }

            Object2D& Object2D::operator=(Object2D && o) {
                Object::operator=(std::move(o));
                return *this;
            }

        };
    };
