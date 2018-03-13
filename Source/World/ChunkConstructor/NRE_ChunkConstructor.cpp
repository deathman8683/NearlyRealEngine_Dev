
    #include "../Chunk/NRE_Chunk.hpp"
    #include "../Mesh/NRE_Mesh.hpp"
    #include "../NRE_World.hpp"

    namespace NRE {
        namespace World {

            void Chunk::constructMesh(World* w) {
                Mesh* cMesh = new Mesh{this};

                cMesh->constructMesh(w);

                std::vector<GLvoid*> data;
                data.push_back(cMesh->getVPointer());
                data.push_back(cMesh->getCPointer());
                data.push_back(cMesh->getNPointer());

                if (!getBuffer().isAllocated()) {
                    buffer.allocateAndFill(sizeof(GLint), cMesh->getVData().size() / 3, cMesh->getIData().size(), GL_STREAM_DRAW, data, cMesh->getIPointer());
                } else {
                    buffer.update(0, sizeof(GLint), cMesh->getVData().size() / 3, cMesh->getIData().size(), data, cMesh->getIPointer());
                }

                delete cMesh;
            }

            void Chunk::createPerlinTerrain(World* w) {
                GLint z;
                GLuint index;

                for (int x = 0; x < static_cast <int> (SIZE_X); x = x + 1) {
                    for (int y = 0; y < static_cast <int> (SIZE_Y); y = y + 1) {
                        z = static_cast <GLint> (w->getGenerator().GetNoise(x + static_cast <GLint> (SIZE_X) * getCoord().getX(), y + static_cast <GLint> (SIZE_Y) * getCoord().getY()) * static_cast <GLint> (SIZE_Z) / 2 + static_cast <GLint> (SIZE_Z) / 2);
                        if (z <= 0) {
                            z = 1;
                        }

                        for (int zPrime = 0; zPrime < z; zPrime = zPrime + 1) {
                            index = getVoxelIndex(x, y, zPrime);

                            if (z - 2 >= 0 && zPrime < z - 2) {
                                voxel[index] = new NRE::Voxel::Stone;
                            } else {
                                voxel[index] = new NRE::Voxel::Grass;
                            }
                        }

                        if (z <= 50) {
                            for (int zPrime = static_cast <int> (z); zPrime < 50; zPrime = zPrime + 1) {
                                index = getVoxelIndex(x, y, zPrime);
                                voxel[index] = new NRE::Voxel::Water;
                            }
                            for (unsigned int zPrime = 50; zPrime < SIZE_Z; zPrime = zPrime + 1) {
                                index = getVoxelIndex(x, y, zPrime);
                                voxel[index] = new NRE::Voxel::Void;
                            }
                        } else {
                            for (unsigned int zPrime = static_cast <unsigned int> (z); zPrime < SIZE_Z; zPrime = zPrime + 1) {
                                index = getVoxelIndex(x, y, zPrime);
                                voxel[index] = new NRE::Voxel::Void;
                            }
                        }
                    }
                }
            }

        };
    };
