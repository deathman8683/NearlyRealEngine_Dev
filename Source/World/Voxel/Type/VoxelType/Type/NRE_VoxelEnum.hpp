
    /**
     * @file NRE_VoxelEnum.hpp
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
        namespace World {

            /**
             * @enum VoxelTypeEnum
             * Regroup all different voxel type name
             */
            enum VoxelTypeEnum {
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

                TYPE_NUM    /**< Number of voxel type */
            };

            /**
             * @enum VoxelFace
             * Regroup voxel face designation
             */
            enum VoxelFace {
                XNegative,  /**< Back */
                YNegative,  /**< Left */
                ZNegative,  /**< Bottom */
                XPositive,  /**< Front */
                YPositive,  /**< Right */
                ZPositive,  /**< Top */

                FACE_NUM    /**< Number of faces */
            };

        };
    };
