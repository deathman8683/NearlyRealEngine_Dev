
    /**
     * @file NRE_NRE_VoxelEnum.hpp
     * @brief Declaration of Engine's Voxel's Object : TypeEnum
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace Voxel
         * @brief Engine's Voxel's Type's Module
         */
        namespace Voxel {

            enum VoxelType {
                VOID,
                GRASS,
                STONE,
                WATER,

                TYPE_NUM
            };

            enum VoxelFace {
                XNegative,
                YNegative,
                ZNegative,
                XPositive,
                YPositive,
                ZPositive,

                FACE_NUM
            };

        };
    };
