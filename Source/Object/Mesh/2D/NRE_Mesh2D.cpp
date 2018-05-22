
    #include "NRE_Mesh2D.hpp"

    namespace NRE {
        namespace Object {

            Mesh2D::Mesh2D() {
            }

            Mesh2D::Mesh2D(GLenum const& type) : Mesh(type) {
                push_back(new UVData());
                buffer = new GL::VBO(true);
                buffer->push_back(new GL::UVBuffer(true));

                access();
            }

            Mesh2D::Mesh2D(Mesh2D && m) : Mesh::Mesh(std::move(m)) {
            }

            Mesh2D::~Mesh2D() {
            }

            void Mesh2D::process(GLenum const& usage, Maths::Point2D<GLint> const& coord, Maths::Vector2D<GLint> const& size) {
                GLint vData[] = {
                    coord.getX(),               coord.getY(),               0,
                    coord.getX() + size.getX(), coord.getY(),               0,
                    coord.getX() + size.getX(), coord.getY() + size.getY(), 0,
                    coord.getX() + size.getX(), coord.getY() + size.getY(), 0,
                    coord.getX()              , coord.getY() + size.getY(), 0,
                    coord.getX(),               coord.getY(),               0,
                };

                add(0, vData, 18);

                GLshort uvData[] = {
                    0, 0,
                    1, 0,
                    1, 1,
                    1, 1,
                    0, 1,
                    0, 0
                };

                add(1, uvData, 12);

                allocateAndFill(usage);
            }

            Mesh2D& Mesh2D::operator=(Mesh2D && m) {
                Mesh::operator=(std::move(m));
                return *this;
            }

        };
    };
