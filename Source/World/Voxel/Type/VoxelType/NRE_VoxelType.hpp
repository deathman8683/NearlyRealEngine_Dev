
    /**
     * @file NRE_VoxelType.hpp
     * @brief Declaration of Engine's Voxel's Object : VoxelType
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../../../Renderer/Color/NRE_Color.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace World
         * @brief Engine's World's Type's Module
         */
        namespace World {

            /**
             * @class VoxelType
             * @brief World's Object :
             */
            class VoxelType {
                public:
                    //## Constructor ##//
                    VoxelType();

                    //## Deconstructor ##//
                    ~VoxelType();

                    //## Getter ##//
                    virtual Color::RGB const getColor() const = 0;
            };

        };
    };
