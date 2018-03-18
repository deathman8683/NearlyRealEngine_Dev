
    /**
     * @file NRE_World.hpp
     * @brief Declaration of Engine's World's Object : World
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include <algorithm>
    #include <unordered_map>
    #include "Chunk/NRE_Chunk.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace World
         * @brief Engine's Voxel's Type's Module
         */
        namespace World {

            /**
             * @class World
             * @brief World's Object : A collection of chunk
             */
            class World {
                private:
                    std::unordered_map<Maths::Point2D<GLint>, Chunk*> chunkMap;
                    Maths::Vector2D<GLuint> hExtent;
                    FastNoise generator;
                    bool *voxelMergingGlobalCache;

                public:
                    //## Constructor ##//
                    World();
                    World(Maths::Vector2D<GLuint> const& size, bool const& loadGenericTerrain = true);

                    //## Copy-Constructor ##//
                    World(World const& w);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~World();

                    //## Getter ##//
                    std::unordered_map<Maths::Point2D<GLint>, Chunk*> const& getChunkMap() const;
                    std::unordered_map<Maths::Point2D<GLint>, Chunk*>::iterator getChunk(Maths::Point2D<GLint> const& p);
                    std::unordered_map<Maths::Point2D<GLint>, Chunk*>::iterator getChunk(GLint const& x, GLint const& y);
                    Maths::Vector2D<GLuint> const& getHExtent() const;
                    FastNoise const& getGenerator() const;
                    bool* getVoxelMergingGlobalCache() const;
                    bool const& getVoxelMergingFace(Maths::Point3D<GLuint> const& p, int const& face) const;
                    bool const& getVoxelMergingFace(GLuint const& x, GLuint const& y, GLuint const& z, int const& face) const;

                    //## Setter ##//
                    void setChunkMap(std::unordered_map<Maths::Point2D<GLint>, Chunk*> const& map);
                    void setChunk(Maths::Point2D<GLint> const& p, Chunk* const& chunk);
                    void setChunk(GLint const& x, GLint const& y, Chunk* const& chunk);
                    void setHExtent(Maths::Vector2D<GLuint> const& size);
                    void setGenerator(FastNoise const& gen);
                    void setVoxelMergingGlobalCache(bool* (&cache));
                    void setVoxelMergingFace(Maths::Point3D<GLuint> const& p, int const& face, bool const& state);
                    void setVoxelMergingFace(GLuint const& x, GLuint const& y, GLuint const& z, int const& face, bool const& state);

                    //## Methods ##//
                    void constructChunksMesh();
                    void render(Renderer::Shader const& shader, Maths::Matrix4x4<NREfloat> &modelview, Maths::Matrix4x4<NREfloat> &projection, Camera::FixedCamera const& camera);
                    void resetVoxelMergingGlobalCache();

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
                    static int DEFAULT_SEED;
            };

            GLuint getVoxelCacheIndex(GLuint const& x, GLuint const& y, GLuint const& z, GLuint const& face);

        };
    };
