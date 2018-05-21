
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

            void MaterialManager::init() {
                materials = new std::vector<Material>;
                for (GLuint i = 0; i < World::VoxelTypes::getSize(); i = i + 1) {
                    materials->push_back(World::VoxelTypes::getVoxelType(i)->getMaterial());
                }
            }

            void MaterialManager::free() {
                delete materials;
            }

            void MaterialManager::sendMaterial() {

            }

        };
    };
