
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
                        /**
                         * Default Constructor
                         */
                        Void();

                    //## Deconstructor ##//
                        /**
                         * Void Deconstructor
                         */
                        ~Void();

                    //## Getter ##//
                        /**
                         * Voxel color getter
                         * @return the color of the voxel
                         */
                        Color::RGB const getColor() const;
                        /**
                         * Solid state getter
                         * @return if the voxel is solid or not
                         */
                        bool const isSolid() const;
                        /**
                         * Voxel material getter
                         * @return the voxel's material
                         */
                        Renderer::Material const getMaterial() const;
            };

            /**
             * @class Ocean
             * @brief World's Object : a grass type voxel
             */
            class Ocean : public VoxelType {
                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                         Ocean();

                    //## Deconstructor ##//
                        /**
                         * Ocean Deconstructor
                         */
                        ~Ocean();

                    //## Getter ##//
                        /**
                         * Voxel color getter
                         * @return the color of the voxel
                         */
                        Color::RGB const getColor() const;
                        /**
                         * Solid state getter
                         * @return if the voxel is solid or not
                         */
                        bool const isSolid() const;
                        /**
                         * Voxel material getter
                         * @return the voxel's material
                         */
                        Renderer::Material const getMaterial() const;
            };

            /**
             * @class Beach
             * @brief World's Object : a grass type voxel
             */
            class Beach : public VoxelType {
                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Beach();

                    //## Deconstructor ##//
                        /**
                         * Beach Deconstructor
                         */
                        ~Beach();

                    //## Getter ##//
                        /**
                         * Voxel color getter
                         * @return the color of the voxel
                         */
                        Color::RGB const getColor() const;
                        /**
                         * Solid state getter
                         * @return if the voxel is solid or not
                         */
                        bool const isSolid() const;
                        /**
                         * Voxel material getter
                         * @return the voxel's material
                         */
                        Renderer::Material const getMaterial() const;
            };

            /**
             * @class Scorched
             * @brief World's Object : a grass type voxel
             */
            class Scorched : public VoxelType {
                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Scorched();

                    //## Deconstructor ##//
                        /**
                         * Scorched Deconstructor
                         */
                        ~Scorched();

                    //## Getter ##//
                        /**
                         * Voxel color getter
                         * @return the color of the voxel
                         */
                        Color::RGB const getColor() const;
                        /**
                         * Solid state getter
                         * @return if the voxel is solid or not
                         */
                        bool const isSolid() const;
                        /**
                         * Voxel material getter
                         * @return the voxel's material
                         */
                        Renderer::Material const getMaterial() const;
            };

            /**
             * @class Bare
             * @brief World's Object : a grass type voxel
             */
            class Bare : public VoxelType {
                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Bare();

                    //## Deconstructor ##//
                        /**
                         * Bare Deconstructor
                         */
                        ~Bare();

                    //## Getter ##//
                        /**
                         * Voxel color getter
                         * @return the color of the voxel
                         */
                        Color::RGB const getColor() const;
                        /**
                         * Solid state getter
                         * @return if the voxel is solid or not
                         */
                        bool const isSolid() const;
                        /**
                         * Voxel material getter
                         * @return the voxel's material
                         */
                        Renderer::Material const getMaterial() const;
            };

            /**
             * @class Tundra
             * @brief World's Object : a grass type voxel
             */
            class Tundra : public VoxelType {
                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Tundra();

                    //## Deconstructor ##//
                        /**
                         * Tundra Deconstructor
                         */
                        ~Tundra();

                    //## Getter ##//
                        /**
                         * Voxel color getter
                         * @return the color of the voxel
                         */
                        Color::RGB const getColor() const;
                        /**
                         * Solid state getter
                         * @return if the voxel is solid or not
                         */
                        bool const isSolid() const;
                        /**
                         * Voxel material getter
                         * @return the voxel's material
                         */
                        Renderer::Material const getMaterial() const;
            };

            /**
             * @class Snow
             * @brief World's Object : a grass type voxel
             */
            class Snow : public VoxelType {
                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Snow();

                    //## Deconstructor ##//
                        /**
                         * Snow Deconstructor
                         */
                        ~Snow();

                    //## Getter ##//
                        /**
                         * Voxel color getter
                         * @return the color of the voxel
                         */
                        Color::RGB const getColor() const;
                        /**
                         * Solid state getter
                         * @return if the voxel is solid or not
                         */
                        bool const isSolid() const;
                        /**
                         * Voxel material getter
                         * @return the voxel's material
                         */
                        Renderer::Material const getMaterial() const;
            };

            /**
             * @class TemperateDesert
             * @brief World's Object : a grass type voxel
             */
            class TemperateDesert : public VoxelType {
                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        TemperateDesert();

                    //## Deconstructor ##//
                        /**
                         * TemperateDesert Deconstructor
                         */
                        ~TemperateDesert();

                    //## Getter ##//
                        /**
                         * Voxel color getter
                         * @return the color of the voxel
                         */
                        Color::RGB const getColor() const;
                        /**
                         * Solid state getter
                         * @return if the voxel is solid or not
                         */
                        bool const isSolid() const;
                        /**
                         * Voxel material getter
                         * @return the voxel's material
                         */
                        Renderer::Material const getMaterial() const;
            };

            /**
             * @class SubtropicalDesert
             * @brief World's Object : a grass type voxel
             */
            class SubtropicalDesert : public VoxelType {
                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        SubtropicalDesert();

                    //## Deconstructor ##//
                        /**
                         * SubtropicalDesert Deconstructor
                         */
                        ~SubtropicalDesert();

                    //## Getter ##//
                        /**
                         * Voxel color getter
                         * @return the color of the voxel
                         */
                        Color::RGB const getColor() const;
                        /**
                         * Solid state getter
                         * @return if the voxel is solid or not
                         */
                        bool const isSolid() const;
                        /**
                         * Voxel material getter
                         * @return the voxel's material
                         */
                        Renderer::Material const getMaterial() const;
            };

            /**
             * @class Shrubland
             * @brief World's Object : a grass type voxel
             */
            class Shrubland : public VoxelType {
                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Shrubland();

                    //## Deconstructor ##//
                        /**
                         * Shrubland Deconstructor
                         */
                        ~Shrubland();

                    //## Getter ##//
                        /**
                         * Voxel color getter
                         * @return the color of the voxel
                         */
                        Color::RGB const getColor() const;
                        /**
                         * Solid state getter
                         * @return if the voxel is solid or not
                         */
                        bool const isSolid() const;
                        /**
                         * Voxel material getter
                         * @return the voxel's material
                         */
                        Renderer::Material const getMaterial() const;
            };

            /**
             * @class Taiga
             * @brief World's Object : a grass type voxel
             */
            class Taiga : public VoxelType {
                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Taiga();

                    //## Deconstructor ##//
                        /**
                         * Taiga Deconstructor
                         */
                        ~Taiga();

                    //## Getter ##//
                        /**
                         * Voxel color getter
                         * @return the color of the voxel
                         */
                        Color::RGB const getColor() const;
                        /**
                         * Solid state getter
                         * @return if the voxel is solid or not
                         */
                        bool const isSolid() const;
                        /**
                         * Voxel material getter
                         * @return the voxel's material
                         */
                        Renderer::Material const getMaterial() const;
            };

            /**
             * @class Grassland
             * @brief World's Object : a grass type voxel
             */
            class Grassland : public VoxelType {
                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Grassland();

                    //## Deconstructor ##//
                        /**
                         * Grassland Deconstructor
                         */
                        ~Grassland();

                    //## Getter ##//
                        /**
                         * Voxel color getter
                         * @return the color of the voxel
                         */
                        Color::RGB const getColor() const;
                        /**
                         * Solid state getter
                         * @return if the voxel is solid or not
                         */
                        bool const isSolid() const;
                        /**
                         * Voxel material getter
                         * @return the voxel's material
                         */
                        Renderer::Material const getMaterial() const;
            };

            /**
             * @class TemperateDeciduousForest
             * @brief World's Object : a grass type voxel
             */
            class TemperateDeciduousForest : public VoxelType {
                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        TemperateDeciduousForest();

                    //## Deconstructor ##//
                        /**
                         * TemperateDeciduousForest Deconstructor
                         */
                        ~TemperateDeciduousForest();

                    //## Getter ##//
                        /**
                         * Voxel color getter
                         * @return the color of the voxel
                         */
                        Color::RGB const getColor() const;
                        /**
                         * Solid state getter
                         * @return if the voxel is solid or not
                         */
                        bool const isSolid() const;
                        /**
                         * Voxel material getter
                         * @return the voxel's material
                         */
                        Renderer::Material const getMaterial() const;
            };

            /**
             * @class TemperateRainForest
             * @brief World's Object : a grass type voxel
             */
            class TemperateRainForest : public VoxelType {
                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        TemperateRainForest();

                    //## Deconstructor ##//
                        /**
                         * TemperateRainForest Deconstructor
                         */
                        ~TemperateRainForest();

                    //## Getter ##//
                        /**
                         * Voxel color getter
                         * @return the color of the voxel
                         */
                        Color::RGB const getColor() const;
                        /**
                         * Solid state getter
                         * @return if the voxel is solid or not
                         */
                        bool const isSolid() const;
                        /**
                         * Voxel material getter
                         * @return the voxel's material
                         */
                        Renderer::Material const getMaterial() const;
            };

            /**
             * @class TropicalSeasonalForest
             * @brief World's Object : a grass type voxel
             */
            class TropicalSeasonalForest : public VoxelType {
                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        TropicalSeasonalForest();

                    //## Deconstructor ##//
                        /**
                         * TropicalSeasonalForest Deconstructor
                         */
                        ~TropicalSeasonalForest();

                    //## Getter ##//
                        /**
                         * Voxel color getter
                         * @return the color of the voxel
                         */
                        Color::RGB const getColor() const;
                        /**
                         * Solid state getter
                         * @return if the voxel is solid or not
                         */
                        bool const isSolid() const;
                        /**
                         * Voxel material getter
                         * @return the voxel's material
                         */
                        Renderer::Material const getMaterial() const;
            };

            /**
             * @class TropicalRainForest
             * @brief World's Object : a grass type voxel
             */
            class TropicalRainForest : public VoxelType {
                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        TropicalRainForest();

                    //## Deconstructor ##//
                        /**
                         * TropicalRainForest Deconstructor
                         */
                        ~TropicalRainForest();

                    //## Getter ##//
                        /**
                         * Voxel color getter
                         * @return the color of the voxel
                         */
                        Color::RGB const getColor() const;
                        /**
                         * Solid state getter
                         * @return if the voxel is solid or not
                         */
                        bool const isSolid() const;
                        /**
                         * Voxel material getter
                         * @return the voxel's material
                         */
                        Renderer::Material const getMaterial() const;
            };

        };
    };
