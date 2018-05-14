
    #include "NRE_VoxelTypes.hpp"

    namespace NRE {
        namespace World {

            VoxelType** VoxelTypes::voxelTypes = 0;
            Renderer::Material* VoxelTypes::materialTypes = 0;
            GL::Texture2DArray* VoxelTypes::materialAlbedo = 0;
            GL::Texture2DArray* VoxelTypes::materialNormal = 0;
            GLuint VoxelTypes::size = 0;

            GLuint const& VoxelTypes::getSize() {
                return size;
            }

            VoxelType* VoxelTypes::getVoxelType(GLubyte const& type) {
                return voxelTypes[type];
            }

            Renderer::Material& VoxelTypes::getMaterial(GLubyte const& type) {
                return materialTypes[type];
            }

            GL::Texture2DArray* VoxelTypes::getMaterialAlbedo() {
                return materialAlbedo;
            }

            GL::Texture2DArray* VoxelTypes::getMaterialNormal() {
                return materialNormal;
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
                materialAlbedo = new GL::Texture2DArray(GL_RGBA, 2048, 2048, TYPE_NUM, GL_RGBA, true);
                materialNormal = new GL::Texture2DArray(GL_RGBA, 2048, 2048, TYPE_NUM, GL_RGBA, true);
                GL::Texture2D texAlbedo("Data/Material/Test_Albedo.png", false);
                GL::Texture2D texNormal("Data/Material/Test_Normal.png", false);
                for (int i = 0; i < TYPE_NUM; i = i + 1) {
                    materialTypes[i] = voxelTypes[i]->getMaterial();
                    materialAlbedo->sendTexture(texAlbedo, i);
                    materialNormal->sendTexture(texNormal, i);
                }

                size = TYPE_NUM;
            }

            void VoxelTypes::free() {
                delete[] voxelTypes;
                delete[] materialTypes;
                delete materialAlbedo;
                delete materialNormal;
            }

        };
    };
