
    #include "NRE_VoxelTypes.hpp"

    namespace NRE {
        namespace World {

            VoxelType** VoxelTypes::voxelTypes = 0;

            GLuint const VoxelTypes::getSize() {
                return TYPE_NUM;
            }

            VoxelType* VoxelTypes::getVoxelType(GLubyte const& type) {
                return voxelTypes[type];
            }

            void VoxelTypes::init() {
                voxelTypes = new VoxelType*[TYPE_NUM];
                voxelTypes[VOID] = new Void();
                voxelTypes[OCEAN] = new Ocean();
                voxelTypes[BEACH] = new Beach();
                voxelTypes[SCORCHED] = new Scorched();
                voxelTypes[BARE] = new Bare();
                voxelTypes[TUNDRA] = new Tundra();
                voxelTypes[SNOW] = new Snow();
                voxelTypes[TEMPERATE_DESERT] = new TemperateDesert();
                voxelTypes[SUBTROPICAL_DESERT] = new SubtropicalDesert();
                voxelTypes[SHRUBLAND] = new Shrubland();
                voxelTypes[TAIGA] = new Taiga();
                voxelTypes[GRASSLAND] = new Grassland();
                voxelTypes[TEMPERATE_DECIDUOUS_FOREST] = new TemperateDeciduousForest();
                voxelTypes[TEMPERATE_RAIN_FOREST] = new TemperateRainForest();
                voxelTypes[TROPICAL_SEASONAL_FOREST] = new TropicalSeasonalForest();
                voxelTypes[TROPICAL_RAIN_FOREST] = new TropicalRainForest();
                voxelTypes[MAT_1] = new Mat_1();
                voxelTypes[MAT_2] = new Mat_2();
                voxelTypes[MAT_3] = new Mat_3();
                voxelTypes[MAT_4] = new Mat_4();
                voxelTypes[MAT_5] = new Mat_5();
                voxelTypes[MAT_6] = new Mat_6();
                voxelTypes[MAT_7] = new Mat_7();
                voxelTypes[MAT_8] = new Mat_8();
            }

            void VoxelTypes::free() {
                delete[] voxelTypes;
            }

        };
    };
