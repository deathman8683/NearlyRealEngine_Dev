
    #include "NRE_World.hpp"

    namespace NRE {
        namespace World {

            int World::DEFAULT_SEED = 6'032'018;

            World::World() : World(Maths::Vector2D<GLuint>(0, 0), true) {
            }

            World::World(Maths::Vector2D<GLuint> const& size, bool const& loadGenericTerrain) : chunkMap((size.getX() * 2 + 1) * (size.getY() * 2 + 1)), hExtent(size), voxelMergingGlobalCache(0) {
                FastNoise worldGen;
                worldGen.SetNoiseType(FastNoise::Perlin);
                worldGen.SetSeed(DEFAULT_SEED);
                generator = worldGen;

                voxelMergingGlobalCache = new bool[Chunk::SIZE_X * Chunk::SIZE_Y * Chunk::SIZE_Z * NRE::Voxel::FACE_NUM];

                for (int x = -getHExtent().getX(); x <= static_cast <GLint> (getHExtent().getX()); x = x + 1) {
                    for (int y = -getHExtent().getY(); y <= static_cast<GLint> (getHExtent().getY()); y = y + 1) {
                        Maths::Point2D<GLint> tmp(x, y);
                        chunkMap[tmp] = new Chunk(tmp, true);
                        Chunk*& it = chunkMap.at(tmp);
                        it->load(this);
                    }
                }
            }

            World::World(World const& w) : chunkMap(w.getChunkMap()), hExtent(w.getHExtent()), generator(w.getGenerator()), voxelMergingGlobalCache(w.getVoxelMergingGlobalCache()) {
            }

            World::~World() {
                delete[] voxelMergingGlobalCache;
                for (const auto &it : chunkMap) {
                    delete it.second;
                }
            }

            std::unordered_map<Maths::Point2D<GLint>, Chunk*> const& World::getChunkMap() const {
                return chunkMap;
            }

            std::unordered_map<Maths::Point2D<GLint>, Chunk*>::iterator World::getChunk(Maths::Point2D<GLint> const& p) {
                return chunkMap.find(p);
            }

            std::unordered_map<Maths::Point2D<GLint>, Chunk*>::iterator World::getChunk(GLint const& x, GLint const& y) {
                return getChunk(Maths::Point2D<GLint>(x, y));
            }

            Maths::Vector2D<GLuint> const& World::getHExtent() const {
                return hExtent;
            }

            FastNoise const& World::getGenerator() const {
                return generator;
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

            void World::setChunk(Maths::Point2D<GLint> const& p, Chunk* const& chunk) {
                chunkMap[p] = chunk;
            }

            void World::setChunk(GLint const& x, GLint const& y, Chunk* const& chunk) {
                setChunk(Maths::Point2D<GLint>(x, y), chunk);
            }

            void World::setHExtent(Maths::Vector2D<GLuint> const& size) {
                hExtent = size;
            }

            void World::setGenerator(FastNoise const& gen) {
                generator = gen;
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

            void World::render(Renderer::Shader const& shader, Maths::Matrix4x4<NREfloat> &modelview, Maths::Matrix4x4<NREfloat> &projection, Camera::FixedCamera const& camera, std::vector<Light::Light*> const& light) {
                for (const auto &it : chunkMap) {
                    it.second->render(shader, modelview, projection, camera, light);
                }
            }

            void World::resetVoxelMergingGlobalCache() {
                std::fill(voxelMergingGlobalCache, voxelMergingGlobalCache + (Chunk::SIZE_X * Chunk::SIZE_Y * Chunk::SIZE_Z * NRE::Voxel::FACE_NUM), false);
            }

            GLuint getVoxelCacheIndex(GLuint const& x, GLuint const& y, GLuint const& z, GLuint const& face) {
                return Array::get1DIndexFrom4D(x, y, z, face, Maths::Vector4D<GLuint>(Chunk::SIZE, NRE::Voxel::FACE_NUM));
            }

        };
    };
