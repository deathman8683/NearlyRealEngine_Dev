
    /**
     * @file NRE_VoxelType.hpp
     * @brief Declaration of Engine's Voxel's Object : VoxelType
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../../../Renderer/Material/NRE_Material.hpp"
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
                        /**
                         * Default Constructor
                         */
                        VoxelType();

                    //## Deconstructor ##//
                        /**
                         * VoxelType Deconstructor
                         */
                        virtual ~VoxelType();

                    //## Getter ##//
                        /**
                         * Solid state getter
                         * @return if the voxel is solid or not
                         */
                        virtual bool const isSolid() const = 0;
                        /**
                         * Voxel material getter
                         * @return the voxel's material's path
                         */
                        virtual std::string const getMaterialPath() const = 0;
            };

        };
    };
