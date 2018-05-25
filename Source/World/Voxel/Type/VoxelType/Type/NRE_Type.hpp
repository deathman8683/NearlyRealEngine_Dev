
    /**
     * @file VoxelType/Type/NRE_Type.hpp
     * @brief Declaration of Engine's World's Object : VoxelType class
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
                         * Solid state getter
                         * @return if the voxel is solid or not
                         */
                        bool const isSolid() const;
                        /**
                         * Voxel material getter
                         * @return the voxel's material's path
                         */
                        std::string const getMaterialPath() const;
            };

            /**
             * @class Ocean
             * @brief World's Object : a ocean type voxel
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
                         * Solid state getter
                         * @return if the voxel is solid or not
                         */
                        bool const isSolid() const;
                        /**
                         * Voxel material getter
                         * @return the voxel's material's path
                         */
                        std::string const getMaterialPath() const;
            };

            /**
             * @class Beach
             * @brief World's Object : a beach type voxel
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
                         * Solid state getter
                         * @return if the voxel is solid or not
                         */
                        bool const isSolid() const;
                        /**
                         * Voxel material getter
                         * @return the voxel's material's path
                         */
                        std::string const getMaterialPath() const;
            };

            /**
             * @class Scorched
             * @brief World's Object : a scorched type voxel
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
                         * Solid state getter
                         * @return if the voxel is solid or not
                         */
                        bool const isSolid() const;
                        /**
                         * Voxel material getter
                         * @return the voxel's material's path
                         */
                        std::string const getMaterialPath() const;
            };

            /**
             * @class Bare
             * @brief World's Object : a bare type voxel
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
                         * Solid state getter
                         * @return if the voxel is solid or not
                         */
                        bool const isSolid() const;
                        /**
                         * Voxel material getter
                         * @return the voxel's material's path
                         */
                        std::string const getMaterialPath() const;
            };

            /**
             * @class Tundra
             * @brief World's Object : a tundra type voxel
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
                         * Solid state getter
                         * @return if the voxel is solid or not
                         */
                        bool const isSolid() const;
                        /**
                         * Voxel material getter
                         * @return the voxel's material's path
                         */
                        std::string const getMaterialPath() const;
            };

            /**
             * @class Snow
             * @brief World's Object : a snow type voxel
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
                         * Solid state getter
                         * @return if the voxel is solid or not
                         */
                        bool const isSolid() const;
                        /**
                         * Voxel material getter
                         * @return the voxel's material's path
                         */
                        std::string const getMaterialPath() const;
            };

            /**
             * @class TemperateDesert
             * @brief World's Object : a temperate desert type voxel
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
                         * Solid state getter
                         * @return if the voxel is solid or not
                         */
                        bool const isSolid() const;
                        /**
                         * Voxel material getter
                         * @return the voxel's material's path
                         */
                        std::string const getMaterialPath() const;
            };

            /**
             * @class SubtropicalDesert
             * @brief World's Object : a subtropical desert type voxel
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
                         * Solid state getter
                         * @return if the voxel is solid or not
                         */
                        bool const isSolid() const;
                        /**
                         * Voxel material getter
                         * @return the voxel's material's path
                         */
                        std::string const getMaterialPath() const;
            };

            /**
             * @class Shrubland
             * @brief World's Object : a shrubland type voxel
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
                         * Solid state getter
                         * @return if the voxel is solid or not
                         */
                        bool const isSolid() const;
                        /**
                         * Voxel material getter
                         * @return the voxel's material's path
                         */
                        std::string const getMaterialPath() const;
            };

            /**
             * @class Taiga
             * @brief World's Object : a taiga type voxel
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
                         * Solid state getter
                         * @return if the voxel is solid or not
                         */
                        bool const isSolid() const;
                        /**
                         * Voxel material getter
                         * @return the voxel's material's path
                         */
                        std::string const getMaterialPath() const;
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
                         * Solid state getter
                         * @return if the voxel is solid or not
                         */
                        bool const isSolid() const;
                        /**
                         * Voxel material getter
                         * @return the voxel's material's path
                         */
                        std::string const getMaterialPath() const;
            };

            /**
             * @class TemperateDeciduousForest
             * @brief World's Object : a temperate deciduous forest type voxel
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
                         * Solid state getter
                         * @return if the voxel is solid or not
                         */
                        bool const isSolid() const;
                        /**
                         * Voxel material getter
                         * @return the voxel's material's path
                         */
                        std::string const getMaterialPath() const;
            };

            /**
             * @class TemperateRainForest
             * @brief World's Object : a temperate rain forest type voxel
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
                         * Solid state getter
                         * @return if the voxel is solid or not
                         */
                        bool const isSolid() const;
                        /**
                         * Voxel material getter
                         * @return the voxel's material's path
                         */
                        std::string const getMaterialPath() const;
            };

            /**
             * @class TropicalSeasonalForest
             * @brief World's Object : a tropical seasonal forest type voxel
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
                         * Solid state getter
                         * @return if the voxel is solid or not
                         */
                        bool const isSolid() const;
                        /**
                         * Voxel material getter
                         * @return the voxel's material's path
                         */
                        std::string const getMaterialPath() const;
            };

            /**
             * @class TropicalRainForest
             * @brief World's Object : a tropical rain forest type voxel
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
                         * Solid state getter
                         * @return if the voxel is solid or not
                         */
                        bool const isSolid() const;
                        /**
                         * Voxel material getter
                         * @return the voxel's material's path
                         */
                        std::string const getMaterialPath() const;
            };

            /**
             * @class Mat_1
             * @brief World's Object : a gold type voxel
             */
            class Mat_1 : public VoxelType {
                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Mat_1();

                    //## Deconstructor ##//
                        /**
                         * Mat_1 Deconstructor
                         */
                        ~Mat_1();

                    //## Getter ##//
                        /**
                         * Solid state getter
                         * @return if the voxel is solid or not
                         */
                        bool const isSolid() const;
                        /**
                         * Voxel material getter
                         * @return the voxel's material's path
                         */
                        std::string const getMaterialPath() const;
            };

            /**
             * @class Mat_2
             * @brief World's Object : a gold type voxel
             */
            class Mat_2 : public VoxelType {
                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Mat_2();

                    //## Deconstructor ##//
                        /**
                         * Mat_2 Deconstructor
                         */
                        ~Mat_2();

                    //## Getter ##//
                        /**
                         * Solid state getter
                         * @return if the voxel is solid or not
                         */
                        bool const isSolid() const;
                        /**
                         * Voxel material getter
                         * @return the voxel's material's path
                         */
                        std::string const getMaterialPath() const;
            };

            /**
             * @class Mat_3
             * @brief World's Object : a gold type voxel
             */
            class Mat_3 : public VoxelType {
                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Mat_3();

                    //## Deconstructor ##//
                        /**
                         * Mat_3 Deconstructor
                         */
                        ~Mat_3();

                    //## Getter ##//
                        /**
                         * Solid state getter
                         * @return if the voxel is solid or not
                         */
                        bool const isSolid() const;
                        /**
                         * Voxel material getter
                         * @return the voxel's material's path
                         */
                        std::string const getMaterialPath() const;
            };

            /**
             * @class Mat_4
             * @brief World's Object : a gold type voxel
             */
            class Mat_4 : public VoxelType {
                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Mat_4();

                    //## Deconstructor ##//
                        /**
                         * Mat_4 Deconstructor
                         */
                        ~Mat_4();

                    //## Getter ##//
                        /**
                         * Solid state getter
                         * @return if the voxel is solid or not
                         */
                        bool const isSolid() const;
                        /**
                         * Voxel material getter
                         * @return the voxel's material's path
                         */
                        std::string const getMaterialPath() const;
            };

            /**
             * @class Mat_5
             * @brief World's Object : a gold type voxel
             */
            class Mat_5 : public VoxelType {
                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Mat_5();

                    //## Deconstructor ##//
                        /**
                         * Mat_5 Deconstructor
                         */
                        ~Mat_5();

                    //## Getter ##//
                        /**
                         * Solid state getter
                         * @return if the voxel is solid or not
                         */
                        bool const isSolid() const;
                        /**
                         * Voxel material getter
                         * @return the voxel's material's path
                         */
                        std::string const getMaterialPath() const;
            };

            /**
             * @class Mat_6
             * @brief World's Object : a gold type voxel
             */
            class Mat_6 : public VoxelType {
                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Mat_6();

                    //## Deconstructor ##//
                        /**
                         * Mat_6 Deconstructor
                         */
                        ~Mat_6();

                    //## Getter ##//
                        /**
                         * Solid state getter
                         * @return if the voxel is solid or not
                         */
                        bool const isSolid() const;
                        /**
                         * Voxel material getter
                         * @return the voxel's material's path
                         */
                        std::string const getMaterialPath() const;
            };

            /**
             * @class Mat_7
             * @brief World's Object : a gold type voxel
             */
            class Mat_7 : public VoxelType {
                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Mat_7();

                    //## Deconstructor ##//
                        /**
                         * Mat_7 Deconstructor
                         */
                        ~Mat_7();

                    //## Getter ##//
                        /**
                         * Solid state getter
                         * @return if the voxel is solid or not
                         */
                        bool const isSolid() const;
                        /**
                         * Voxel material getter
                         * @return the voxel's material's path
                         */
                        std::string const getMaterialPath() const;
            };

            /**
             * @class Mat_8
             * @brief World's Object : a gold type voxel
             */
            class Mat_8 : public VoxelType {
                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Mat_8();

                    //## Deconstructor ##//
                        /**
                         * Mat_8 Deconstructor
                         */
                        ~Mat_8();

                    //## Getter ##//
                        /**
                         * Solid state getter
                         * @return if the voxel is solid or not
                         */
                        bool const isSolid() const;
                        /**
                         * Voxel material getter
                         * @return the voxel's material's path
                         */
                        std::string const getMaterialPath() const;
            };

        };
    };
