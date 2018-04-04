
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
                    static VoxelType** getVoxelTypes();
                    static Renderer::Material* getMaterialTypes();
                    static VoxelType* getVoxelType(GLubyte const& type);
                    static Renderer::Material const& getMaterial(GLubyte const& type);

                    //## Methods ##//
                    static void init();
                    static void free();

                private:
                    static VoxelType **voxelTypes;
                    static Renderer::Material *materialTypes;
            };

        };
    };
