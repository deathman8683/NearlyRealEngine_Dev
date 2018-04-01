
    #include "NRE_Mesh.hpp"

    namespace NRE {
        namespace World {

            Mesh::Mesh() : Mesh(0) {
            }

            Mesh::Mesh(Chunk* const& target) : target(target) {
            }

            Mesh::Mesh(Mesh const& mesh) : target(mesh.getTarget()), vData(mesh.getVData()), cData(mesh.getCData()), nData(mesh.getNData()), iData(mesh.getIData()), map(mesh.getMap()) {
            }

            Mesh::~Mesh() {
            }

            Chunk* const& Mesh::getTarget() const {
                return target;
            }

            std::vector<GLint> const& Mesh::getVData() const {
                return vData;
            }

            std::vector<GLfloat> const& Mesh::getCData() const {
                return cData;
            }

            std::vector<GLbyte> const& Mesh::getNData() const {
                return nData;
            }

            std::vector<GLuint> const& Mesh::getIData() const {
                return iData;
            }

            GLint* Mesh::getVPointer() {
                return &vData.front();
            }

            GLfloat* Mesh::getCPointer() {
                return &cData.front();
            }

            GLbyte* Mesh::getNPointer() {
                return &nData.front();
            }

            GLuint* Mesh::getIPointer() {
                return &iData.front();
            }

            std::unordered_map<PackedVertex, size_t> const& Mesh::getMap() const {
                return map;
            }

            void Mesh::setTarget(Chunk* const& target) {
                this->target = target;
            }

            void Mesh::setVData(std::vector<GLint> const& data) {
                vData = data;
            }

            void Mesh::setCData(std::vector<GLfloat> const& data) {
                cData = data;
            }

            void Mesh::setNData(std::vector<GLbyte> const& data) {
                nData = data;
            }

            void Mesh::setIData(std::vector<GLuint> const& data) {
                iData = data;
            }

            void Mesh::setMap(std::unordered_map<PackedVertex, size_t> const& map) {
                this->map = map;
            }

            void Mesh::addVertex(Maths::Point3D<GLint> const& v) {
                vData.push_back(v.getX());
                vData.push_back(v.getY());
                vData.push_back(v.getZ());
            }

            void Mesh::addColor(Color::RGB const& c) {
                cData.push_back(static_cast <NREfloat> (c.getR()) / 255.0);
                cData.push_back(static_cast <NREfloat> (c.getG()) / 255.0);
                cData.push_back(static_cast <NREfloat> (c.getB()) / 255.0);
            }

            void Mesh::addNormal(Maths::Vector3D<GLbyte> const& n) {
                nData.push_back(n.getX());
                nData.push_back(n.getY());
                nData.push_back(n.getZ());
            }

            void Mesh::addIndex(GLuint const& index) {
                iData.push_back(index);
            }

            void Mesh::constructMesh(World* w) {
                GLuint index;
                bool face[FACE_NUM];

                w->resetVoxelMergingGlobalCache();

                for (unsigned int x = 0; x < Chunk::SIZE_X; x = x + 1) {
                    for (unsigned int y = 0; y < Chunk::SIZE_Y; y = y + 1) {
                        for (unsigned int z = 0; z < Chunk::SIZE_Z; z = z + 1) {
                            index = getVoxelIndex(x, y, z);
                            if (getTarget()->getVoxel(index).getType() != VOID) {
                                face[XNegative] = checkVoxelXNegativeFace(w, x, y, z);
                                face[XPositive] = checkVoxelXPositiveFace(w, x, y, z);
                                face[YNegative] = checkVoxelYNegativeFace(w, x, y, z);
                                face[YPositive] = checkVoxelYPositiveFace(w, x, y, z);
                                face[ZNegative] = checkVoxelZNegativeFace(w, x, y, z);
                                face[ZPositive] = checkVoxelZPositiveFace(w, x, y, z);

                                addVoxel(w, Maths::Point3D<GLuint>(x, y, z), Maths::Point3D<GLint>(x + target->getCoord().getX() * Chunk::SIZE_X, y + target->getCoord().getY() * Chunk::SIZE_Y, z), face);
                            }
                        }
                    }
                }
            }

            void Mesh::addVoxel(World* w, Maths::Point3D<GLuint> const& voxCoord, Maths::Point3D<GLint> const& realCoord, bool const (&face)[6]) {
                Maths::Point3D<GLint> p[4];
                Color::RGB voxColor = getTarget()->getVoxel(voxCoord).getColor();

                if (face[XNegative]) {
                    if (!w->getVoxelMergingFace(voxCoord, XNegative)) {

                        p[0] = {realCoord.getX(), realCoord.getY(), realCoord.getZ()};
                        p[1] = {realCoord.getX(), realCoord.getY() + 1, realCoord.getZ()};
                        p[2] = {realCoord.getX(), realCoord.getY(), realCoord.getZ() + 1};
                        p[3] = {realCoord.getX(), realCoord.getY() + 1, realCoord.getZ() + 1};

                        mergeVoxels(w, voxCoord.getX(), voxCoord.getY(), voxCoord.getZ(), getTarget()->getVoxel(voxCoord).getType(), p, XNegative);
                        addPackedVertex(p, voxColor, XNegative, static_cast <size_t> (target->getVoxel(voxCoord).getType()));
                    }
                }

                if (face[YNegative]) {
                    if (!w->getVoxelMergingFace(voxCoord, YNegative)) {
                        p[0] = {realCoord.getX() + 1, realCoord.getY(), realCoord.getZ()};
                        p[1] = {realCoord.getX(), realCoord.getY(), realCoord.getZ()};
                        p[2] = {realCoord.getX() + 1, realCoord.getY(), realCoord.getZ() + 1};
                        p[3] = {realCoord.getX(), realCoord.getY(), realCoord.getZ() + 1};

                        mergeVoxels(w, voxCoord.getX(), voxCoord.getY(), voxCoord.getZ(), getTarget()->getVoxel(voxCoord).getType(), p, YNegative);
                        addPackedVertex(p, voxColor, YNegative, static_cast <size_t> (target->getVoxel(voxCoord).getType()));
                    }
                }

                if (face[ZNegative]) {
                    if (!w->getVoxelMergingFace(voxCoord, ZNegative)) {
                        p[0] = {realCoord.getX(), realCoord.getY(), realCoord.getZ()};
                        p[1] = {realCoord.getX() + 1, realCoord.getY(), realCoord.getZ()};
                        p[2] = {realCoord.getX(), realCoord.getY() + 1, realCoord.getZ()};
                        p[3] = {realCoord.getX() + 1, realCoord.getY() + 1, realCoord.getZ()};

                        mergeVoxels(w, voxCoord.getX(), voxCoord.getY(), voxCoord.getZ(), getTarget()->getVoxel(voxCoord).getType(), p, ZNegative);
                        addPackedVertex(p, voxColor, ZNegative, static_cast <size_t> (target->getVoxel(voxCoord).getType()));
                    }
                }

                if (face[XPositive]) {
                    if (!w->getVoxelMergingFace(voxCoord, XPositive)) {
                        p[0] = {realCoord.getX() + 1, realCoord.getY() + 1, realCoord.getZ()};
                        p[1] = {realCoord.getX() + 1, realCoord.getY(), realCoord.getZ()};
                        p[2] = {realCoord.getX() + 1, realCoord.getY() + 1, realCoord.getZ() + 1};
                        p[3] = {realCoord.getX() + 1, realCoord.getY(), realCoord.getZ() + 1};

                        mergeVoxels(w, voxCoord.getX(), voxCoord.getY(), voxCoord.getZ(), getTarget()->getVoxel(voxCoord).getType(), p, XPositive);
                        addPackedVertex(p, voxColor, XPositive, static_cast <size_t> (target->getVoxel(voxCoord).getType()));
                    }
                }

                if (face[YPositive]) {
                    if (!w->getVoxelMergingFace(voxCoord, YPositive)) {
                        p[0] = {realCoord.getX(), realCoord.getY() + 1, realCoord.getZ()};
                        p[1] = {realCoord.getX() + 1, realCoord.getY() + 1, realCoord.getZ()};
                        p[2] = {realCoord.getX(),  realCoord.getY() + 1, realCoord.getZ() + 1};
                        p[3] = {realCoord.getX() + 1, realCoord.getY() + 1, realCoord.getZ() + 1};

                        mergeVoxels(w, voxCoord.getX(), voxCoord.getY(), voxCoord.getZ(), getTarget()->getVoxel(voxCoord).getType(), p, YPositive);
                        addPackedVertex(p, voxColor, YPositive, static_cast <size_t> (target->getVoxel(voxCoord).getType()));
                    }
                }

                if (face[ZPositive]) {
                    if (!w->getVoxelMergingFace(voxCoord, ZPositive)) {
                        p[0] = {realCoord.getX() + 1, realCoord.getY(), realCoord.getZ() + 1};
                        p[1] = {realCoord.getX(), realCoord.getY(), realCoord.getZ() + 1};
                        p[2] = {realCoord.getX() + 1, realCoord.getY() + 1, realCoord.getZ() + 1};
                        p[3] = {realCoord.getX(), realCoord.getY() + 1, realCoord.getZ() + 1};

                        mergeVoxels(w, voxCoord.getX(), voxCoord.getY(), voxCoord.getZ(), getTarget()->getVoxel(voxCoord).getType(), p, ZPositive);
                        addPackedVertex(p, voxColor, ZPositive, static_cast <size_t> (target->getVoxel(voxCoord).getType()));
                    }
                }
            }


            void Mesh::mergeVoxels(World* w, GLuint x, GLuint y, GLuint z, GLint const& type, Maths::Point3D<GLint> (&p)[4], int const& face) {
                GLuint index = 0;
                bool axe1More, axe2More;
                GLuint axe1Size = 1, axe2Size = 0, axe1Cpy, *axe1, *axe2, limit1, limit2;
                Maths::Point3D<GLint> *p1, *p2, *p3, *p4;
                auto setAxe1 = &Maths::Point3D<GLint>::setZ<GLint>;
                auto setAxe2 = &Maths::Point3D<GLint>::setZ<GLint>;
                auto getAxe1 = &Maths::Point3D<GLint>::getZ;
                auto getAxe2 = &Maths::Point3D<GLint>::getZ;
                auto checkFace = &Mesh::checkVoxelXNegativeFace;

                if (face == XNegative || face == XPositive) {
                    axe1 = &y, axe2 = &z; axe1Cpy = y;
                    limit1 = Chunk::SIZE_Y; limit2 = Chunk::SIZE_Z;
                    setAxe1 = &Maths::Point3D<GLint>::setY<GLint>;
                    setAxe2 = &Maths::Point3D<GLint>::setZ<GLint>;
                    getAxe1 = &Maths::Point3D<GLint>::getY;
                    getAxe2 = &Maths::Point3D<GLint>::getZ;
                    if (face == XNegative) {
                       p1 = &p[1]; p2 = &p[3], p3 = &p[2]; p4 = &p[3];
                       checkFace = &Mesh::checkVoxelXNegativeFace;
                    } else {
                       p1 = &p[0]; p2 = &p[2], p3 = &p[2]; p4 = &p[3];
                       checkFace = &Mesh::checkVoxelXPositiveFace;
                    }
                }
                if (face == YNegative || face == YPositive) {
                    axe1 = &x; axe2 = &z; axe1Cpy = x;
                    limit1 = Chunk::SIZE_X; limit2 = Chunk::SIZE_Z;
                    setAxe1 = &Maths::Point3D<GLint>::setX<GLint>;
                    setAxe2 = &Maths::Point3D<GLint>::setZ<GLint>;
                    getAxe1 = &Maths::Point3D<GLint>::getX;
                    getAxe2 = &Maths::Point3D<GLint>::getZ;
                    if (face == YNegative) {
                        p1 = &p[0]; p2 = &p[2], p3 = &p[2]; p4 = &p[3];
                        checkFace = &Mesh::checkVoxelYNegativeFace;
                    } else {
                        p1 = &p[1]; p2 = &p[3]; p3 = &p[2]; p4 = &p[3];
                        checkFace = &Mesh::checkVoxelYPositiveFace;
                    }
                }
                if (face == ZNegative || face == ZPositive) {
                    axe1 = &x, axe2 = &y; axe1Cpy = x;
                    limit1 = Chunk::SIZE_X; limit2 = Chunk::SIZE_Y;
                    setAxe1 = &Maths::Point3D<GLint>::setX<GLint>;
                    setAxe2 = &Maths::Point3D<GLint>::setY<GLint>;
                    getAxe1 = &Maths::Point3D<GLint>::getX;
                    getAxe2 = &Maths::Point3D<GLint>::getY;
                    if (face == ZNegative) {
                       p1 = &p[1]; p2 = &p[3], p3 = &p[2]; p4 = &p[3];
                       checkFace = &Mesh::checkVoxelZNegativeFace;
                    } else {
                       p1 = &p[0]; p2 = &p[2], p3 = &p[2]; p4 = &p[3];
                       checkFace = &Mesh::checkVoxelZPositiveFace;
                    }
                }

                index = getVoxelIndex(x, y, z);
                w->setVoxelMergingFace(x, y, z, face, true);
                axe1More = !(*axe1 == limit1 - 1);
                *axe1 = *axe1 + 1;

                while (axe1More) {
                    index = getVoxelIndex(x, y, z);
                    if ((this->*checkFace)(w, x, y, z)
                     && !w->getVoxelMergingFace(x, y, z, face)
                     && getTarget()->getVoxel(index).getType() == type) {
                         (p1->*setAxe1)((p1->*getAxe1)() + 1);
                         (p2->*setAxe1)((p2->*getAxe1)() + 1);
                         w->setVoxelMergingFace(x, y, z, face, true);
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
                        index = getVoxelIndex(x, y, z);
                        if ((this->*checkFace)(w, x, y, z)
                         && !w->getVoxelMergingFace(x, y, z, face)
                         && getTarget()->getVoxel(index).getType() == type) {
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
                            index = getVoxelIndex(x, y, z);
                            w->setVoxelMergingFace(x, y, z, face, true);
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

            void Mesh::addPackedVertex(Maths::Point3D<GLint> const (&p)[4], Color::RGB const& voxColor, GLuint const& face, size_t const& cCode) {
                Maths::Vector3D<GLbyte> n;
                GLuint idx0, idx1, idx2, nIdx;
                bool found;

                switch (face) {
                    case (XNegative) : {
                        n = {-1.0, 0, 0};
                        break;
                    }
                    case (YNegative) : {
                        n = {0, -1.0, 0};
                        break;
                    }
                    case (ZNegative) : {
                        n = {0, 0, -1.0};
                        break;
                    }
                    case (XPositive) : {
                        n = {1.0, 0, 0};
                        break;
                    }
                    case (YPositive) : {
                        n = {0, 1.0, 0};
                        break;
                    }
                    case (ZPositive) : {
                        n = {0, 0, 1.0};
                        break;
                    }
                    default : {
                    }
                }

                PackedVertex packed(p[2], n, voxColor, static_cast <size_t> (face), cCode);
                found = getSimilarVertexIndex(packed, map, idx0);

                if (found) {
                    iData.push_back(idx0);
                    idx1 = idx0;
                } else {
                    addVertex(p[2]);
                    addNormal(n);
                    addColor(voxColor);
                    nIdx = static_cast <GLuint> (vData.size() / 3) - 1;
                    addIndex(nIdx);
                    map[packed] = nIdx;
                    idx1 = nIdx;
                }

                packed = {p[1], n, voxColor, static_cast <size_t> (face), cCode};
                found = getSimilarVertexIndex(packed, map, idx0);

                if (found) {
                    iData.push_back(idx0);
                    idx2 = idx0;
                } else {
                    addVertex(p[1]);
                    addNormal(n);
                    addColor(voxColor);
                    nIdx = static_cast <GLuint> (vData.size() / 3) - 1;
                    addIndex(nIdx);
                    map[packed] = nIdx;
                    idx2 = nIdx;
                }

                packed = {p[0], n, voxColor, static_cast <size_t> (face), cCode};
                found = getSimilarVertexIndex(packed, map, idx0);

                if (found) {
                    iData.push_back(idx0);
                } else {
                    addVertex(p[0]);
                    addNormal(n);
                    addColor(voxColor);
                    nIdx = static_cast <GLuint> (vData.size() / 3) - 1;
                    addIndex(nIdx);
                    map[packed] = nIdx;
                }

                packed = {p[3], n, voxColor, static_cast <size_t> (face), cCode};
                found = getSimilarVertexIndex(packed, map, idx0);

                if (found) {
                    iData.push_back(idx0);
                } else {
                    addVertex(p[3]);
                    addNormal(n);
                    addColor(voxColor);
                    nIdx = static_cast <GLuint> (vData.size() / 3) - 1;
                    addIndex(nIdx);
                    map[packed] = nIdx;
                }

                iData.push_back(idx2);
                iData.push_back(idx1);
            }

            bool const Mesh::getSimilarVertexIndex(PackedVertex const& packed, std::unordered_map<PackedVertex, size_t> const& map, GLuint &result) const {
                auto it = map.find(packed);
                if (it == map.end()) {
                    return false;
                } else {
                    result = it->second;
                    return true;
                }
            }

            bool Mesh::checkVoxelXNegativeFace(World* w, GLuint const& x, GLuint const& y, GLuint const& z) {
                if (x == 0) {
                    if (getTarget()->getCoord().getX() - w->getShift().getX() == -1 * static_cast <GLint> (w->getHExtent().getX())) {
                        return true;
                    } else {
                        return w->getChunk(getTarget()->getCoord().getX() - 1, getTarget()->getCoord().getY())->getVoxel(Chunk::SIZE_X - 1, y, z).getType() == VOID;
                    }
                } else {
                    return getTarget()->getVoxel(x - 1, y, z).getType() == VOID;
                }
            }

            bool Mesh::checkVoxelXPositiveFace(World* w, GLuint const& x, GLuint const& y, GLuint const& z) {
                if (x == Chunk::SIZE_X - 1) {
                    if (getTarget()->getCoord().getX() - w->getShift().getX() == static_cast <GLint> (w->getHExtent().getX())) {
                        return true;
                    } else {
                        return w->getChunk(getTarget()->getCoord().getX() + 1, getTarget()->getCoord().getY())->getVoxel(0, y, z).getType() == VOID;
                    }
                } else {
                    return getTarget()->getVoxel(x + 1, y, z).getType() == VOID;
                }
            }

            bool Mesh::checkVoxelYNegativeFace(World* w, GLuint const& x, GLuint const& y, GLuint const& z) {
                if (y == 0) {
                    if (getTarget()->getCoord().getY() - w->getShift().getY() == -1 * static_cast <GLint> (w->getHExtent().getY())) {
                        return true;
                    } else {
                        return w->getChunk(getTarget()->getCoord().getX(), getTarget()->getCoord().getY() - 1)->getVoxel(x, Chunk::SIZE_Y - 1, z).getType() == VOID;
                    }
                } else {
                    return getTarget()->getVoxel(x, y - 1, z).getType() == VOID;
                }
            }

            bool Mesh::checkVoxelYPositiveFace(World* w, GLuint const& x, GLuint const& y, GLuint const& z) {
                if (y == Chunk::SIZE_Y - 1) {
                    if (getTarget()->getCoord().getY() - w->getShift().getY() == static_cast <GLint> (w->getHExtent().getY())) {
                        return true;
                    } else {
                        return w->getChunk(getTarget()->getCoord().getX(), getTarget()->getCoord().getY() + 1)->getVoxel(x, 0, z).getType() == VOID;
                    }
                } else {
                    return getTarget()->getVoxel(x, y + 1, z).getType() == VOID;
                }
            }

            bool Mesh::checkVoxelZNegativeFace(World* w, GLuint const& x, GLuint const& y, GLuint const& z) {
                if (z == 0) {
                    return true;
                } else {
                    return getTarget()->getVoxel(x, y, z - 1).getType() == VOID;
                }
            }

            bool Mesh::checkVoxelZPositiveFace(World* w, GLuint const& x, GLuint const& y, GLuint const& z) {
                if (z == Chunk::SIZE_Z - 1) {
                    return true;
                } else {
                    return getTarget()->getVoxel(x, y, z + 1).getType() == VOID;
                }
            }

        };
    };
