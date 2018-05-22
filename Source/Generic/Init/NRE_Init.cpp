
    #include "NRE_Init.hpp"

    namespace NRE {

        void init() {
            World::VoxelTypes::init();
            Renderer::MaterialManager::init();
            Object::MergingCache::init();
            Renderer::EngineShader::init();
            Light::EngineLights::init();
        }

        void quit() {
            Light::EngineLights::free();
            Renderer::EngineShader::free();
            Object::MergingCache::free();
            Renderer::MaterialManager::free();
            World::VoxelTypes::free();
        }

    };
