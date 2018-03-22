
    #include "NRE_VoxelTypes.hpp"

    namespace NRE {
        namespace World {

            VoxelType** VoxelTypes::types = 0;

            VoxelType** VoxelTypes::getTypes() {
                if (types == 0) {
                    types = new VoxelType*[TYPE_NUM];
                    types[VOID] = new Void();
                    types[OCEAN] = new Ocean();
                    types[BEACH] = new Beach();
                    types[SCORCHED] = new Scorched();
                    types[BARE] = new Bare();
                    types[TUNDRA] = new Tundra();
                    types[SNOW] = new Snow();
                    types[TEMPERATE_DESERT] = new TemperateDesert();
                    types[SUBTROPICAL_DESERT] = new SubtropicalDesert();
                    types[SHRUBLAND] = new Shrubland();
                    types[TAIGA] = new Taiga();
                    types[GRASSLAND] = new Grassland();
                    types[TEMPERATE_DECIDUOUS_FOREST] = new TemperateDeciduousForest();
                    types[TEMPERATE_RAIN_FOREST] = new TemperateRainForest();
                    types[TROPICAL_SEASONAL_FOREST] = new TropicalSeasonalForest();
                    types[TROPICAL_RAIN_FOREST] = new TropicalRainForest();
                }

                return types;
            }

            VoxelType* VoxelTypes::getVoxelType(GLubyte const& type) {
                return getTypes()[type];
            }

            void VoxelTypes::free() {
                delete[] types;
                types = 0;
            }

        };
    };
