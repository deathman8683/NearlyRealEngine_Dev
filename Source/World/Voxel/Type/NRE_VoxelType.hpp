
    /**
     * @file NRE_VoxelType.hpp
     * @brief Declaration of Engine's Voxel's Object : Grass
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_Voxel.hpp"
    #include "NRE_VoxelEnum.hpp"

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

            /**
             * @class Grass
             * @brief Voxel's Object : a grass type voxel
             */
            class Grass : public World::Voxel {
                public:
                    //## Constructor ##//
                    Grass();

                    //## Copy-Constructor ##//
                    Grass(Grass const& vox);

                    //## Deconstructor ##//
                    ~Grass();

                    //## Methods ##//
                    GLint const getType() const override;
                    Color::RGB const getColor() const override;
            };

            /**
             * @class Stone
             * @brief Voxel's Object : a stone type voxel
             */
            class Stone : public World::Voxel {
                public:
                    //## Constructor ##//
                    Stone();

                    //## Copy-Constructor ##//
                    Stone(Stone const& vox);

                    //## Deconstructor ##//
                    ~Stone();

                    //## Methods ##//
                    GLint const getType() const override;
                    Color::RGB const getColor() const override;
            };

        };
    };
