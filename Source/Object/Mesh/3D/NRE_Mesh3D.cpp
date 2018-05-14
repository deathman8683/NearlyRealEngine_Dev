
    #include "NRE_Mesh3D.hpp"

    namespace NRE {
        namespace Object {

            Mesh3D::Mesh3D() : target(0), left(0), right(0), front(0), back(0), up(0), bottom(0) {
            }

            Mesh3D::Mesh3D(GLenum const& type) : Mesh(type), target(0), left(0), right(0), front(0), back(0), up(0), bottom(0) {
                push_back(new MaterialData());
                push_back(new NormalData());
                push_back(new UVData());
                push_back(new IndexData());
            }

            Mesh3D::Mesh3D(GLenum const& type, const Model* target, const Model* left, const Model* right, const Model* front, const Model* back, const Model* up, const Model* bottom) : Mesh3D(type) {
                this->target = target;
                this->left = left;
                this->right = right;
                this->front = front;
                this->back = back;
                this->up = up;
                this->bottom = bottom;
            }

            Mesh3D::Mesh3D(Mesh3D const& m) : Mesh::Mesh(m), target(m.target), left(m.left), right(m.right), front(m.front), back(m.back), up(m.up), bottom(m.bottom) {
            }

            Mesh3D::Mesh3D(Mesh3D && m) : Mesh::Mesh(std::move(m)), target(std::move(m.target)), left(std::move(m.left)), right(std::move(m.right)), front(std::move(m.front)), back(std::move(m.back)), up(std::move(m.up)), bottom(std::move(m.bottom)) {
            }

            Mesh3D::~Mesh3D() {
            }

            void Mesh3D::setLeft(const Model* const model) {
                left = model;
            }

            void Mesh3D::setRight(const Model* const model) {
                right = model;
            }

            void Mesh3D::setFront(const Model* const model) {
                front = model;
            }

            void Mesh3D::setBack(const Model* const model) {
                back = model;
            }

            void Mesh3D::setUp(const Model* const model) {
                up = model;
            }

            void Mesh3D::setBottom(const Model* const model) {
                bottom = model;
            }

            void Mesh3D::process(GL::IBO& buffer, GLenum const& usage, Maths::Point2D<GLint> const& coord) {
                GLuint index;
                bool face[World::FACE_NUM];

                MergingCache::reset();

                for (unsigned int x = 0; x < target->getSize().getX(); x = x + 1) {
                    for (unsigned int y = 0; y < target->getSize().getY(); y = y + 1) {
                        for (unsigned int z = 0; z <= target->getMaxSolidHeight(); z = z + 1) {
                            index = target->getVoxelIndex(x, y, z);
                            if (target->getVoxel(index).getType() != World::VOID) {
                                face[World::XNegative] = checkVoxelXNegativeFace(x, y, z);
                                face[World::XPositive] = checkVoxelXPositiveFace(x, y, z);
                                face[World::YNegative] = checkVoxelYNegativeFace(x, y, z);
                                face[World::YPositive] = checkVoxelYPositiveFace(x, y, z);
                                face[World::ZNegative] = checkVoxelZNegativeFace(x, y, z);
                                face[World::ZPositive] = checkVoxelZPositiveFace(x, y, z);

                                addVoxel(x, y, z, x + coord.getX() * target->getSize().getX(), y + coord.getY() * target->getSize().getY(), z, face);
                            }
                        }
                    }
                }

                allocateAndFill(buffer, usage);
            }

            void Mesh3D::addVoxel(GLuint const& x, GLuint const& y, GLuint const& z, GLint const& rX, GLint const& rY, GLint const& rZ, bool const (&face)[6]) {
                Maths::Point3D<GLint> p[4];

                if (face[World::XNegative]) {
                    if (!MergingCache::getVoxelMergingFace(x, y, z, World::XNegative)) {

                        p[0] = {rX, rY, rZ};
                        p[1] = {rX, rY + 1, rZ};
                        p[2] = {rX, rY, rZ + 1};
                        p[3] = {rX, rY + 1, rZ + 1};

                        mergeVoxels(x, y, z, target->getVoxel(x, y, z).getType(), p, World::XNegative);
                        addPackedVertex(p, World::XNegative, static_cast <size_t> (target->getVoxel(x, y, z).getType()));
                    }
                }

                if (face[World::YNegative]) {
                    if (!MergingCache::getVoxelMergingFace(x, y, z, World::YNegative)) {
                        p[0] = {rX + 1, rY, rZ};
                        p[1] = {rX, rY, rZ};
                        p[2] = {rX + 1, rY, rZ + 1};
                        p[3] = {rX, rY, rZ + 1};

                        mergeVoxels(x, y, z, target->getVoxel(x, y, z).getType(), p, World::YNegative);
                        addPackedVertex(p, World::YNegative, static_cast <size_t> (target->getVoxel(x, y, z).getType()));
                    }
                }

                if (face[World::ZNegative]) {
                    if (!MergingCache::getVoxelMergingFace(x, y, z, World::ZNegative)) {
                        p[0] = {rX, rY, rZ};
                        p[1] = {rX + 1, rY, rZ};
                        p[2] = {rX, rY + 1, rZ};
                        p[3] = {rX + 1, rY + 1, rZ};

                        mergeVoxels(x, y, z, target->getVoxel(x, y, z).getType(), p, World::ZNegative);
                        addPackedVertex(p, World::ZNegative, static_cast <size_t> (target->getVoxel(x, y, z).getType()));
                    }
                }

                if (face[World::XPositive]) {
                    if (!MergingCache::getVoxelMergingFace(x, y, z, World::XPositive)) {
                        p[0] = {rX + 1, rY + 1, rZ};
                        p[1] = {rX + 1, rY, rZ};
                        p[2] = {rX + 1, rY + 1, rZ + 1};
                        p[3] = {rX + 1, rY, rZ + 1};

                        mergeVoxels(x, y, z, target->getVoxel(x, y, z).getType(), p, World::XPositive);
                        addPackedVertex(p, World::XPositive, static_cast <size_t> (target->getVoxel(x, y, z).getType()));
                    }
                }

                if (face[World::YPositive]) {
                    if (!MergingCache::getVoxelMergingFace(x, y, z, World::YPositive)) {
                        p[0] = {rX, rY + 1, rZ};
                        p[1] = {rX + 1, rY + 1, rZ};
                        p[2] = {rX,  rY + 1, rZ + 1};
                        p[3] = {rX + 1, rY + 1, rZ + 1};

                        mergeVoxels(x, y, z, target->getVoxel(x, y, z).getType(), p, World::YPositive);
                        addPackedVertex(p, World::YPositive, static_cast <size_t> (target->getVoxel(x, y, z).getType()));
                    }
                }

                if (face[World::ZPositive]) {
                    if (!MergingCache::getVoxelMergingFace(x, y, z, World::ZPositive)) {
                        p[0] = {rX + 1, rY, rZ + 1};
                        p[1] = {rX, rY, rZ + 1};
                        p[2] = {rX + 1, rY + 1, rZ + 1};
                        p[3] = {rX, rY + 1, rZ + 1};

                        mergeVoxels(x, y, z, target->getVoxel(x, y, z).getType(), p, World::ZPositive);
                        addPackedVertex(p, World::ZPositive, static_cast <size_t> (target->getVoxel(x, y, z).getType()));
                    }
                }
            }


            void Mesh3D::mergeVoxels(GLuint x, GLuint y, GLuint z, GLint const& type, Maths::Point3D<GLint> (&p)[4], int const& face) {
                GLuint index = 0;
                bool axe1More, axe2More;
                GLuint axe1Size = 1, axe2Size = 0, axe1Cpy, *axe1, *axe2, limit1, limit2;
                Maths::Point3D<GLint> *p1, *p2, *p3, *p4;
                auto setAxe1 = &Maths::Point3D<GLint>::setZ<GLint>;
                auto setAxe2 = &Maths::Point3D<GLint>::setZ<GLint>;
                auto getAxe1 = &Maths::Point3D<GLint>::getZ;
                auto getAxe2 = &Maths::Point3D<GLint>::getZ;
                auto checkFace = &Mesh3D::checkVoxelXNegativeFace;

                if (face == World::XNegative || face == World::XPositive) {
                    axe1 = &y, axe2 = &z; axe1Cpy = y;
                    limit1 = target->getSize().getY(); limit2 = target->getSize().getZ();
                    setAxe1 = &Maths::Point3D<GLint>::setY<GLint>;
                    setAxe2 = &Maths::Point3D<GLint>::setZ<GLint>;
                    getAxe1 = &Maths::Point3D<GLint>::getY;
                    getAxe2 = &Maths::Point3D<GLint>::getZ;
                    if (face == World::XNegative) {
                       p1 = &p[1]; p2 = &p[3], p3 = &p[2]; p4 = &p[3];
                       checkFace = &Mesh3D::checkVoxelXNegativeFace;
                    } else {
                       p1 = &p[0]; p2 = &p[2], p3 = &p[2]; p4 = &p[3];
                       checkFace = &Mesh3D::checkVoxelXPositiveFace;
                    }
                }
                if (face == World::YNegative || face == World::YPositive) {
                    axe1 = &x; axe2 = &z; axe1Cpy = x;
                    limit1 = target->getSize().getX(); limit2 = target->getSize().getZ();
                    setAxe1 = &Maths::Point3D<GLint>::setX<GLint>;
                    setAxe2 = &Maths::Point3D<GLint>::setZ<GLint>;
                    getAxe1 = &Maths::Point3D<GLint>::getX;
                    getAxe2 = &Maths::Point3D<GLint>::getZ;
                    if (face == World::YNegative) {
                        p1 = &p[0]; p2 = &p[2], p3 = &p[2]; p4 = &p[3];
                        checkFace = &Mesh3D::checkVoxelYNegativeFace;
                    } else {
                        p1 = &p[1]; p2 = &p[3]; p3 = &p[2]; p4 = &p[3];
                        checkFace = &Mesh3D::checkVoxelYPositiveFace;
                    }
                }
                if (face == World::ZNegative || face == World::ZPositive) {
                    axe1 = &x, axe2 = &y; axe1Cpy = x;
                    limit1 = target->getSize().getX(); limit2 = target->getSize().getY();
                    setAxe1 = &Maths::Point3D<GLint>::setX<GLint>;
                    setAxe2 = &Maths::Point3D<GLint>::setY<GLint>;
                    getAxe1 = &Maths::Point3D<GLint>::getX;
                    getAxe2 = &Maths::Point3D<GLint>::getY;
                    if (face == World::ZNegative) {
                       p1 = &p[1]; p2 = &p[3], p3 = &p[2]; p4 = &p[3];
                       checkFace = &Mesh3D::checkVoxelZNegativeFace;
                    } else {
                       p1 = &p[0]; p2 = &p[2], p3 = &p[2]; p4 = &p[3];
                       checkFace = &Mesh3D::checkVoxelZPositiveFace;
                    }
                }

                index = target->getVoxelIndex(x, y, z);
                MergingCache::setVoxelMergingFace(x, y, z, face, true);
                axe1More = !(*axe1 == limit1 - 1);
                *axe1 = *axe1 + 1;

                while (axe1More) {
                    index = target->getVoxelIndex(x, y, z);
                    if ((this->*checkFace)(x, y, z)
                     && !MergingCache::getVoxelMergingFace(x, y, z, face)
                     && target->getVoxel(index).getType() == type) {
                         (p1->*setAxe1)((p1->*getAxe1)() + 1);
                         (p2->*setAxe1)((p2->*getAxe1)() + 1);
                         MergingCache::setVoxelMergingFace(x, y, z, face, true);
                        *axe1 = *axe1 + 1;
                        axe1Size = axe1Size + 1;
                    } else {
                        axe1More = false;
                    }
                    if (*axe1 == limit1) {
                        axe1More = false;
                    }
                }

                axe1More = true;
                *axe1 = axe1Cpy;
                axe2More = !(*axe2 == limit2 - 1);
                *axe2 = *axe2 + 1;
                while (axe2More) {
                    while (axe1More && axe1Size != axe2Size) {
                        index = target->getVoxelIndex(x, y, z);
                        if ((this->*checkFace)(x, y, z)
                         && !MergingCache::getVoxelMergingFace(x, y, z, face)
                         && target->getVoxel(index).getType() == type) {
                            axe2Size = axe2Size + 1;
                            *axe1 = *axe1 + 1;
                        } else {
                            axe1More = false;
                        }
                        if (*axe1 == limit1) {
                            axe1More = false;
                        }
                    }
                    if (axe2Size == axe1Size) {
                        (p3->*setAxe2)((p3->*getAxe2)() + 1);
                        (p4->*setAxe2)((p4->*getAxe2)() + 1);
                        *axe1 = axe1Cpy;
                        while (axe2Size != 0) {
                            index = target->getVoxelIndex(x, y, z);
                            MergingCache::setVoxelMergingFace(x, y, z, face, true);
                            axe2Size = axe2Size - 1;
                            *axe1 = *axe1 + 1;
                        }
                    } else {
                        axe2More = false;
                    }
                    axe2Size = 0;
                    axe1More = true;
                    *axe1 = axe1Cpy;
                    *axe2 = *axe2 + 1;
                    if (*axe2 == limit2) {
                        axe2More = false;
                    }
                }
            }

            void Mesh3D::addPackedVertex(Maths::Point3D<GLint> const (&p)[4], GLuint const& face, size_t const& cCode) {
                Maths::Vector3D<NREfloat> n;
                GLuint idx1, idx2, nIdx;

                Maths::Point2D<NREfloat> uv[4] = {
                    {0, 0}, {0, 1}, {1, 0}, {1, 1}
                };

                switch (face) {
                    case (World::XNegative) : {
                        n = {-1, 0, 0};
                        break;
                    }
                    case (World::YNegative) : {
                        n = {0, -1, 0};
                        break;
                    }
                    case (World::ZNegative) : {
                        n = {0, 0, -1};
                        break;
                    }
                    case (World::XPositive) : {
                        n = {1, 0, 0};
                        break;
                    }
                    case (World::YPositive) : {
                        n = {0, 1, 0};
                        break;
                    }
                    case (World::ZPositive) : {
                        n = {0, 0, 1};
                        break;
                    }
                    default : {
                    }
                }

                add(0, p[2].value(), 3);
                add(3, uv[2].value(), 2);
                add(2, n.value(), 3);
                add(1, &cCode);
                nIdx = static_cast <GLuint> (getDataSet(0)->size() / 3) - 1;
                add(4, &nIdx);
                idx1 = nIdx;

                add(0, p[1].value(), 3);
                add(3, uv[1].value(), 2);
                add(2, n.value(), 3);
                add(1, &cCode);
                nIdx = static_cast <GLuint> (getDataSet(0)->size() / 3) - 1;
                add(4, &nIdx);
                idx2 = nIdx;

                add(0, p[0].value(), 3);
                add(3, uv[0].value(), 2);
                add(2, n.value(), 3);
                add(1, &cCode);
                nIdx = static_cast <GLuint> (getDataSet(0)->size() / 3) - 1;
                add(4, &nIdx);

                add(0, p[3].value(), 3);
                add(3, uv[3].value(), 2);
                add(2, n.value(), 3);
                add(1, &cCode);
                nIdx = static_cast <GLuint> (getDataSet(0)->size() / 3) - 1;
                add(4, &nIdx);

                add(4, &idx2);
                add(4, &idx1);
            }

            void Mesh3D::processSphere(GL::IBO& buffer, GLenum const& usage, NREfloat const& radius, NREfloat const& rings, NREfloat const& sectors, GLubyte const& type) {
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

                        add(3, &u);
                        add(3, &v);

                        add(0, &vX);
                        add(0, &vY);
                        add(0, &vZ);

                        add(1, &type);

                        add(2, &x);
                        add(2, &y);
                        add(2, &z);
                    }
                }

                for (GLint r = 0; r < static_cast <GLint> (rings) - 1; r = r + 1) {
                    for (GLint s = 0; s < static_cast <GLint> (sectors) - 1; s = s + 1) {
                        GLuint idx1 = r * sectors + s;
                        GLuint idx2 = r * sectors + (s + 1);
                        GLuint idx3 = (r + 1) * sectors + (s + 1);
                        GLuint idx4 = (r + 1) * sectors + s;

                        add(4, &idx4);
                        add(4, &idx2);
                        add(4, &idx1);
                        add(4, &idx2);
                        add(4, &idx4);
                        add(4, &idx3);
                    }
                }

                allocateAndFill(buffer, usage);
            }

            Mesh3D& Mesh3D::operator=(Mesh3D const& m) {
                Mesh::operator=(m);
                target = m.target;
                left = m.left;
                right = m.right;
                front = m.front;
                back = m.back;
                up = m.up;
                bottom = m.bottom;
                return *this;
            }

            Mesh3D& Mesh3D::operator=(Mesh3D && m) {
                Mesh::operator=(std::move(m));
                target = std::move(m.target);
                left = std::move(m.left);
                right = std::move(m.right);
                front = std::move(m.front);
                back = std::move(m.back);
                up = std::move(m.up);
                bottom = std::move(m.bottom);
                return *this;
            }

            bool const Mesh3D::checkVoxelXNegativeFace(GLuint const& x, GLuint const& y, GLuint const& z) {
                if (x == 0) {
                    if (left == 0) {
                        return true;
                    } else {
                        return left->getVoxel(target->getSize().getX() - 1, y, z).getType() == World::VOID;
                    }
                } else {
                    return target->getVoxel(x - 1, y, z).getType() == World::VOID;
                }
            }

            bool const Mesh3D::checkVoxelXPositiveFace(GLuint const& x, GLuint const& y, GLuint const& z) {
                if (x == target->getSize().getX() - 1) {
                    if (right == 0) {
                        return true;
                    } else {
                        return right->getVoxel(0, y, z).getType() == World::VOID;
                    }
                } else {
                    return target->getVoxel(x + 1, y, z).getType() == World::VOID;
                }
            }

            bool const Mesh3D::checkVoxelYNegativeFace(GLuint const& x, GLuint const& y, GLuint const& z) {
                if (y == 0) {
                    if (back == 0) {
                        return true;
                    } else {
                        return back->getVoxel(x, target->getSize().getY() - 1, z).getType() == World::VOID;
                    }
                } else {
                    return target->getVoxel(x, y - 1, z).getType() == World::VOID;
                }
            }

            bool const Mesh3D::checkVoxelYPositiveFace(GLuint const& x, GLuint const& y, GLuint const& z) {
                if (y == target->getSize().getY() - 1) {
                    if (front == 0) {
                        return true;
                    } else {
                        return front->getVoxel(x, 0, z).getType() == World::VOID;
                    }
                } else {
                    return target->getVoxel(x, y + 1, z).getType() == World::VOID;
                }
            }

            bool const Mesh3D::checkVoxelZNegativeFace(GLuint const& x, GLuint const& y, GLuint const& z) {
                if (z == 0) {
                    if (bottom == 0) {
                        return true;
                    } else {
                        return bottom->getVoxel(x, y, target->getSize().getZ() - 1).getType() == World::VOID;
                    }
                    return true;
                } else {
                    return target->getVoxel(x, y, z - 1).getType() == World::VOID;
                }
            }

            bool const Mesh3D::checkVoxelZPositiveFace(GLuint const& x, GLuint const& y, GLuint const& z) {
                if (z == target->getSize().getZ() - 1) {
                    if (up == 0) {
                        return true;
                    } else {
                        return up->getVoxel(x, y, 0).getType() == World::VOID;
                    }
                } else {
                    return target->getVoxel(x, y, z + 1).getType() == World::VOID;
                }
            }

        };
    };
