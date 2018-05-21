
    #include "NRE_Init.hpp"

    namespace NRE {

        void init() {
            World::VoxelTypes::init();
            Renderer::MaterialManager::init();
            Object::MergingCache::init();
            Renderer::EngineShader::init();
        }

        void quit() {
            World::VoxelTypes::free();
            Renderer::MaterialManager::free();
            Object::MergingCache::free();
            Renderer::EngineShader::free();
        }

    };
