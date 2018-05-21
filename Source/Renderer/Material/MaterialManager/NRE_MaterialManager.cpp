
    #include "NRE_MaterialManager.hpp"

    namespace NRE {
        namespace Renderer {

            std::vector<Material>* MaterialManager::materials = 0;
            GL::Texture2DArray* MaterialManager::materialsAlbedo = 0;

            Material& MaterialManager::getMaterial(GLuint const& index) {
                return (*materials)[index];
            }

            size_t const MaterialManager::getSize() {
                return materials->size();
            }

            GL::Texture2DArray& MaterialManager::getMaterialArray() {
                return *materialsAlbedo;
            }

            void MaterialManager::init() {
                materials = new std::vector<Material>;
                materialsAlbedo = new GL::Texture2DArray();
                materialsAlbedo->allocate(World::VoxelTypes::getSize(), World::VoxelTypes::getVoxelType(0)->getMaterial().getAlbedoTexture(), true);
                for (GLuint i = 0; i < World::VoxelTypes::getSize(); i = i + 1) {
                    materials->push_back(World::VoxelTypes::getVoxelType(i)->getMaterial());
                    materialsAlbedo->sendTexture(getMaterial(i).getAlbedoTexture(), i);
                    getMaterial(i).freeTextures();
                }
            }

            void MaterialManager::free() {
                delete materials;
                delete materialsAlbedo;
            }

            void MaterialManager::sendMaterial() {

            }

        };
    };
