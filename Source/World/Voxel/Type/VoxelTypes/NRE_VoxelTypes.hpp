
    /**
     * @file NRE_VoxelType.hpp
     * @brief Declaration of Engine's World's Object : VoxelTypes
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../VoxelType/Type/NRE_Type.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace Voxel
         * @brief Engine's Voxel's Type's Module
         */
        namespace World {

            /**
             * @class VoxelTypes
             * @brief World's Object : a Voxel manager, VoxelType Singleton
             */
            class VoxelTypes {
                public:
                    //## Getter ##//
                        /**
                         * Array size getter
                         * @return the size of the voxel type array
                         */
                        static GLuint const& getSize();
                        /**
                         * Specific voxel type getter
                         * @param  type the specific type enum
                         * @return      the corresponding voxel type object
                         */
                        static VoxelType* getVoxelType(GLubyte const& type);
                        /**
                         * Specific material type getter
                         * @param  type the specific type enum
                         * @return      the corresponding material type object
                         */
                        static Renderer::Material& getMaterial(GLubyte const& type);

                    //## Methods ##//
                        /**
                         * Initialize both voxel and material array
                         */
                        static void init();
                        /**
                         * Free both voxel and material array
                         */
                        static void free();

                private:
                    static VoxelType **voxelTypes;              /**< Store all differents voxel types */
                    static Renderer::Material *materialTypes;   /**< Store all differents material types */
                public:
                    static GLuint size;                         /**< The size of both types array */
            };

        };
    };
