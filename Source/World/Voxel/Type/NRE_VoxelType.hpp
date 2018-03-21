
    /**
     * @file NRE_VoxelType.hpp
     * @brief Declaration of Engine's Voxel's Object : VoxelType
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
             * @class Ocean
             * @brief Voxel's Object : a grass type voxel
             */
            class Ocean : public World::Voxel {
                public:
                    //## Constructor ##//
                    Ocean();

                    //## Copy-Constructor ##//
                    Ocean(Ocean const& vox);

                    //## Deconstructor ##//
                    ~Ocean();

                    //## Methods ##//
                    GLint const getType() const override;
                    Color::RGB const getColor() const override;
            };

            /**
             * @class Beach
             * @brief Voxel's Object : a grass type voxel
             */
            class Beach : public World::Voxel {
                public:
                    //## Constructor ##//
                    Beach();

                    //## Copy-Constructor ##//
                    Beach(Beach const& vox);

                    //## Deconstructor ##//
                    ~Beach();

                    //## Methods ##//
                    GLint const getType() const override;
                    Color::RGB const getColor() const override;
            };

            /**
             * @class Scorched
             * @brief Voxel's Object : a grass type voxel
             */
            class Scorched : public World::Voxel {
                public:
                    //## Constructor ##//
                    Scorched();

                    //## Copy-Constructor ##//
                    Scorched(Scorched const& vox);

                    //## Deconstructor ##//
                    ~Scorched();

                    //## Methods ##//
                    GLint const getType() const override;
                    Color::RGB const getColor() const override;
            };

            /**
             * @class Bare
             * @brief Voxel's Object : a grass type voxel
             */
            class Bare : public World::Voxel {
                public:
                    //## Constructor ##//
                    Bare();

                    //## Copy-Constructor ##//
                    Bare(Bare const& vox);

                    //## Deconstructor ##//
                    ~Bare();

                    //## Methods ##//
                    GLint const getType() const override;
                    Color::RGB const getColor() const override;
            };

            /**
             * @class Tundra
             * @brief Voxel's Object : a grass type voxel
             */
            class Tundra : public World::Voxel {
                public:
                    //## Constructor ##//
                    Tundra();

                    //## Copy-Constructor ##//
                    Tundra(Tundra const& vox);

                    //## Deconstructor ##//
                    ~Tundra();

                    //## Methods ##//
                    GLint const getType() const override;
                    Color::RGB const getColor() const override;
            };

            /**
             * @class Snow
             * @brief Voxel's Object : a grass type voxel
             */
            class Snow : public World::Voxel {
                public:
                    //## Constructor ##//
                    Snow();

                    //## Copy-Constructor ##//
                    Snow(Snow const& vox);

                    //## Deconstructor ##//
                    ~Snow();

                    //## Methods ##//
                    GLint const getType() const override;
                    Color::RGB const getColor() const override;
            };

            /**
             * @class TemperateDesert
             * @brief Voxel's Object : a grass type voxel
             */
            class TemperateDesert : public World::Voxel {
                public:
                    //## Constructor ##//
                    TemperateDesert();

                    //## Copy-Constructor ##//
                    TemperateDesert(TemperateDesert const& vox);

                    //## Deconstructor ##//
                    ~TemperateDesert();

                    //## Methods ##//
                    GLint const getType() const override;
                    Color::RGB const getColor() const override;
            };

            /**
             * @class SubtropicalDesert
             * @brief Voxel's Object : a grass type voxel
             */
            class SubtropicalDesert : public World::Voxel {
                public:
                    //## Constructor ##//
                    SubtropicalDesert();

                    //## Copy-Constructor ##//
                    SubtropicalDesert(SubtropicalDesert const& vox);

                    //## Deconstructor ##//
                    ~SubtropicalDesert();

                    //## Methods ##//
                    GLint const getType() const override;
                    Color::RGB const getColor() const override;
            };

            /**
             * @class Shrubland
             * @brief Voxel's Object : a grass type voxel
             */
            class Shrubland : public World::Voxel {
                public:
                    //## Constructor ##//
                    Shrubland();

                    //## Copy-Constructor ##//
                    Shrubland(Shrubland const& vox);

                    //## Deconstructor ##//
                    ~Shrubland();

                    //## Methods ##//
                    GLint const getType() const override;
                    Color::RGB const getColor() const override;
            };

            /**
             * @class Taiga
             * @brief Voxel's Object : a grass type voxel
             */
            class Taiga : public World::Voxel {
                public:
                    //## Constructor ##//
                    Taiga();

                    //## Copy-Constructor ##//
                    Taiga(Taiga const& vox);

                    //## Deconstructor ##//
                    ~Taiga();

                    //## Methods ##//
                    GLint const getType() const override;
                    Color::RGB const getColor() const override;
            };

            /**
             * @class Grassland
             * @brief Voxel's Object : a grass type voxel
             */
            class Grassland : public World::Voxel {
                public:
                    //## Constructor ##//
                    Grassland();

                    //## Copy-Constructor ##//
                    Grassland(Grassland const& vox);

                    //## Deconstructor ##//
                    ~Grassland();

                    //## Methods ##//
                    GLint const getType() const override;
                    Color::RGB const getColor() const override;
            };

            /**
             * @class TemperateDeciduousForest
             * @brief Voxel's Object : a grass type voxel
             */
            class TemperateDeciduousForest : public World::Voxel {
                public:
                    //## Constructor ##//
                    TemperateDeciduousForest();

                    //## Copy-Constructor ##//
                    TemperateDeciduousForest(TemperateDeciduousForest const& vox);

                    //## Deconstructor ##//
                    ~TemperateDeciduousForest();

                    //## Methods ##//
                    GLint const getType() const override;
                    Color::RGB const getColor() const override;
            };

            /**
             * @class TemperateRainForest
             * @brief Voxel's Object : a grass type voxel
             */
            class TemperateRainForest : public World::Voxel {
                public:
                    //## Constructor ##//
                    TemperateRainForest();

                    //## Copy-Constructor ##//
                    TemperateRainForest(TemperateRainForest const& vox);

                    //## Deconstructor ##//
                    ~TemperateRainForest();

                    //## Methods ##//
                    GLint const getType() const override;
                    Color::RGB const getColor() const override;
            };

            /**
             * @class TropicalSeasonalForest
             * @brief Voxel's Object : a grass type voxel
             */
            class TropicalSeasonalForest : public World::Voxel {
                public:
                    //## Constructor ##//
                    TropicalSeasonalForest();

                    //## Copy-Constructor ##//
                    TropicalSeasonalForest(TropicalSeasonalForest const& vox);

                    //## Deconstructor ##//
                    ~TropicalSeasonalForest();

                    //## Methods ##//
                    GLint const getType() const override;
                    Color::RGB const getColor() const override;
            };

            /**
             * @class TropicalRainForest
             * @brief Voxel's Object : a grass type voxel
             */
            class TropicalRainForest : public World::Voxel {
                public:
                    //## Constructor ##//
                    TropicalRainForest();

                    //## Copy-Constructor ##//
                    TropicalRainForest(TropicalRainForest const& vox);

                    //## Deconstructor ##//
                    ~TropicalRainForest();

                    //## Methods ##//
                    GLint const getType() const override;
                    Color::RGB const getColor() const override;
            };
            
        };
    };
