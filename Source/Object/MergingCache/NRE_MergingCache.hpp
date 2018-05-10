
    /**
     * @file NRE_MergingCache.hpp
     * @brief Declaration of Engine's Object's Object : MergingCache
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../Generic/NRE_Type.hpp"
    #include "../../Generic/Array/NRE_ArrayOperation.hpp"
    #include "../../Maths/NRE_Maths.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace Object
         * @brief The Engine's Object's managing system>
         */
        namespace Object {

            /**
             * @class MergingCache
             * @brief Object's Object : A singleton used to manage the global cache used in 3D mesh construction
             */
            class MergingCache {
                public:
                    //## Getter ##//
                        /**
                         * Voxel Face Merged State getter
                         * @param  p    the voxel's coordinates
                         * @param  face the voxel's face to check
                         * @return      the face merged state
                         */
                        static bool const& getVoxelMergingFace(Maths::Point3D<GLuint> const& p, int const& face);
                        /**
                         * Voxel Face Merged State getter
                         * @param  x    the voxel's x coordinate
                         * @param  y    the voxel's y coordinate
                         * @param  z    the voxel's z coordinate
                         * @param  face the voxel's face to check
                         * @return      the face merged state
                         */
                        static bool const& getVoxelMergingFace(GLuint const& x, GLuint const& y, GLuint const& z, int const& face);

                    //## Setter ##//
                        /**
                         * Voxel Face Merged State setter
                         * @param  p    the voxel's coordinates
                         * @param  face the voxel's face to modify
                         * @param state the new voxel's face merged state value
                         */
                        static void setVoxelMergingFace(Maths::Point3D<GLuint> const& p, int const& face, bool const& state);
                        /**
                         * Voxel Face Merged State setter
                         * @param  x    the voxel's x coordinate
                         * @param  y    the voxel's y coordinate
                         * @param  z    the voxel's z coordinate
                         * @param  face the voxel's face to modify
                         * @param state the new voxel's face merged state value
                         */
                        static void setVoxelMergingFace(GLuint const& x, GLuint const& y, GLuint const& z, int const& face, bool const& state);

                    //## Methods ##//
                        /**
                         * Allocate the cache
                         */
                        static void init();
                        /**
                         * Free the cache
                         */
                        static void free();
                        /**
                         * Reset the cache's values
                         */
                        static void reset();

                private:
                    static bool *cache;                     /**< The merging cache */
                    static Maths::Vector4D<GLuint> size;    /**< The cache 4D size */
            };

        };
    };
