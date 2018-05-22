
    #include "NRE_MaterialManager.hpp"

    namespace NRE {
        namespace Renderer {

            size_t MaterialManager::RESOLUTION = 256;
            std::vector<Material*>* MaterialManager::materials = 0;
            GL::Texture2DArray* MaterialManager::materialsAlbedo = 0;
            GL::Texture2DArray* MaterialManager::materialsNormal = 0;
            GL::Texture2DArray* MaterialManager::materialsRoughness = 0;
            GL::Texture2DArray* MaterialManager::materialsMetallic = 0;

            Material& MaterialManager::getMaterial(GLuint const& index) {
                return *((*materials)[index]);
            }

            size_t const MaterialManager::getSize() {
                return materials->size();
            }

            GL::Texture2DArray& MaterialManager::getMaterialsAlbedo() {
                return *materialsAlbedo;
            }

            GL::Texture2DArray& MaterialManager::getMaterialsNormal() {
                return *materialsNormal;
            }

            GL::Texture2DArray& MaterialManager::getMaterialsRoughness() {
                return *materialsRoughness;
            }

            GL::Texture2DArray& MaterialManager::getMaterialsMetallic() {
                return *materialsMetallic;
            }

            void MaterialManager::init() {
                materials = new std::vector<Material*>();
                materialsAlbedo = new GL::Texture2DArray();
                materialsNormal = new GL::Texture2DArray();
                materialsRoughness = new GL::Texture2DArray();
                materialsMetallic = new GL::Texture2DArray();
                materialsAlbedo->allocate(GL_RGBA, RESOLUTION, RESOLUTION, World::VoxelTypes::getSize(), GL_RGBA, true);
                materialsNormal->allocate(GL_RGBA, RESOLUTION, RESOLUTION, World::VoxelTypes::getSize(), GL_RGBA, true);
                materialsRoughness->allocate(GL_RGBA, RESOLUTION, RESOLUTION, World::VoxelTypes::getSize(), GL_RGBA, true);
                materialsMetallic->allocate(GL_RGBA, RESOLUTION, RESOLUTION, World::VoxelTypes::getSize(), GL_RGBA, true);
                for (GLuint i = 0; i < World::VoxelTypes::getSize(); i = i + 1) {
                    materials->push_back(new Material(World::VoxelTypes::getVoxelType(i)->getMaterialPath()));
                    materialsAlbedo->sendTexture(getMaterial(i).getAlbedo(), i);
                    materialsNormal->sendTexture(getMaterial(i).getNormal(), i);
                    materialsRoughness->sendTexture(getMaterial(i).getRoughness(), i);
                    materialsMetallic->sendTexture(getMaterial(i).getMetallic(), i);
                    getMaterial(i).freeTextures();
                }
                materialsAlbedo->bind();
                    glGenerateMipmap(GL_TEXTURE_2D_ARRAY);
                    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
                materialsAlbedo->unbind();
                materialsNormal->bind();
                    glGenerateMipmap(GL_TEXTURE_2D_ARRAY);
                    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
                materialsNormal->unbind();
            }

            void MaterialManager::free() {
                for (GLuint i = 0; i < materials->size(); i = i + 1) {
                    delete (*materials)[i];
                }
                delete materials;
                delete materialsAlbedo;
                delete materialsNormal;
                delete materialsRoughness;
                delete materialsMetallic;
            }

        };
    };
