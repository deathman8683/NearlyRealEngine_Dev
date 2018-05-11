
    /**
     * @file NRE_VoxelPoint.hpp
     * @brief Declaration of Engine's World's Object : VoxelPoint
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../../Generic/NRE_Type.hpp"
    #include "../../../Maths/NRE_Maths.hpp"
    #include "../../Chunk/NRE_Chunk.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace World
         * @brief Engine's World's Module>
         */
        namespace World {

            /**
             * @class VoxelPoint
             * @brief World's Object : Manage voxel's coordinate, regrouping his chunk's coord and position in the chunk
             */
            class VoxelPoint {
                private:
                    Maths::Point3D<GLuint> coord;   /**< The voxel's coordinates in the chunk */
                    Maths::Point2D<GLint> chunk;    /**< The voxel's chunk's coordinates */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        VoxelPoint();
                        /**
                         * Construct a voxel point from his real coordinates in world
                         * @param p the voxel's position in world
                         */
                        VoxelPoint(Maths::Point3D<GLint> const& p);

                    //## Copy-Constructor ##//
                        /**
                         * Copy p into this
                         * @param p the voxel point to copy the content
                         */
                        VoxelPoint(VoxelPoint const& p);

                    //## Move-Constructor ##//
                        /**
                         * Move p into this, leaving p empty
                         * @param p the voxel point to move
                         */
                        VoxelPoint(VoxelPoint && p);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * VoxelPoint Deconstructor
                         */
                        ~VoxelPoint();

                    //## Getter ##//
                        /**
                         * Coord getter
                         * @return the voxel's position in the chunk
                         */
                        Maths::Point3D<GLuint> const& getCoord() const;
                        /**
                         * Chunk's coord getter
                         * @return the chunk's coord where the voxel is
                         */
                        Maths::Point2D<GLint> const& getChunkCoord() const;

                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Compute the voxel's coord and chunk's coord from his real coordinates in world
                         * @param p the voxel's position in world
                         */
                        void compute(Maths::Point3D<GLint> const& p);

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of p into this
                         * @param p the voxel point to copy into this
                         * @return the reference of himself
                         */
                        VoxelPoint& operator=(VoxelPoint const& p);
                        /**
                         * Move assigment of p into this, leaving p empty
                         * @param p the voxel point to move into this
                         * @return the reference of himself
                         */
                        VoxelPoint& operator=(VoxelPoint && p);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
