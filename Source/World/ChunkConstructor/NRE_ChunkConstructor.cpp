
    #include "../Chunk/NRE_Chunk.hpp"
    #include "../Mesh/NRE_Mesh.hpp"

    namespace NRE {
        namespace World {

            void Chunk::constructMesh(World* w) {
                Mesh* cMesh = new Mesh{this};

                cMesh->constructMesh(w);

                if (!getBuffer().isAllocated()) {
                    buffer.allocateAndFill(sizeof(GLint), cMesh->getVData().size() / 3, cMesh->getIData().size(), GL_STREAM_DRAW, cMesh->getVPointer(), cMesh->getCPointer(), cMesh->getNPointer(), cMesh->getIPointer());
                } else {
                    buffer.update(0, sizeof(GLint), cMesh->getVData().size() / 3, cMesh->getIData().size(), cMesh->getVPointer(), cMesh->getCPointer(), cMesh->getNPointer(), cMesh->getIPointer());
                }

                delete cMesh;
            }

        };
    };
