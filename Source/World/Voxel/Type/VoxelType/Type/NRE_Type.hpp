
    /**
     * @file NRE_VoxelType.hpp
     * @brief Declaration of Engine's World's Object : VoxelType
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_VoxelType.hpp"
    #include "NRE_VoxelEnum.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace World
         * @brief Engine's World's Module
         */
        namespace World {

            /**
             * @class Void
             * @brief World's Object : a void type voxel
             */
            class Void : public VoxelType {
                public:
                    //## Constructor ##//
                    Void();

                    //## Deconstructor ##//
                    virtual ~Void();

                    //## Getter ##//
                    Color::RGB const getColor() const;
                    bool const isSolid() const;
                    Renderer::Material const getMaterial() const;
            };

            /**
             * @class Ocean
             * @brief World's Object : a grass type voxel
             */
            class Ocean : public VoxelType {
                public:
                    //## Constructor ##//
                    Ocean();

                    //## Deconstructor ##//
                    virtual ~Ocean();

                    //## Getter ##//
                    Color::RGB const getColor() const;
                    bool const isSolid() const;
                    Renderer::Material const getMaterial() const;
            };

            /**
             * @class Beach
             * @brief World's Object : a grass type voxel
             */
            class Beach : public VoxelType {
                public:
                    //## Constructor ##//
                    Beach();

                    //## Deconstructor ##//
                    virtual ~Beach();

                    //## Getter ##//
                    Color::RGB const getColor() const;
                    bool const isSolid() const;
                    Renderer::Material const getMaterial() const;
            };

            /**
             * @class Scorched
             * @brief World's Object : a grass type voxel
             */
            class Scorched : public VoxelType {
                public:
                    //## Constructor ##//
                    Scorched();

                    //## Deconstructor ##//
                    virtual ~Scorched();

                    //## Getter ##//
                    Color::RGB const getColor() const;
                    bool const isSolid() const;
                    Renderer::Material const getMaterial() const;
            };

            /**
             * @class Bare
             * @brief World's Object : a grass type voxel
             */
            class Bare : public VoxelType {
                public:
                    //## Constructor ##//
                    Bare();

                    //## Deconstructor ##//
                    virtual ~Bare();

                    //## Getter ##//
                    Color::RGB const getColor() const;
                    bool const isSolid() const;
                    Renderer::Material const getMaterial() const;
            };

            /**
             * @class Tundra
             * @brief World's Object : a grass type voxel
             */
            class Tundra : public VoxelType {
                public:
                    //## Constructor ##//
                    Tundra();

                    //## Deconstructor ##//
                    virtual ~Tundra();

                    //## Getter ##//
                    Color::RGB const getColor() const;
                    bool const isSolid() const;
                    Renderer::Material const getMaterial() const;
            };

            /**
             * @class Snow
             * @brief World's Object : a grass type voxel
             */
            class Snow : public VoxelType {
                public:
                    //## Constructor ##//
                    Snow();

                    //## Deconstructor ##//
                    virtual ~Snow();

                    //## Getter ##//
                    Color::RGB const getColor() const;
                    bool const isSolid() const;
                    Renderer::Material const getMaterial() const;
            };

            /**
             * @class TemperateDesert
             * @brief World's Object : a grass type voxel
             */
            class TemperateDesert : public VoxelType {
                public:
                    //## Constructor ##//
                    TemperateDesert();

                    //## Deconstructor ##//
                    virtual ~TemperateDesert();

                    //## Getter ##//
                    Color::RGB const getColor() const;
                    bool const isSolid() const;
                    Renderer::Material const getMaterial() const;
            };

            /**
             * @class SubtropicalDesert
             * @brief World's Object : a grass type voxel
             */
            class SubtropicalDesert : public VoxelType {
                public:
                    //## Constructor ##//
                    SubtropicalDesert();

                    //## Deconstructor ##//
                    virtual ~SubtropicalDesert();

                    //## Getter ##//
                    Color::RGB const getColor() const;
                    bool const isSolid() const;
                    Renderer::Material const getMaterial() const;
            };

            /**
             * @class Shrubland
             * @brief World's Object : a grass type voxel
             */
            class Shrubland : public VoxelType {
                public:
                    //## Constructor ##//
                    Shrubland();

                    //## Deconstructor ##//
                    virtual ~Shrubland();

                    //## Getter ##//
                    Color::RGB const getColor() const;
                    bool const isSolid() const;
                    Renderer::Material const getMaterial() const;
            };

            /**
             * @class Taiga
             * @brief World's Object : a grass type voxel
             */
            class Taiga : public VoxelType {
                public:
                    //## Constructor ##//
                    Taiga();

                    //## Deconstructor ##//
                    virtual ~Taiga();

                    //## Getter ##//
                    Color::RGB const getColor() const;
                    bool const isSolid() const;
                    Renderer::Material const getMaterial() const;
            };

            /**
             * @class Grassland
             * @brief World's Object : a grass type voxel
             */
            class Grassland : public VoxelType {
                public:
                    //## Constructor ##//
                    Grassland();

                    //## Deconstructor ##//
                    virtual ~Grassland();

                    //## Getter ##//
                    Color::RGB const getColor() const;
                    bool const isSolid() const;
                    Renderer::Material const getMaterial() const;
            };

            /**
             * @class TemperateDeciduousForest
             * @brief World's Object : a grass type voxel
             */
            class TemperateDeciduousForest : public VoxelType {
                public:
                    //## Constructor ##//
                    TemperateDeciduousForest();

                    //## Deconstructor ##//
                    virtual ~TemperateDeciduousForest();

                    //## Getter ##//
                    Color::RGB const getColor() const;
                    bool const isSolid() const;
                    Renderer::Material const getMaterial() const;
            };

            /**
             * @class TemperateRainForest
             * @brief World's Object : a grass type voxel
             */
            class TemperateRainForest : public VoxelType {
                public:
                    //## Constructor ##//
                    TemperateRainForest();

                    //## Deconstructor ##//
                    virtual ~TemperateRainForest();

                    //## Getter ##//
                    Color::RGB const getColor() const;
                    bool const isSolid() const;
                    Renderer::Material const getMaterial() const;
            };

            /**
             * @class TropicalSeasonalForest
             * @brief World's Object : a grass type voxel
             */
            class TropicalSeasonalForest : public VoxelType {
                public:
                    //## Constructor ##//
                    TropicalSeasonalForest();

                    //## Deconstructor ##//
                    virtual ~TropicalSeasonalForest();

                    //## Getter ##//
                    Color::RGB const getColor() const;
                    bool const isSolid() const;
                    Renderer::Material const getMaterial() const;
            };

            /**
             * @class TropicalRainForest
             * @brief World's Object : a grass type voxel
             */
            class TropicalRainForest : public VoxelType {
                public:
                    //## Constructor ##//
                    TropicalRainForest();

                    //## Deconstructor ##//
                    virtual ~TropicalRainForest();

                    //## Getter ##//
                    Color::RGB const getColor() const;
                    bool const isSolid() const;
                    Renderer::Material const getMaterial() const;
            };

        };
    };
