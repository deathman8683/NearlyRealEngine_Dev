
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
    #include "../Voxel/Type/NRE_VoxelType.hpp"
    #include "../../GL_Wrapper/VAO/NRE_VAO.hpp"
    #include "../../Renderer/Shader/NRE_Shader.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace World
         * @brief Engine's Voxel's Type's Module
         */
        namespace World {

            /**
             * @class Chunk
             * @brief World's Object : A collection of voxel
             */
            class Chunk {
                private:
                    Voxel **voxel;
                    Maths::Point2D<GLint> coord;
                    GL::IBO buffer;
                    GL::VAO vao;

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
                    Voxel** const& getVoxels() const;
                    Voxel* const& getVoxel(Maths::Point3D<GLuint> const& p) const;
                    Voxel* const& getVoxel(GLuint const& x, GLuint const& y, GLuint const& z) const;
                    Voxel* const& getVoxel(GLuint const& index) const;
                    Maths::Point2D<GLint> const& getCoord() const;
                    GL::IBO const& getBuffer() const;
                    GL::VAO const& getVAO() const;

                    //## Setter ##//
                    void setVoxels(Voxel** const& vox);
                    void setVoxel(Maths::Point3D<GLuint> const& p, Voxel* const& vox);
                    void setVoxel(GLuint const& x, GLuint const& y, GLuint const& z, Voxel* const& vox);
                    void setVoxel(GLuint const& index, Voxel* const& vox);
                    void setCoord(Maths::Point2D<GLint> const& p);
                    void setBuffer(GL::IBO const& buffer);
                    void setVAO(GL::VAO const& vao);

                    //## Methods ##//
                    void constructMesh();
                    void render(Renderer::Shader const& shader, Maths::Matrix4x4<NREfloat> &modelview, Maths::Matrix4x4<NREfloat> &projection);
                    void save();
                    void load();
                    void loadVoxels(GLuint &x, GLuint &y, GLuint &z, GLuint const& nb, GLuint const& type);

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
            };

            GLuint getVoxelIndex(GLuint const& x, GLuint const& y, GLuint const& z);

        };
    };
