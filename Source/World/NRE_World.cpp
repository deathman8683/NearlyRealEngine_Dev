
    #include "NRE_World.hpp"

    namespace NRE {
        namespace World {

            World::World() : World(Maths::Vector2D<GLuint>(0, 0), true) {
            }

            World::World(Maths::Vector2D<GLuint> const& size, bool const& loadGenericTerrain) : chunkMap((size.getX() * 2 + 1) * (size.getY() * 2 + 1)), hExtent(size) {
                for (int x = -getHExtent().getX(); x <= static_cast <GLint> (getHExtent().getX()); x = x + 1) {
                    for (int y = -getHExtent().getY(); y <= static_cast<GLint> (getHExtent().getY()); y = y + 1) {
                        Maths::Point2D<GLint> tmp(x, y);
                        chunkMap[tmp] = new Chunk(tmp, true);
                    }
                }
            }

            World::World(World const& w) : chunkMap(w.getChunkMap()), hExtent(w.getHExtent()), generator(w.getGenerator()) {
            }

            World::~World() {
                for (const auto &it : chunkMap) {
                    delete it.second;
                }
            }

            std::unordered_map<Maths::Point2D<GLint>, Chunk*> const& World::getChunkMap() const {
                return chunkMap;
            }

            std::unordered_map<Maths::Point2D<GLint>, Chunk*>::const_iterator World::getChunk(Maths::Point2D<GLint> const& p) const {
                return chunkMap.find(p);
            }

            std::unordered_map<Maths::Point2D<GLint>, Chunk*>::const_iterator World::getChunk(GLint const& x, GLint const& y) const {
                return getChunk(Maths::Point2D<GLint>(x, y));
            }

            Maths::Vector2D<GLuint> const& World::getHExtent() const {
                return hExtent;
            }

            FastNoise const& World::getGenerator() const {
                return generator;
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

            void World::constructChunksMesh() {
                for (const auto &it : chunkMap) {
                    it.second->constructMesh();
                }
            }

            void World::render(Renderer::Shader const& shader, Maths::Matrix4x4<NREfloat> &modelview, Maths::Matrix4x4<NREfloat> &projection) {
                for (const auto &it : chunkMap) {
                    it.second->render(shader, modelview, projection);
                }
            }

        };
    };
