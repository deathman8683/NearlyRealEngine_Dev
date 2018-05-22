
    #include "NRE_Init.hpp"

    namespace NRE {

        void init() {
            World::VoxelTypes::init();
            Renderer::MaterialsManager::init();
            Object::MergingCache::init();
            Renderer::ShadersManager::init();
            Light::LightsManager::init();
        }

        void quit() {
            Light::LightsManager::free();
            Renderer::ShadersManager::free();
            Object::MergingCache::free();
            Renderer::MaterialsManager::free();
            World::VoxelTypes::free();
        }

    };
