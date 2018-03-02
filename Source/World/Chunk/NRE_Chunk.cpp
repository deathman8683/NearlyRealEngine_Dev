
    #include "NRE_Chunk.hpp"

    namespace NRE {
        namespace World {

            Chunk::Chunk() : voxel(0) {
            }

            Chunk::Chunk(bool const& generateID) : Chunk(Maths::Point2D<GLint>(0, 0), generateID) {
            }

            Chunk::Chunk(Maths::Point2D<GLint> const& coord, bool const& generateID) : voxel(0), buffer(generateID), vao(generateID) {

            }
            
            Chunk::Chunk(Chunk const& c);
            Chunk::~Chunk();
            Voxel* const& Chunk::getVoxel(Maths::Point3D<GLuint> const& p) const;
            Voxel* const& Chunk::getVoxel(GLuint const& x, GLuint const& y, GLuint const& z) const;
            Maths::Point2D<GLint> const& Chunk::getCoord() const;
            GL::IBO const& Chunk::getBuffer() const;
            GL::VAO const& Chunk::getVAO() const;
            void Chunk::setVoxel(Maths::Point3D<GLuint> const& p, Voxel const& vox);
            void Chunk::setVoxel(GLuint const& x, GLuint const& y, GLuint const& z, Voxel const& vox);
            void Chunk::setCoord(Maths::Point2D<GLint> const& p);
            void Chunk::setBuffer(GL::IBO const& buffer);
            void Chunk::setVAO(GL::VAO const& vao);
            void Chunk::constructMesh();
            void Chunk::render();

        };
    };
