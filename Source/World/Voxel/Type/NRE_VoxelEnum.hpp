
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
                OCEAN,
                BEACH,
                SCORCHED,
                BARE,
                TUNDRA,
                SNOW,
                TEMPERATE_DESERT,
                SUBTROPICAL_DESERT,
                SHRUBLAND,
                TAIGA,
                GRASSLAND,
                TEMPERATE_DECIDUOUS_FOREST,
                TEMPERATE_RAIN_FOREST,
                TROPICAL_SEASONAL_FOREST,
                TROPICAL_RAIN_FOREST,
                TREE,

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
