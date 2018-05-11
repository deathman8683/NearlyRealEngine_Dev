
    #include "NRE_Init.hpp"

    namespace NRE {

        void init() {
            World::VoxelTypes::init();
            Object::MergingCache::init();
            Renderer::EngineShader::init();
        }

        void quit() {
            World::VoxelTypes::free();
            Object::MergingCache::free();
            Renderer::EngineShader::free();
        }

    };
