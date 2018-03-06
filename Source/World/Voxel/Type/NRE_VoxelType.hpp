
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
             * @class Void
             * @brief Voxel's Object : a void type voxel
             */
            class Void : public World::Voxel {
                public:
                    //## Constructor ##//
                    Void();

                    //## Copy-Constructor ##//
                    Void(Void const& vox);

                    //## Deconstructor ##//
                    ~Void();

                    //## Methods ##//
                    GLint const getType() const override;
                    Color::RGB const getColor() const override;
            };

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

            /**
             * @class Water
             * @brief Voxel's Object : a water type voxel
             */
            class Water : public World::Voxel {
                public:
                    //## Constructor ##//
                    Water();

                    //## Copy-Constructor ##//
                    Water(Water const& vox);

                    //## Deconstructor ##//
                    ~Water();

                    //## Methods ##//
                    GLint const getType() const override;
                    Color::RGB const getColor() const override;
            };

        };
    };
