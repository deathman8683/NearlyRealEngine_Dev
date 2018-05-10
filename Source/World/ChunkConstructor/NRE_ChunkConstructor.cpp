
    #include "../Chunk/NRE_Chunk.hpp"
    #include "../Mesh/NRE_Mesh.hpp"
    #include "../NRE_World.hpp"

    namespace NRE {
        namespace World {

            void Chunk::constructMesh(World* w) {
                Mesh* cMesh = new Mesh(this);

                cMesh->constructMesh(w);

                std::vector<GLvoid*> data;
                data.push_back(cMesh->getVPointer());
                data.push_back(cMesh->getMPointer());
                data.push_back(cMesh->getNPointer());
                data.push_back(cMesh->getIPointer());

                if (!getBuffer().isAllocated()) {
                    buffer.allocateAndFill(sizeof(GLint), cMesh->getVData().size() / 3, cMesh->getIData().size(), GL_STREAM_DRAW, data);
                } else {
                    std::vector<GLintptr> offset;
                    offset.push_back(0);
                    offset.push_back(0);
                    offset.push_back(0);
                    offset.push_back(0);
                    buffer.update(offset, sizeof(GLint), cMesh->getVData().size() / 3, cMesh->getIData().size(), data);
                }

                delete cMesh;
            }

            void Chunk::createProceduralTerrain(World* w) {
                model.createProceduralTerrain(w->getSoilGenerator(), w->getMoistureGenerator(), getCoord());
            }

        };
    };
