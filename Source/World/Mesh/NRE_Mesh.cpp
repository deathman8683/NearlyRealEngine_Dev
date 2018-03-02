
    #include "NRE_Mesh.hpp"

    namespace NRE {
        namespace World {

            Mesh::Mesh() {
            }

            Mesh::Mesh(Mesh const& mesh) : vertices(mesh.getVData()), color(mesh.getCData()), normal(mesh.getNData()), index(mesh.getIData()), map(mesh.getMap()) {
            }

            Mesh::~Mesh() {
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

            std::vector<GLint>* const& Mesh::getVPointer() const {
                return &vData.front();
            }

            std::vector<GLfloat>* const& Mesh::getCPointer() const {
                return &cData.front();
            }

            std::vector<GLbyte>* const& Mesh::getNPointer() const {
                return &nData.front();
            }

            std::vector<GLuint>* const& Mesh::getIPointer() const {
                return &iData.front();
            }

            std::unordered_map<Voxel::PackedVertex<GLint>, size_t> const& Mesh::getMap() const {
                return map;
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

            void Mesh::setMap(std::unordered_map<Voxel::PackedVertex<GLint>, size_t> const& map) {
                this->map = map;
            }

            void Mesh::addVertex(Maths::Point3D<GLint> const& v) {
                vData.push_back(v.getX());
                vData.push_back(v.getY());
                vData.push_back(v.getZ());
            }

            void Mesh::addColor(Color::RGB const& c) {
                cData.push_back(c.getR());
                cData.push_back(c.getG());
                cData.push_back(c.getB());
            }

            void Mesh::addNormal(Maths::Vector3D<GLbyte> const& n) {
                nData.push_back(n.getX());
                nData.push_back(n.getY());
                nData.push_back(n.getZ());
            }

            void Mesh::addIndex(GLuint const& index) {
                iData.push_back(index);
            }

        };
    };
