
    #include "NRE_Init.hpp"

    namespace NRE {

        void init() {
            World::VoxelTypes::init();
            Object::MergingCache::init();
        }

        void quit() {
            World::VoxelTypes::free();
            Object::MergingCache::free();
        }
        
    };
