
    #include "NRE_VoxelTypes.hpp"

    namespace NRE {
        namespace World {

            VoxelType** VoxelTypes::voxelTypes = 0;
            Renderer::Material* VoxelTypes::materialTypes = 0;

            VoxelType** VoxelTypes::getVoxelTypes() {
                if (voxelTypes == 0) {
                    init();
                }

                return voxelTypes;
            }

            Renderer::Material* VoxelTypes::getMaterialTypes() {
                if (materialTypes == 0) {
                    init();
                }

                return materialTypes;
            }

            VoxelType* VoxelTypes::getVoxelType(GLubyte const& type) {
                return getVoxelTypes()[type];
            }

            Renderer::Material const& VoxelTypes::getMaterial(GLubyte const& type) {
                return getMaterialTypes()[type];
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

                materialTypes = new Renderer::Material[TYPE_NUM];
                for (int i = 0; i < TYPE_NUM; i = i + 1) {
                    materialTypes[i] = voxelTypes[i]->getMaterial();
                }
            }

            void VoxelTypes::free() {
                delete[] voxelTypes;
                delete[] materialTypes;
                voxelTypes = 0;
                materialTypes = 0;
            }

        };
    };
