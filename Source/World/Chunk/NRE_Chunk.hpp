
    /**
     * @file NRE_Chunk.hpp
     * @brief Declaration of Engine's World's Object : Chunk
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include <sstream>
    #include <fstream>
    #include "../../Renderer/Shader/NRE_Shader.hpp"
    #include "../../Camera/FixedCamera/NRE_FixedCamera.hpp"
    #include "../../GL_Wrapper/BufferObject/VBO/NRE_VBO.hpp"
    #include "../../Object/3D/VoxelObject/NRE_VoxelObject.hpp"

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
            class Chunk : public Object::VoxelObject {
                private:
                    Maths::Point2D<GLint> coord;    /**< Chunk coordinates */
                    Physics::AABB<GLint> bounding;  /**< Chunk bounding box */
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
                         * Construct a chunk with given coordinates
                         * @param coord      the new chunk coordinates
                         */
                        Chunk(Maths::Point2D<GLint> const& coord);

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
                         * Coordinates getter
                         * @return the chunk's coordinates value
                         */
                        Maths::Point2D<GLint> const& getCoord() const;
                        /**
                         * Bounding getter
                         * @return the chunk's AABB object
                         */
                        Physics::AABB<GLint> const& getBounding() const;
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
                        /**
                         * Voxel's type setter
                         * @param p    the voxel's coordinates
                         * @param type the new voxel's type
                         */
                        void setType(Maths::Point3D<GLuint> const& p, GLubyte const& type);

                    //## Methods ##//
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
                         * Construct a procedural terrain from a custom generator using FastNoise library
                         * @param w the world used to get the seed and FastNoise generator
                         */
                        void createProceduralTerrain(World* w);
                        /**
                         * Update the active state with a camera, using the camera's view frustum
                         * @param camera the camera to use the view frustum and perform AABB test
                         */
                        void checkActiveState(Camera::FixedCamera* camera);
                        /**
                         * Reload the chunk's ID, reset chunk's state
                         */
                        void reload();

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
                stream << "(" << c.getCoord() << ")";
                return stream;
            }

        };
    };
