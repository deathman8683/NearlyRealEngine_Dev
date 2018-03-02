
    #include "NRE_Chunk.hpp"

    namespace NRE {
        namespace World {

            GLuint Chunk::SIZE_X = 16;
            GLuint Chunk::SIZE_Y = 16;
            GLuint Chunk::SIZE_Z = 16;
            Maths::Vector3D<GLuint> Chunk::SIZE = Maths::Point2D<GLuint>(SIZE_X, SIZE_Y, SIZE_Z);

            Chunk::Chunk() : voxel(0) {
            }

            Chunk::Chunk(bool const& generateID) : Chunk(Maths::Point2D<GLint>(0, 0), generateID) {
            }

            Chunk::Chunk(Maths::Point2D<GLint> const& coord, bool const& generateID) : voxel(0), buffer(generateID), vao(generateID) {
                voxel = new Voxel[SIZE_X * SIZE_Y * SIZE_Z];
            }

            Chunk::Chunk(Chunk const& c) : voxel(0), buffer(true), vao(true) {
                voxel = new Voxel[SIZE_X * SIZE_Y * SIZE_Z];
                mempcy(voxel, c.getVoxels(), sizeof(Voxel));
            }

            Chunk::~Chunk() {
                delete voxel;
            }

            Voxel* const& Chunk::getVoxels() const {
                return voxel;
            }

            Voxel const& Chunk::getVoxel(Maths::Point3D<GLuint> const& p) const {
                return getVoxel(p.getX(), p.getY(), p.getZ());
            }

            Voxel const& Chunk::getVoxel(GLuint const& x, GLuint const& y, GLuint const& z) const {
                return voxel[getVoxelIndex(x, y, z)];
            }

            Maths::Point2D<GLint> const& Chunk::getCoord() const {
                return coord;
            }

            GL::IBO const& Chunk::getBuffer() const {
                return buffer;
            }

            GL::VAO const& Chunk::getVAO() const {
                return vao;
            }

            void Chunk::setVoxels(Voxel* const& vox) {
                voxel = vox;
            }

            void Chunk::setVoxel(Maths::Point3D<GLuint> const& p, Voxel const& vox) {
                setVoxel(p.getX(), p.getY(), p.getZ(), vox);
            }

            void Chunk::setVoxel(GLuint const& x, GLuint const& y, GLuint const& z, Voxel const& vox) {
                voxel[getVoxelIndex(x, y, z)] = vox;
            }

            void Chunk::setCoord(Maths::Point2D<GLint> const& p) {
                coord = p;
            }

            void Chunk::setBuffer(GL::IBO const& buffer) {
                this->buffer = buffer;
            }

            void Chunk::setVAO(GL::VAO const& vao) {
                this->vao = vao;
            }

            void Chunk::constructMesh() {

            }

            void Chunk::render() {

            }

            void getVoxelIndex(GLuint const& x, GLuint const& y, GLuint const& z) {
                return get1DIndexFrom3D(x, y, z, SIZE);
            }

        };
    };
