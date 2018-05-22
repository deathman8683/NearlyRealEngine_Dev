
    #include "NRE_MaterialManager.hpp"

    namespace NRE {
        namespace Renderer {

            size_t MaterialManager::RESOLUTION = 256;
            std::vector<Material>* MaterialManager::materials = 0;
            GL::Texture2DArray* MaterialManager::materialsAlbedo = 0;
            GL::Texture2DArray* MaterialManager::materialsNormal = 0;

            Material& MaterialManager::getMaterial(GLuint const& index) {
                return (*materials)[index];
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

            void MaterialManager::init() {
                materials = new std::vector<Material>;
                materialsAlbedo = new GL::Texture2DArray();
                materialsNormal = new GL::Texture2DArray();
                materialsAlbedo->allocate(GL_RGBA, RESOLUTION, RESOLUTION, World::VoxelTypes::getSize(), GL_RGBA, true);
                materialsNormal->allocate(GL_RGBA, RESOLUTION, RESOLUTION, World::VoxelTypes::getSize(), GL_RGBA, true);
                for (GLuint i = 0; i < World::VoxelTypes::getSize(); i = i + 1) {
                    materials->push_back(World::VoxelTypes::getVoxelType(i)->getMaterial());
                    materialsAlbedo->sendTexture(getMaterial(i).getAlbedo(), i);
                    materialsNormal->sendTexture(getMaterial(i).getNormal(), i);
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
                delete materials;
                delete materialsAlbedo;
                delete materialsNormal;
            }

        };
    };
