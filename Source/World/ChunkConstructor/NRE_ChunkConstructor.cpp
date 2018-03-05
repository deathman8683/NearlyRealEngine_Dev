
    #include "../Chunk/NRE_Chunk.hpp"
    #include "../Mesh/NRE_Mesh.hpp"

    namespace NRE {
        namespace World {

            void Chunk::constructMesh() {
                Mesh* cMesh = new Mesh{this};

                delete cMesh;
            }

        };
    };
