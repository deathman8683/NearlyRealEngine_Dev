
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
                    Voxel *voxel;                   /**< Voxel array*/
                    Maths::Point2D<GLint> coord;    /**< Chunk coordinates */
                    GL::IBO buffer;                 /**< Chunk rendering buffer */
                    GL::VAO vao;                    /**< Chunk rendering VAO */
                    Physics::AABB<GLint> bounding;  /**< Chunk bounding box */
                    GLuint maxSolidHeight;          /**< The maximum height with solid voxel */
                    bool active;                    /**< Active state, for rendering purpose */
                    bool loaded;                    /**< Loaded state, for rendering/loading purpose */
                    bool constructed;               /**< Constructed state, for rendering/loading purpose */
                    bool loading;                   /**< Loading state, for loading purpose */
                    bool constructing;              /**< Constructing state, for loading purpose */
                    bool modified;                  /**< Modified state, for saving purpose */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Chunk();
                        /**
                         * Construct a chunk and generate buffer's id on fly or not
                         * @param generateID tell if the constructor has to generate buffer's id on fly
                         */
                        Chunk(bool const& generateID);
                        /**
                         * Construct a chunk with given coordinates and id's generation or not
                         * @param coord      the new chunk coordinates
                         * @param generateID tell if the constructor has to generate buffer's id on fly
                         */
                        Chunk(Maths::Point2D<GLint> const& coord, bool const& generateID);

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param c the chunk to copy the content
                         */
                         Chunk(Chunk const& c) = delete;

                     //## Move-Constructor ##//
                         /**
                          * Move c into this, leaving c empty
                          * @param c the chunk to move
                          */
                         Chunk(Chunk && c);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * Chunk Deconstructor
                         */
                        ~Chunk();

                    //## Getter ##//
                        /**
                         * Specific Voxel getter
                         * @param  p the voxel's coordinates
                         * @return   the corresponding voxel
                         */
                        Voxel const& getVoxel(Maths::Point3D<GLuint> const& p) const;
                        /**
                         * Specific Voxel getter
                         * @param  x the voxel's x coordinate
                         * @param  y the voxel's y coordinate
                         * @param  z the voxel's z coordinate
                         * @return   the corresponding voxel
                         */
                        Voxel const& getVoxel(GLuint const& x, GLuint const& y, GLuint const& z) const;
                        /**
                         * Specific Voxel getter
                         * @param  index the already computed voxel index (3D to 1D)
                         * @return       the corresponding voxel
                         */
                        Voxel const& getVoxel(GLuint const& index) const;
                        /**
                         * Coordinates getter
                         * @return the chunk's coordinates value
                         */
                        Maths::Point2D<GLint> const& getCoord() const;
                        /**
                         * Buffer getter
                         * @return the chunk's rendering buffer
                         */
                        GL::IBO const& getBuffer() const;
                        /**
                         * VAO getter
                         * @return the chunk's rendering VAO
                         */
                        GL::VAO const& getVAO() const;
                        /**
                         * Bounding getter
                         * @return the chunk's AABB object
                         */
                        Physics::AABB<GLint> const& getBounding() const;
                        /**
                         * Maximum solid voxel height getter
                         * @return the chunk's maximum height of solid voxel
                         */
                        GLuint const& getMaxSolidHeight() const;
                        /**
                         * Active state getter
                         * @return the chunk's active state
                         */
                        bool const& isActive() const;
                        /**
                         * Loaded state getter
                         * @return the chunk's loaded state
                         */
                        bool const& isLoaded() const;
                        /**
                         * Constructed state getter
                         * @return the chunk's constructed state
                         */
                        bool const& isConstructed() const;
                        /**
                         * Loading state getter
                         * @return the chunk's loading state
                         */
                        bool const& isLoading() const;
                        /**
                         * Constructing state constructing
                         * @return the chunk's active state
                         */
                        bool const& isConstructing() const;
                        /**
                         * Modified state getter
                         * @return the chunk's modified state
                         */
                        bool const& isModfied() const;

                    //## Setter ##//
                        /**
                         * Specific Voxel setter
                         * @param p   the voxel's coordinates
                         * @param vox the new voxel object
                         */
                        void setVoxel(Maths::Point3D<GLuint> const& p, Voxel const& vox);
                        /**
                         * Specific Voxel setter
                         * @param x   the voxel's x coordinate
                         * @param y   the voxel's y coordinate
                         * @param z   the voxel's z coordinate
                         * @param vox the new voxel object
                         */
                        void setVoxel(GLuint const& x, GLuint const& y, GLuint const& z, Voxel const& vox);
                        /**
                         * Specific Voxel setter
                         * @param index the already computed voxel index (3D to 1D)
                         * @param vox the new voxel object
                         */
                        void setVoxel(GLuint const& index, Voxel const& vox);
                        /**
                         * Coordinates setter
                         * @param p the new coordinates value
                         */
                        void setCoord(Maths::Point2D<GLint> const& p);
                        /**
                         * Bounding setter
                         * @param box the new AABB object
                         */
                        void setBounding(Physics::AABB<GLint> const& box);
                        /**
                         * Maximum solid voxel height setter
                         * @param height the new maximum solid voxel height value
                         */
                        void setMaxSolidHeight(GLuint const& height);
                        /**
                         * Active state setter
                         * @param state the new active state value
                         */
                        void setActive(bool const& state);
                        /**
                         * Active state setter
                         * @param state the new active state value
                         */
                        void setLoaded(bool const& state);
                        /**
                         * Constructed state setter
                         * @param state the new constructed state value
                         */
                        void setConstructed(bool const& state);
                        /**
                         * Loading state setter
                         * @param state the new loading state value
                         */
                        void setLoading(bool const& state);
                        /**
                         * Constructing state setter
                         * @param state the new constructing state value
                         */
                        void setConstructing(bool const& state);
                        /**
                         * Modified state setter
                         * @param state the new modified state value
                         */
                        void setModified(bool const& state);

                    //## Methods ##//
                        /**
                         * Construct the chunk's mesh
                         * @param w the world used to compute chunk border
                         */
                        void constructMesh(World* w);
                        /**
                         * Render the chunk using the VAO
                         */
                        void render();
                        /**
                         * Save the chunk into a passed file stream
                         * @param chunkFile the chunk's file stream
                         */
                        void save(std::fstream &chunkFile);
                        /**
                         * Load the chunk from a passed file stream
                         * @param chunkFile the chunk's file stream
                         * @param w         the world used to generate procedural terrain if necessary
                         */
                        void load(std::fstream &chunkFile, World* w);
                        /**
                         * Load a number of voxel with a based coordinate and a type
                         * @param x    the first voxel x coordinate
                         * @param y    the first voxel y coordinate
                         * @param z    the first voxel z coordinate
                         * @param nb   the number of voxel to add, used to increment through coordinates
                         * @param type the voxel's type to add
                         */
                        void loadVoxels(GLuint &x, GLuint &y, GLuint &z, GLuint const& nb, GLuint const& type);
                        /**
                         * Construct a procedural terrain from a custom generator using FastNoise library
                         * @param w the world used to get the seed and FastNoise generator
                         */
                        void createProceduralTerrain(World* w);
                        /**
                         * Update the active state with a camera, using the camera's view frustum
                         * @param camera the camera to use the view frustum and perform AABB test
                         */
                        void checkActiveState(Camera::FixedCamera const& camera);
                        /**
                         * Reload the chunk's ID, reset chunk's state
                         */
                        void reload();
                        /**
                         * Write compressed data into a string stream for later process in save system
                         * @param data the string stream to add compressed data
                         */
                        void writeCompressedData(std::stringstream &data);

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy allowed
                         * @param c the chunk to copy into this
                         * @return the reference of himself
                         */
                        Chunk& operator=(Chunk const& c) = delete;
                        /**
                         * Move assigment of c into this, leaving c empty
                         * @param c the chunk to move into this
                         * @return the reference of himself
                         */
                        Chunk& operator=(Chunk && c);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                public:
                    static GLuint SIZE_X;               /**< The default Size X of the voxel array */
                    static GLuint SIZE_Y;               /**< The default Size Y of the voxel array */
                    static GLuint SIZE_Z;               /**< The default Size Z of the voxel array */
                    static Maths::Vector3D<GLuint> SIZE;/**< The default Size vector of the voxel array */
                    static GLuint SECTOR_SIZE;          /**< The sector size in bytes in a region file */
                    static GLuint LOOKUP_SIZE;          /**< The lookup table size in bytes in a region file */
            };

            /**
             * Outstream operation for Chunk
             * @param stream the out stream to add the chunk c
             * @param c the chunk to add in the stream
             * @return the modified outstream
             */
            inline std::ostream& operator<<(std::ostream &stream, Chunk const& c) {
                stream << "(" << c.getCoord() << "," << c.getBuffer() << "," << c.getVAO() << ")";
                return stream;
            }

            /**
             * Compute the voxel 1D index from 3D coordinates
             * @param  x the voxel's x coordinate
             * @param  y the voxel's y coordinate
             * @param  z the voxel's z coordinate
             * @return   the computed index using array operation function
             */
            GLuint getVoxelIndex(GLuint const& x, GLuint const& y, GLuint const& z);

        };
    };
