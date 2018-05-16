
    #include "NRE_Model.hpp"

    namespace NRE {
        namespace Object {

            Model::Model() {
            }

            Model::Model(Maths::Vector3D<GLuint> const& size) : size(size), maxSolidHeight(0) {
                voxels = new World::Voxel[size.getX() * size.getY() * size.getZ()];
            }

            Model::Model(Model const& m) : voxels(m.voxels), size(m.size), maxSolidHeight(m.maxSolidHeight) {
            }

            Model::Model(Model && m) : voxels(std::move(m.voxels)), size(std::move(m.size)), maxSolidHeight(std::move(m.maxSolidHeight)) {
            }

            Model::~Model() {
                delete[] voxels;
            }

            World::Voxel const& Model::getVoxel(Maths::Point3D<GLuint> const& p) const {
                return getVoxel(p.getX(), p.getY(), p.getZ());
            }

            World::Voxel const& Model::getVoxel(GLuint const& x, GLuint const& y, GLuint const& z) const {
                return voxels[getVoxelIndex(x, y, z)];
            }

            World::Voxel const& Model::getVoxel(GLuint const& index) const {
                return voxels[index];
            }

            GLuint const Model::getVoxelIndex(GLuint const& x, GLuint const& y, GLuint const& z) const {
                return Array::get1DIndexFrom3D(x, y, z, size);
            }

            Maths::Vector3D<GLuint> const& Model::getSize() const {
                return size;
            }

            GLuint const& Model::getMaxSolidHeight() const {
                return maxSolidHeight;
            }

            void Model::setMaxSolidHeight(GLuint const& height) {
                maxSolidHeight = height;
            }

            void Model::setType(Maths::Point3D<GLuint> const& p, GLubyte const& type) {
                voxels[getVoxelIndex(p.getX(), p.getY(), p.getZ())].setType(type);
            }

            void Model::save(std::string const& path) const {
                std::fstream modelFile;
                modelFile.open(path, std::ios::trunc | std::ios::out | std::ios::binary);
                if (!modelFile.is_open()) {
                    throw (Exception::IOException("Model File could not be open : " + path));
                }
                std::stringstream data;
                writeCompressedData(data);
                modelFile << data.rdbuf();
                modelFile.close();
            }

            void Model::load(std::string const& path) {
                std::fstream modelFile;
                modelFile.open(path, std::ios::in | std::ios::binary | std::ios_base::ate);
                if (!modelFile.is_open()) {
                    throw (Exception::IOException("Model File could not be open : " + path));
                }

                GLuint dataSize = modelFile.tellg();
                modelFile.seekg(0, modelFile.beg);

                GLuint voxNumber, x = 0, y = 0, z = 0;
                GLubyte voxType;
                while (dataSize > 0) {
                    modelFile.read(reinterpret_cast<char*> (&voxNumber), 2);
                    modelFile.read(reinterpret_cast<char*> (&voxType), 1);
                    dataSize = dataSize - 3;

                    loadVoxels(x, y, z, voxNumber, voxType);
                }
            }

            void Model::loadVoxels(GLuint &x, GLuint &y, GLuint &z, GLuint const& nb, GLubyte const& type) {
                GLuint index, n = nb;
                while (n != 0) {
                    index = getVoxelIndex(x, y, z);
                    voxels[index].setType(type);
                    x = x + 1;
                    if (x == size.getX()) {
                        x = 0;
                        y = y + 1;
                        if (y == size.getY()) {
                            y = 0;
                            z = z + 1;
                        }
                    }
                    n = n - 1;
                }
                if (type != World::VOID) {
                    if (getMaxSolidHeight() < z) {
                        setMaxSolidHeight(z);
                    }
                }
            }

            void Model::createProceduralTerrain(FastNoise const& soilGenerator, FastNoise const& moistureGenerator, Maths::Point2D<GLint> const& coord) {
                GLint z;
                GLuint index;

                for (int x = 0; x < static_cast <int> (size.getX()); x = x + 1) {
                    for (int y = 0; y < static_cast <int> (size.getY()); y = y + 1) {
                        NREfloat nx = x + static_cast <int> (size.getX()) * coord.getX();
                        NREfloat ny = y + static_cast <int> (size.getY()) * coord.getY();
                        NREfloat bias = static_cast <int> (size.getZ());
                        NREfloat noise = (1.00 * ((soilGenerator.GetNoise( 1 * nx,  1 * ny) + 1.0) / 2.0)
                                        + 0.50 * ((soilGenerator.GetNoise( 2 * nx,  2 * ny) + 1.0) / 2.0)
                                        + 0.25 * ((soilGenerator.GetNoise( 4 * nx,  4 * ny) + 1.0) / 2.0)
                                        + 0.06 * ((soilGenerator.GetNoise( 8 * nx,  8 * ny) + 1.0) / 2.0)
                                        + 0.06 * ((soilGenerator.GetNoise(16 * nx, 16 * ny) + 1.0) / 2.0)
                                        + 0.02 * ((soilGenerator.GetNoise(32 * nx, 32 * ny) + 1.0) / 2.0));
                        noise = noise / (1.00 + 0.50 + 0.25 + 0.06 + 0.06 + 0.02);
                        noise = std::pow(noise, 1.0 - soilGenerator.GetNoise(nx, ny));
                        NREfloat moisture = (1.00 * ((moistureGenerator.GetNoise( 1 * nx,  1 * ny) + 1.0) / 2.0)
                                           + 0.75 * ((moistureGenerator.GetNoise( 2 * nx,  2 * ny) + 1.0) / 2.0)
                                           + 0.33 * ((moistureGenerator.GetNoise( 4 * nx,  4 * ny) + 1.0) / 2.0)
                                           + 0.33 * ((moistureGenerator.GetNoise( 8 * nx,  8 * ny) + 1.0) / 2.0)
                                           + 0.33 * ((moistureGenerator.GetNoise(16 * nx, 16 * ny) + 1.0) / 2.0)
                                           + 0.50 * ((moistureGenerator.GetNoise(32 * nx, 32 * ny) + 1.0) / 2.0));
                        moisture = moisture / (1.00 + 0.75 + 0.33 + 0.33 + 0.33 + 0.50);
                        z = static_cast <GLint> (noise * bias);
                        if (z <= 0) {
                            z = 1;
                        }
                        if (z > static_cast <int> (size.getZ())) {
                            z = static_cast <int> (size.getZ());
                        }

                        for (int zPrime = 0; zPrime < z; zPrime = zPrime + 1) {
                            index = getVoxelIndex(x, y, zPrime);

                            if (z - 4 >= 0 && zPrime >= z - 4) {
                                if (noise < 0.22) {
                                    voxels[index].setType(World::OCEAN);
                                } else if (noise < 0.24) {
                                    voxels[index].setType(World::BEACH);
                                } else if (noise < 0.4) {
                                    if (moisture < 0.16) {
                                        voxels[index].setType(World::SUBTROPICAL_DESERT);
                                    } else if (moisture < 0.33) {
                                        voxels[index].setType(World::GRASSLAND);
                                    } else if (moisture < 0.66) {
                                        voxels[index].setType(World::TROPICAL_SEASONAL_FOREST);
                                    } else {
                                        voxels[index].setType(World::TROPICAL_RAIN_FOREST);
                                    }
                                } else if (noise < 0.6) {
                                    if (moisture < 0.16) {
                                        voxels[index].setType(World::TEMPERATE_DESERT);
                                    } else if (moisture < 0.5) {
                                        voxels[index].setType(World::GRASSLAND);
                                    } else if (moisture < 0.83) {
                                        voxels[index].setType(World::TEMPERATE_DECIDUOUS_FOREST);
                                    } else {
                                        voxels[index].setType(World::TEMPERATE_RAIN_FOREST);
                                    }
                                } else if (noise < 0.8) {
                                    if (moisture < 0.33) {
                                        voxels[index].setType(World::TEMPERATE_DESERT);
                                    } else if (moisture < 0.66) {
                                        voxels[index].setType(World::SHRUBLAND);
                                    } else {
                                        voxels[index].setType(World::TAIGA);
                                    }
                                } else {
                                    if (moisture < 0.1) {
                                        voxels[index].setType(World::SCORCHED);
                                    } else if (moisture < 0.2) {
                                        voxels[index].setType(World::BARE);
                                    } else if (moisture < 0.5) {
                                        voxels[index].setType(World::TUNDRA);
                                    } else {
                                        voxels[index].setType(World::SNOW);
                                    }
                                }
                            } else {
                                voxels[index].setType(World::SCORCHED);
                            }
                        }

                        if (getMaxSolidHeight() < static_cast <GLuint> (z)) {
                            setMaxSolidHeight(z);
                        }

                        if (noise < 0.22) {
                            for (int zPrime = static_cast <int> (z); zPrime < 0.22 * size.getZ(); zPrime = zPrime + 1) {
                                index = getVoxelIndex(x, y, zPrime);
                                voxels[index].setType(World::OCEAN);
                            }
                            if (getMaxSolidHeight() < 0.22 * size.getZ()) {
                                setMaxSolidHeight(0.22 * size.getZ());
                            }
                            for (unsigned int zPrime = 0.22 * size.getZ(); zPrime < size.getZ(); zPrime = zPrime + 1) {
                                index = getVoxelIndex(x, y, zPrime);
                                voxels[index].setType(World::VOID);
                            }
                        } else {
                            for (unsigned int zPrime = static_cast <unsigned int> (z); zPrime < size.getZ(); zPrime = zPrime + 1) {
                                index = getVoxelIndex(x, y, zPrime);
                                voxels[index].setType(World::VOID);
                            }
                        }
                    }
                }
            }

            void Model::writeCompressedData(std::stringstream &data) const {
                GLuint x = 0, y = 0, z = 0;
                GLuint currentType = getVoxel(x, y, z).getType(), currentLineSize = 0;
                while (z != size.getZ()) {
                    if (currentType == static_cast <GLuint> (getVoxel(x, y, z).getType())) {
                        currentLineSize = currentLineSize + 1;
                    } else {
                        data.write(reinterpret_cast<char*> (&currentLineSize), 2);
                        data.write(reinterpret_cast<char*> (&currentType), 1);
                        currentType = getVoxel(x, y, z).getType();
                        currentLineSize = 1;
                    }

                    x = x + 1;
                    if (x == size.getX()) {
                        x = 0;
                        y = y + 1;
                        if (y == size.getY()) {
                            y = 0;
                            z = z + 1;
                        }
                    }
                }
                data.write(reinterpret_cast<char*> (&currentLineSize), 2);
                data.write(reinterpret_cast<char*> (&currentType), 1);
            }

            Model& Model::operator=(Model const& m) {
                voxels = m.voxels;
                size = m.size;
                maxSolidHeight = m.maxSolidHeight;
                return *this;
            }

            Model& Model::operator=(Model && m) {
                voxels = std::move(m.voxels);
                size = std::move(m.size);
                maxSolidHeight = std::move(m.maxSolidHeight);
                return *this;
            }

        };
    };
