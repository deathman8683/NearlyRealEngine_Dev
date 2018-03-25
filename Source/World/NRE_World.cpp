
    #include "NRE_World.hpp"

    namespace NRE {
        namespace World {

            int World::DEFAULT_SOIL_SEED = 6'032'018;
            int World::DEFAULT_MOISTURE_SEED = 21'032'018;

            World::World() : World(Maths::Vector2D<GLuint>(0, 0), true) {
            }

            World::World(Maths::Vector2D<GLuint> const& size, bool const& loadGenericTerrain) : chunkMap((size.getX() * 2 + 1) * (size.getY() * 2 + 1)), hExtent(size), voxelMergingGlobalCache(0) {
                FastNoise worldGen, worldGen2;
                worldGen.SetNoiseType(FastNoise::Simplex);
                worldGen.SetSeed(DEFAULT_SOIL_SEED);
                worldGen.SetFrequency(0.004);
                worldGen2.SetNoiseType(FastNoise::Simplex);
                worldGen2.SetSeed(DEFAULT_MOISTURE_SEED);
                soilGenerator = worldGen;
                moistureGenerator = worldGen2;

                voxelMergingGlobalCache = new bool[Chunk::SIZE_X * Chunk::SIZE_Y * Chunk::SIZE_Z * FACE_NUM];

                for (int x = -getHExtent().getX(); x <= static_cast <GLint> (getHExtent().getX()); x = x + 1) {
                    for (int y = -getHExtent().getY(); y <= static_cast<GLint> (getHExtent().getY()); y = y + 1) {
                        Maths::Point2D<GLint> tmp(x, y);
                        chunkMap[tmp] = new Chunk(tmp, true);
                    }
                }
            }

            World::World(World const& w) : chunkMap(w.getChunkMap()), loadRegionMap(w.getLoadRegionMap()), saveRegionMap(w.getSaveRegionMap()), constructionStack(w.getConstructionStack()), hExtent(w.getHExtent()), soilGenerator(w.getSoilGenerator()), moistureGenerator(w.getMoistureGenerator()), voxelMergingGlobalCache(w.getVoxelMergingGlobalCache()) {
            }

            World::~World() {
                delete[] voxelMergingGlobalCache;
                for (auto &it : chunkMap) {
                    addChunkToSaveRegion(it.second);
                }
                emptySaveRegionMap();
                for (const auto &it : chunkMap) {
                    delete it.second;
                }
            }

            std::unordered_map<Maths::Point2D<GLint>, Chunk*> const& World::getChunkMap() const {
                return chunkMap;
            }

            std::unordered_map<Maths::Point2D<GLint>, Region*> const& World::getLoadRegionMap() const {
                return loadRegionMap;
            }

            std::unordered_map<Maths::Point2D<GLint>, Region*> const& World::getSaveRegionMap() const {
                return saveRegionMap;
            }

            std::stack<Chunk*> const& World::getConstructionStack() const {
                return constructionStack;
            }

            Chunk* const& World::getChunk(Maths::Point2D<GLint> const& p) {
                return chunkMap.find(p)->second;
            }

            Chunk* const& World::getChunk(GLint const& x, GLint const& y) {
                return getChunk(Maths::Point2D<GLint>(x, y));
            }

            Maths::Vector2D<GLuint> const& World::getHExtent() const {
                return hExtent;
            }

            FastNoise const& World::getSoilGenerator() const {
                return soilGenerator;
            }

            FastNoise const& World::getMoistureGenerator() const {
                return moistureGenerator;
            }

            bool* World::getVoxelMergingGlobalCache() const {
                return voxelMergingGlobalCache;
            }

            bool const& World::getVoxelMergingFace(Maths::Point3D<GLuint> const& p, int const& face) const {
                return getVoxelMergingFace(p.getX(), p.getY(), p.getZ(), face);
            }

            bool const& World::getVoxelMergingFace(GLuint const& x, GLuint const& y, GLuint const& z, int const& face) const {
                return voxelMergingGlobalCache[getVoxelCacheIndex(x, y, z, face)];
            }

            void World::setChunkMap(std::unordered_map<Maths::Point2D<GLint>, Chunk*> const& map) {
                chunkMap = map;
            }

            void World::setLoadRegionMap(std::unordered_map<Maths::Point2D<GLint>, Region*> const& map) {
                loadRegionMap = map;
            }

            void World::setSaveRegionMap(std::unordered_map<Maths::Point2D<GLint>, Region*> const& map) {
                saveRegionMap = map;
            }

            void World::setConstructionStack(std::stack<Chunk*> const& stack) {
                constructionStack = stack;
            }

            void World::setChunk(Maths::Point2D<GLint> const& p, Chunk* const& chunk) {
                chunkMap[p] = chunk;
            }

            void World::setChunk(GLint const& x, GLint const& y, Chunk* const& chunk) {
                setChunk(Maths::Point2D<GLint>(x, y), chunk);
            }

            void World::setHExtent(Maths::Vector2D<GLuint> const& size) {
                hExtent = size;
            }

            void World::setSoilGenerator(FastNoise const& gen) {
                soilGenerator = gen;
            }

            void World::setMoistureGenerator(FastNoise const& gen) {
                moistureGenerator = gen;
            }

            void World::setVoxelMergingGlobalCache(bool* (&cache)) {
                voxelMergingGlobalCache = cache;
            }
            void World::setVoxelMergingFace(Maths::Point3D<GLuint> const& p, int const& face, bool const& state) {
                setVoxelMergingFace(p.getX(), p.getY(), p.getZ(), face, state);
            }

            void World::setVoxelMergingFace(GLuint const& x, GLuint const& y, GLuint const& z, int const& face, bool const& state) {
                voxelMergingGlobalCache[getVoxelCacheIndex(x, y, z, face)] = state;
            }

            void World::constructChunksMesh() {
                for (const auto &it : chunkMap) {
                    it.second->constructMesh(this);
                }
            }

            void World::render(Renderer::Shader const& shader, Maths::Matrix4x4<NREfloat> &MVP, Camera::FixedCamera const& camera) {
                for (auto &it : chunkMap) {
                    if (!it.second->isLoaded()) {
                        addChunkToLoadRegion(it.second);
                    }
                    if (!it.second->isConstructed()) {
                        addChunkToConstruction(it.second);
                    }
                    if (it.second->isLoaded() && it.second->isConstructed()) {
                        it.second->render(shader, MVP, camera);
                    }
                }
                emptyLoadRegionMap();
                emptyConstructionStack();
            }

            void World::resetVoxelMergingGlobalCache() {
                std::fill(voxelMergingGlobalCache, voxelMergingGlobalCache + (Chunk::SIZE_X * Chunk::SIZE_Y * Chunk::SIZE_Z * FACE_NUM), false);
            }

            NREfloat const World::getSoilNoise(NREfloat const& x, NREfloat const& y) const {
                return (getSoilGenerator().GetNoise(x, y) + 1.0) / 2.0;
            }

            NREfloat const World::getMoistureNoise(NREfloat const& x, NREfloat const& y) const {
                return (getMoistureGenerator().GetNoise(x, y) + 1.0) / 2.0;
            }

            void World::addChunkToLoadRegion(Chunk *chunk) {
                Maths::Point2D<GLint> coord;
                if (chunk->getCoord().getX() < 0) {
                    coord.setX((chunk->getCoord().getX() / 16) -1);
                } else {
                    coord.setX((chunk->getCoord().getX() / 16));
                }
                if (chunk->getCoord().getY() < 0) {
                    coord.setY((chunk->getCoord().getY() / 16) -1);
                } else {
                    coord.setY((chunk->getCoord().getY() / 16));
                }
                if (loadRegionMap.count(coord) == 0) {
                    loadRegionMap[chunk->getCoord()] = new Region(chunk);
                } else {
                    auto it = loadRegionMap.find(coord);
                    it->second->add(chunk);
                }
            }

            void World::addChunkToSaveRegion(Chunk *chunk) {
                Maths::Point2D<GLint> coord;
                if (chunk->getCoord().getX() < 0) {
                    coord.setX((chunk->getCoord().getX() / 16) -1);
                } else {
                    coord.setX((chunk->getCoord().getX() / 16));
                }
                if (chunk->getCoord().getY() < 0) {
                    coord.setY((chunk->getCoord().getY() / 16) -1);
                } else {
                    coord.setY((chunk->getCoord().getY() / 16));
                }
                if (saveRegionMap.count(coord) == 0) {
                    saveRegionMap[coord] = new Region(chunk);
                } else {
                    auto it = saveRegionMap.find(coord);
                    it->second->add(chunk);
                }
            }

            void World::addChunkToConstruction(Chunk *chunk) {
                constructionStack.push(chunk);
            }

            void World::emptyLoadRegionMap() {
                for (auto &it : loadRegionMap) {
                    it.second->load(this);
                }
                for (auto &it : loadRegionMap) {
                    delete it.second;
                }
                loadRegionMap.erase(loadRegionMap.begin(), loadRegionMap.end());
            }

            void World::emptySaveRegionMap() {
                for (auto &it : saveRegionMap) {
                    it.second->save();
                }
                for (auto &it : saveRegionMap) {
                    delete it.second;
                }
                saveRegionMap.erase(saveRegionMap.begin(), saveRegionMap.end());
            }

            void World::emptyConstructionStack() {
                size_t limit = constructionStack.size();
                for (GLuint i = 0; i < limit; i = i + 1) {
                    constructionStack.top()->constructMesh(this);
                    constructionStack.top()->setConstructed(true);
                    constructionStack.pop();
                }
            }

            GLuint getVoxelCacheIndex(GLuint const& x, GLuint const& y, GLuint const& z, GLuint const& face) {
                return Array::get1DIndexFrom4D(x, y, z, face, Maths::Vector4D<GLuint>(Chunk::SIZE, FACE_NUM));
            }

        };
    };
