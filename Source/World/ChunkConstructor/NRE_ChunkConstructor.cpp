
    #include "../Chunk/NRE_Chunk.hpp"
    #include "../NRE_World.hpp"

    namespace NRE {
        namespace World {

            void Chunk::createProceduralTerrain(World* w) {
                voxelSets[0].createProceduralTerrain(w->getSoilGenerator(), w->getMoistureGenerator(), getCoord());
            }

        };
    };
