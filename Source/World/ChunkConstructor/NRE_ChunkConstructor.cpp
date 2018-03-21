
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
                        NREfloat noise = (1.00 * w->getSoilNoise( 1 * nx,  1 * ny)
                                        + 0.50 * w->getSoilNoise( 2 * nx,  2 * ny)
                                        + 0.25 * w->getSoilNoise( 4 * nx,  4 * ny)
                                        + 0.06 * w->getSoilNoise( 8 * nx,  8 * ny)
                                        + 0.06 * w->getSoilNoise(16 * nx, 16 * ny)
                                        + 0.02 * w->getSoilNoise(32 * nx, 32 * ny));
                        noise = noise / (1.00 + 0.50 + 0.25 + 0.06 + 0.06 + 0.02);
                        noise = std::pow(noise, 1.0 - (w->getSoilGenerator().GetNoise(nx, ny)));
                        NREfloat moisture = (1.00 * w->getMoistureNoise( 1 * nx,  1 * ny)
                                           + 0.75 * w->getMoistureNoise( 2 * nx,  2 * ny)
                                           + 0.33 * w->getMoistureNoise( 4 * nx,  4 * ny)
                                           + 0.33 * w->getMoistureNoise( 8 * nx,  8 * ny)
                                           + 0.33 * w->getMoistureNoise(16 * nx, 16 * ny)
                                           + 0.50 * w->getMoistureNoise(32 * nx, 32 * ny));
                        moisture = moisture / (1.00 + 0.75 + 0.33 + 0.33 + 0.33 + 0.50);
                        z = static_cast <GLint> (noise * bias);
                        if (z <= 0) {
                            z = 1;
                        }
                        if (z > static_cast <int> (SIZE_Z)) {
                            z = static_cast <int> (SIZE_Z);
                        }

                        for (int zPrime = 0; zPrime < z; zPrime = zPrime + 1) {
                            index = getVoxelIndex(x, y, zPrime);

                            if (noise < 0.22) {
                                voxel[index] = new NRE::Voxel::Ocean;
                            } else if (noise < 0.24) {
                                voxel[index] = new NRE::Voxel::Beach;
                            } else if (noise < 0.4) {
                                if (moisture < 0.16) {
                                    voxel[index] = new NRE::Voxel::SubtropicalDesert;
                                } else if (moisture < 0.33) {
                                    voxel[index] = new NRE::Voxel::Grassland;
                                } else if (moisture < 0.66) {
                                    voxel[index] = new NRE::Voxel::TropicalSeasonalForest;
                                } else {
                                    voxel[index] = new NRE::Voxel::TropicalRainForest;
                                }
                            } else if (noise < 0.6) {
                                if (moisture < 0.16) {
                                    voxel[index] = new NRE::Voxel::TemperateDesert;
                                } else if (moisture < 0.5) {
                                    voxel[index] = new NRE::Voxel::Grassland;
                                } else if (moisture < 0.83) {
                                    voxel[index] = new NRE::Voxel::TemperateDeciduousForest;
                                } else {
                                    voxel[index] = new NRE::Voxel::TemperateRainForest;
                                }
                            } else if (noise < 0.8) {
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

                        if (noise < 0.22) {
                            for (int zPrime = static_cast <int> (z); zPrime < 0.22 * SIZE_Z; zPrime = zPrime + 1) {
                                index = getVoxelIndex(x, y, zPrime);
                                voxel[index] = new NRE::Voxel::Ocean;
                            }
                            for (unsigned int zPrime = 0.22 * SIZE_Z; zPrime < SIZE_Z; zPrime = zPrime + 1) {
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
