
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
                        NREfloat nx = x + static_cast <int> (SIZE_X) * getCoord().getX();
                        NREfloat ny = y + static_cast <int> (SIZE_Y) * getCoord().getY();
                        NREfloat bias = static_cast <int> (SIZE_Z);
                        NREfloat noise = w->getGenerator().GetNoise(nx, ny)
                        +  0.5 * w->getGenerator().GetNoise(2 * nx, 2 * ny);
                        noise = (noise + 1.0) / 2.0;
                        NREfloat moisture =  w->getGenerator().GetNoise(nx, ny)
                            +  0.5 * w->getGenerator().GetNoise(2 * nx, 2 * ny)
                           +  0.25 * w->getGenerator().GetNoise(4 * nx, 4 * ny)
                          +  0.125 * w->getGenerator().GetNoise(8 * nx, 8 * ny)
                          +  0.1 * w->getGenerator().GetNoise(10 * nx, 10 * ny);
                        moisture = (moisture + 1.0) / 2.0;
                        NREfloat redistributedNoise = std::pow(noise, 1.85);
                        z = static_cast <GLint> (redistributedNoise * bias);
                        if (z <= 0) {
                            z = 1;
                        }
                        if (z > 128) {
                            z = 128;
                        }

                        for (int zPrime = 0; zPrime < z; zPrime = zPrime + 1) {
                            index = getVoxelIndex(x, y, zPrime);

                            if (redistributedNoise < 0.12) {
                                voxel[index] = new NRE::Voxel::Ocean;
                            } else if (redistributedNoise < 0.14) {
                                voxel[index] = new NRE::Voxel::Beach;
                            } else if (redistributedNoise < 0.3) {
                                if (moisture < 0.16) {
                                    voxel[index] = new NRE::Voxel::SubtropicalDesert;
                                } else if (moisture < 0.33) {
                                    voxel[index] = new NRE::Voxel::Grassland;
                                } else if (moisture < 0.66) {
                                    voxel[index] = new NRE::Voxel::TropicalSeasonalForest;
                                } else {
                                    voxel[index] = new NRE::Voxel::TropicalRainForest;
                                }
                            } else if (redistributedNoise < 0.6) {
                                if (moisture < 0.16) {
                                    voxel[index] = new NRE::Voxel::TemperateDesert;
                                } else if (moisture < 0.5) {
                                    voxel[index] = new NRE::Voxel::Grassland;
                                } else if (moisture < 0.83) {
                                    voxel[index] = new NRE::Voxel::TemperateDeciduousForest;
                                } else {
                                    voxel[index] = new NRE::Voxel::TemperateRainForest;
                                }
                            } else if (redistributedNoise < 0.8) {
                                if (moisture < 0.33) {
                                    voxel[index] = new NRE::Voxel::TemperateDesert;
                                } else if (moisture < 0.66) {
                                    voxel[index] = new NRE::Voxel::Shrubland;
                                } else {
                                    voxel[index] = new NRE::Voxel::Taiga;
                                }
                            } else {
                                if (moisture < 0.1) {
                                    voxel[index] = new NRE::Voxel::Scorched;
                                } else if (moisture < 0.2) {
                                    voxel[index] = new NRE::Voxel::Bare;
                                } else if (moisture < 0.5) {
                                    voxel[index] = new NRE::Voxel::Tundra;
                                } else {
                                    voxel[index] = new NRE::Voxel::Snow;
                                }
                            }
                        }

                        if (redistributedNoise < 0.12) {
                            for (int zPrime = static_cast <int> (z); zPrime < 15; zPrime = zPrime + 1) {
                                index = getVoxelIndex(x, y, zPrime);
                                voxel[index] = new NRE::Voxel::Ocean;
                            }
                            for (unsigned int zPrime = 15; zPrime < SIZE_Z; zPrime = zPrime + 1) {
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
