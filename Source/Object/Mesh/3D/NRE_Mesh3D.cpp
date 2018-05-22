
    #include "NRE_Mesh3D.hpp"

    namespace NRE {
        namespace Object {

            Mesh3D::Mesh3D() {
            }

            Mesh3D::Mesh3D(GLenum const& type) : Mesh(type) {
                push_back(new MaterialData());
                push_back(new NormalData());
                push_back(new TangentData());
                push_back(new UVData());
                push_back(new IndexData());

                buffer = new GL::IBO(true);
                buffer->push_back(new GL::MaterialBuffer(true));
                buffer->push_back(new GL::NormalBuffer(true));
                buffer->push_back(new GL::TangentBuffer(true));
                buffer->push_back(new GL::UVBuffer(true));

                access();
            }

            Mesh3D::Mesh3D(Mesh3D && m) : Mesh::Mesh(std::move(m)) {
            }

            Mesh3D::~Mesh3D() {
            }

            void Mesh3D::processSphere(GLenum const& usage, NREfloat const& radius, NREfloat const& rings, NREfloat const& sectors, GLubyte const& type) {
                NREfloat ring = 1.0 / static_cast <NREfloat> (rings - 1);
                NREfloat sector = 1.0 / static_cast <NREfloat> (sectors - 1);

                for (GLint r = 0; r < static_cast <GLint> (rings); r = r + 1) {
                    for (GLint s = 0; s < static_cast <GLint> (sectors); s = s + 1) {
                        NREfloat x = std::cos(2.0 * Global::PI * static_cast <NREfloat> (s * sector)) * std::sin(Global::PI * static_cast <NREfloat> (r * ring));
                        NREfloat y = std::sin(-Global::PI_2 + Global::PI * static_cast <NREfloat> (r * ring));
                        NREfloat z = std::sin(2.0 * Global::PI * static_cast <NREfloat> (s * sector)) * std::sin(Global::PI * static_cast <NREfloat> (r * ring));

                        NREfloat vX = x * radius;
                        NREfloat vY = y * radius;
                        NREfloat vZ = z * radius;

                        NREfloat u = s * sector;
                        NREfloat v = r * ring;

                        Maths::Vector3D<NREfloat> n(x, y, z);
                        Maths::Vector3D<NREfloat> tangent = Maths::Vector3D<NREfloat>(0, 0, 1) ^ n;

                        add(0, &vX);
                        add(0, &vY);
                        add(0, &vZ);

                        add(1, &type);

                        add(2, n.value(), 3);
                        add(3, tangent.value(), 3);

                        add(4, &u);
                        add(4, &v);
                    }
                }

                for (GLint r = 0; r < static_cast <GLint> (rings) - 1; r = r + 1) {
                    for (GLint s = 0; s < static_cast <GLint> (sectors) - 1; s = s + 1) {
                        GLuint idx1 = r * sectors + s;
                        GLuint idx2 = r * sectors + (s + 1);
                        GLuint idx3 = (r + 1) * sectors + (s + 1);
                        GLuint idx4 = (r + 1) * sectors + s;

                        add(5, &idx4);
                        add(5, &idx2);
                        add(5, &idx1);
                        add(5, &idx2);
                        add(5, &idx4);
                        add(5, &idx3);
                    }
                }

                allocateAndFill(usage);
            }

            Mesh3D& Mesh3D::operator=(Mesh3D && m) {
                Mesh::operator=(std::move(m));
                return *this;
            }

        };
    };
