
    /**
     * @file NRE_Chunk.hpp
     * @brief Declaration of Engine's World's Object : Chunk
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include <sstream>
    #include <fstream>
    #include "../../Generic/Array/NRE_ArrayOperation.hpp"
    #include "../../GL_Wrapper/Buffer/VAO/NRE_VAO.hpp"
    #include "../../GL_Wrapper/BufferObject/IBO/NRE_IBO.hpp"
    #include "../../Renderer/Shader/NRE_Shader.hpp"
    #include "../../lib/FastNoise/FastNoise.h"
    #include "../../Camera/FixedCamera/NRE_FixedCamera.hpp"
    #include "../Voxel/NRE_Voxel.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace World
         * @brief Engine's World's Module
         */
        namespace World {

            class World;

            /**
             * @class Chunk
             * @brief World's Object : A collection of voxel
             */
            class Chunk {
                private:
                    Voxel *voxel;
                    Maths::Point2D<GLint> coord;
                    GL::IBO buffer;
                    GL::VAO vao;
                    Physics::AABB<GLint> bounding;
                    bool active;

                public:
                    //## Constructor ##//
                    Chunk();
                    Chunk(bool const& generateID);
                    Chunk(Maths::Point2D<GLint> const& coord, bool const& generateID);

                    //## Copy-Constructor ##//
                    Chunk(Chunk const& c);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~Chunk();

                    //## Getter ##//
                    Voxel* const& getVoxels() const;
                    Voxel const& getVoxel(Maths::Point3D<GLuint> const& p) const;
                    Voxel const& getVoxel(GLuint const& x, GLuint const& y, GLuint const& z) const;
                    Voxel const& getVoxel(GLuint const& index) const;
                    Maths::Point2D<GLint> const& getCoord() const;
                    GL::IBO const& getBuffer() const;
                    GL::VAO const& getVAO() const;
                    Physics::AABB<GLint> const& getBounding() const;
                    bool const& isActive() const;

                    //## Setter ##//
                    void setVoxels(Voxel* const& vox);
                    void setVoxel(Maths::Point3D<GLuint> const& p, Voxel const& vox);
                    void setVoxel(GLuint const& x, GLuint const& y, GLuint const& z, Voxel const& vox);
                    void setVoxel(GLuint const& index, Voxel const& vox);
                    void setCoord(Maths::Point2D<GLint> const& p);
                    void setBuffer(GL::IBO const& buffer);
                    void setVAO(GL::VAO const& vao);
                    void setBounding(Physics::AABB<GLint> const& box);
                    void setActive(bool const& state);

                    //## Methods ##//
                    void constructMesh(World* w);
                    void render(Renderer::Shader const& shader, Maths::Matrix4x4<NREfloat> &MVP, Camera::FixedCamera const& camera);
                    void save(std::fstream &chunkFile);
                    void load(std::fstream &chunkFile, World* w);
                    void loadVoxels(GLuint &x, GLuint &y, GLuint &z, GLuint const& nb, GLuint const& type);
                    void createProceduralTerrain(World* w);
                    void checkActiveState(Camera::FixedCamera const& camera);

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                public:
                    static GLuint SIZE_X;
                    static GLuint SIZE_Y;
                    static GLuint SIZE_Z;
                    static Maths::Vector3D<GLuint> SIZE;
                    static GLuint SECTOR_SIZE;
                    static GLuint LOOKUP_SIZE;
            };

            inline std::ostream& operator<<(std::ostream &stream, Chunk const& c) {
                stream << "(" << c.getCoord() << "," << c.getBuffer() << "," << c.getVAO() << ")";
                return stream;
            }

            GLuint getVoxelIndex(GLuint const& x, GLuint const& y, GLuint const& z);

        };
    };
