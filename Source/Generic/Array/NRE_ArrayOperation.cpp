
    #include "NRE_ArrayOperation.hpp"

    namespace NRE {
        namespace Array {

            GLuint const get1DIndexFrom3D(Maths::Point3D<GLuint> const& p, Maths::Vector3D<GLuint> const& size) {
                return get1DIndexFrom3D(p.getX(), p.getY(), p.getZ(), size);
            }

            GLuint const get1DIndexFrom3D(GLuint const& x, GLuint const& y, GLuint const& z, Maths::Vector3D<GLuint> const& size) {
                return (x * size.getY() * size.getZ()) + (y * size.getZ()) + z;
            }

            GLuint const get1DIndexFrom2D(Maths::Point2D<GLuint> const& p, Maths::Vector2D<GLuint> const& size) {
                return get1get1DIndexFrom2D(p.getX(), p.getY(), size);
            }

            GLuint const get1DIndexFrom2D(GLuint const& x, GLuint const& y, Maths::Vector2D<GLuint> const& size) {
                return (x * size.getY()) + y;
            }

        };
    };
