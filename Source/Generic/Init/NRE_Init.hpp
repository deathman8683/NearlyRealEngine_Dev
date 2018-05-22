
    /**
     * @file NRE_Init.hpp
     * @brief Declaration of Engine's Initialization Module
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../World/Voxel/Type/VoxelTypes/NRE_VoxelTypes.hpp"
    #include "../../Object/MergingCache/NRE_MergingCache.hpp"
    #include "../../Renderer/Shader/ShadersManager/NRE_ShadersManager.hpp"
    #include "../../Renderer/Material/MaterialsManager/NRE_MaterialsManager.hpp"
    #include "../../Light/LightsManager/NRE_LightsManager.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {

        /**
         * Initialize the engine
         */
        void init();
        /**
         * Desallocate engine's global singleton
         */
        void quit();

    };
