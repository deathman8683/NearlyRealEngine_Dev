
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

            std::unordered_map<NRE::Voxel::PackedVertex, size_t> const& Mesh::getMap() const {
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

            void Mesh::setMap(std::unordered_map<NRE::Voxel::PackedVertex, size_t> const& map) {
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

            void Mesh::constructMesh() {
                GLuint index;
                bool face[NRE::Voxel::FACE_NUM];

                for (unsigned int x = 0; x < Chunk::SIZE_X; x = x + 1) {
                    for (unsigned int y = 0; y < Chunk::SIZE_Y; y = y + 1) {
                        for (unsigned int z = 0; z < Chunk::SIZE_Z; z = z + 1) {
                            index = getVoxelIndex(x, y, z);
                            if (getTarget()->getVoxel(index)->getType() != NRE::Voxel::VOID) {
                                if (x == 0) {
                                    face[NRE::Voxel::XNegative] = true;
                                } else {
                                    face[NRE::Voxel::XNegative] = getTarget()->getVoxel(x - 1, y, z)->getType() == NRE::Voxel::VOID;
                                }

                                if (x == Chunk::SIZE_X - 1) {
                                    face[NRE::Voxel::XPositive] = true;
                                } else {
                                    face[NRE::Voxel::XPositive] = getTarget()->getVoxel(x + 1, y, z)->getType() == NRE::Voxel::VOID;
                                }

                                if (y == 0) {
                                    face[NRE::Voxel::YNegative] = true;
                                } else {
                                    face[NRE::Voxel::YNegative] = getTarget()->getVoxel(x, y - 1, z)->getType() == NRE::Voxel::VOID;
                                }

                                if (y == Chunk::SIZE_Y - 1) {
                                    face[NRE::Voxel::YPositive] = true;
                                } else {
                                    face[NRE::Voxel::YPositive] = getTarget()->getVoxel(x, y + 1, z)->getType() == NRE::Voxel::VOID;
                                }

                                if (z == 0) {
                                    face[NRE::Voxel::ZNegative] = true;
                                } else {
                                    face[NRE::Voxel::ZNegative] = getTarget()->getVoxel(x, y, z - 1)->getType() == NRE::Voxel::VOID;
                                }

                                if (z == Chunk::SIZE_Z - 1) {
                                    face[NRE::Voxel::ZPositive] = true;
                                } else {
                                    face[NRE::Voxel::ZPositive] = getTarget()->getVoxel(x, y, z + 1)->getType() == NRE::Voxel::VOID;
                                }

                                addVoxel(Maths::Point3D<GLuint>(x, y, z), Maths::Point3D<GLint>(x + target->getCoord().getX() * Chunk::SIZE_X, y + target->getCoord().getY() * Chunk::SIZE_Y, z), face);
                            }
                        }
                    }
                }
            }

            void Mesh::addVoxel(Maths::Point3D<GLuint> const& voxCoord, Maths::Point3D<GLint> const& realCoord, bool const (&face)[6]) {
                Maths::Point3D<GLint> p[4];
                Color::RGB voxColor = getTarget()->getVoxel(voxCoord)->getColor();

                if (face[NRE::Voxel::XNegative]) {
                    p[0] = {realCoord.getX(), realCoord.getY(), realCoord.getZ()};
                    p[1] = {realCoord.getX(), realCoord.getY() + 1, realCoord.getZ()};
                    p[2] = {realCoord.getX(), realCoord.getY(), realCoord.getZ() + 1};
                    p[3] = {realCoord.getX(), realCoord.getY() + 1, realCoord.getZ() + 1};

                    addPackedVertex(p, voxColor, NRE::Voxel::XNegative, static_cast <size_t> (target->getVoxel(voxCoord)->getType()));
                }

                if (face[NRE::Voxel::YNegative]) {
                    p[0] = {realCoord.getX() + 1, realCoord.getY(), realCoord.getZ()};
                    p[1] = {realCoord.getX(), realCoord.getY(), realCoord.getZ()};
                    p[2] = {realCoord.getX() + 1, realCoord.getY(), realCoord.getZ() + 1};
                    p[3] = {realCoord.getX(), realCoord.getY(), realCoord.getZ() + 1};

                    addPackedVertex(p, voxColor, NRE::Voxel::YNegative, static_cast <size_t> (target->getVoxel(voxCoord)->getType()));
                }

                if (face[NRE::Voxel::ZNegative]) {
                    p[0] = {realCoord.getX(), realCoord.getY(), realCoord.getZ()};
                    p[1] = {realCoord.getX() + 1, realCoord.getY(), realCoord.getZ()};
                    p[2] = {realCoord.getX(), realCoord.getY() + 1, realCoord.getZ()};
                    p[3] = {realCoord.getX() + 1, realCoord.getY() + 1, realCoord.getZ()};

                    addPackedVertex(p, voxColor, NRE::Voxel::ZNegative, static_cast <size_t> (target->getVoxel(voxCoord)->getType()));
                }

                if (face[NRE::Voxel::XPositive]) {
                    p[0] = {realCoord.getX() + 1, realCoord.getY() + 1, realCoord.getZ()};
                    p[1] = {realCoord.getX() + 1, realCoord.getY(), realCoord.getZ()};
                    p[2] = {realCoord.getX() + 1, realCoord.getY() + 1, realCoord.getZ() + 1};
                    p[3] = {realCoord.getX() + 1, realCoord.getY(), realCoord.getZ() + 1};

                    addPackedVertex(p, voxColor, NRE::Voxel::XPositive, static_cast <size_t> (target->getVoxel(voxCoord)->getType()));
                }

                if (face[NRE::Voxel::YPositive]) {
                    p[0] = {realCoord.getX(), realCoord.getY() + 1, realCoord.getZ()};
                    p[1] = {realCoord.getX() + 1, realCoord.getY() + 1, realCoord.getZ()};
                    p[2] = {realCoord.getX(),  realCoord.getY() + 1, realCoord.getZ() + 1};
                    p[3] = {realCoord.getX() + 1, realCoord.getY() + 1, realCoord.getZ() + 1};

                    addPackedVertex(p, voxColor, NRE::Voxel::YPositive, static_cast <size_t> (target->getVoxel(voxCoord)->getType()));
                }

                if (face[NRE::Voxel::ZPositive]) {
                    p[0] = {realCoord.getX() + 1, realCoord.getY(), realCoord.getZ() + 1};
                    p[1] = {realCoord.getX(), realCoord.getY(), realCoord.getZ() + 1};
                    p[2] = {realCoord.getX() + 1, realCoord.getY() + 1, realCoord.getZ() + 1};
                    p[3] = {realCoord.getX(), realCoord.getY() + 1, realCoord.getZ() + 1};

                    addPackedVertex(p, voxColor, NRE::Voxel::ZPositive, static_cast <size_t> (target->getVoxel(voxCoord)->getType()));
                }
            }

            void Mesh::addPackedVertex(Maths::Point3D<GLint> const (&p)[4], Color::RGB const& voxColor, GLuint const& face, size_t const& cCode) {
                Maths::Vector3D<GLbyte> n;
                GLuint idx0, idx1, idx2, nIdx;
                bool found;

                switch (face) {
                    case (NRE::Voxel::XNegative) : {
                        n = {-1, 0, 0};
                        break;
                    }
                    case (NRE::Voxel::YNegative) : {
                        n = {0, -1, 0};
                        break;
                    }
                    case (NRE::Voxel::ZNegative) : {
                        n = {0, 0, -1};
                        break;
                    }
                    case (NRE::Voxel::XPositive) : {
                        n = {1, 0, 0};
                        break;
                    }
                    case (NRE::Voxel::YPositive) : {
                        n = {0, 1, 0};
                        break;
                    }
                    case (NRE::Voxel::ZPositive) : {
                        n = {0, 0, 1};
                        break;
                    }
                    default : {
                    }
                }

                NRE::Voxel::PackedVertex packed(p[2], n, voxColor, static_cast <size_t> (face), cCode);
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

            bool const Mesh::getSimilarVertexIndex(NRE::Voxel::PackedVertex const& packed, std::unordered_map<NRE::Voxel::PackedVertex, size_t> const& map, GLuint &result) const {
                auto it = map.find(packed);
                if (it == map.end()) {
                    return false;
                } else {
                    result = it->second;
                    return true;
                }
            }

        };
    };
