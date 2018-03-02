
    /**
     * @file NRE_Chunk.hpp
     * @brief Declaration of Engine's World's Object : Chunk
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../Generic/NRE_Type.hpp"
    #include "../Voxel/Type/NRE_VoxelType.hpp"
    #include "../../Maths/NRE_Maths.hpp"
    #include "../../GL_Wrapper/VAO/NRE_VAO.hpp"

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
                    Voxel *voxel;
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
                    Voxel* const& getVoxel(Maths::Point3D<GLuint> const& p) const;
                    Voxel* const& getVoxel(GLuint const& x, GLuint const& y, GLuint const& z) const;
                    Maths::Point2D<GLint> const& getCoord() const;
                    GL::IBO const& getBuffer() const;
                    GL::VAO const& getVAO() const;

                    //## Setter ##//
                    void setVoxel(Maths::Point3D<GLuint> const& p, Voxel const& vox);
                    void setVoxel(GLuint const& x, GLuint const& y, GLuint const& z, Voxel const& vox);
                    void setCoord(Maths::Point2D<GLint> const& p);
                    void setBuffer(GL::IBO const& buffer);
                    void setVAO(GL::VAO const& vao);

                    //## Methods ##//
                    void constructMesh();
                    void render();

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
