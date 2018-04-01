
    /**
     * @file NRE_World.hpp
     * @brief Declaration of Engine's World's Object : World
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include <algorithm>
    #include <unordered_map>
    #include "Region/NRE_Region.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace World
         * @brief Engine's World's Module
         */
        namespace World {

            /**
             * @class World
             * @brief World's Object : A collection of chunk
             */
            class World {
                private:
                    std::unordered_map<Maths::Point2D<GLint>, Chunk*> chunkMap;
                    std::unordered_map<Maths::Point2D<GLint>, Region*> loadRegionMap;
                    std::unordered_map<Maths::Point2D<GLint>, Region*> saveRegionMap;
                    std::stack<Chunk*> constructionStack;
                    Maths::Vector2D<GLuint> hExtent;
                    Maths::Vector2D<GLint> shift;
                    FastNoise soilGenerator;
                    FastNoise moistureGenerator;
                    bool *voxelMergingGlobalCache;

                public:
                    //## Constructor ##//
                    World();
                    World(Maths::Vector2D<GLuint> const& hExtent, Maths::Vector2D<GLuint> const& shift);

                    //## Copy-Constructor ##//
                    World(World const& w);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~World();

                    //## Getter ##//
                    std::unordered_map<Maths::Point2D<GLint>, Chunk*> const& getChunkMap() const;
                    std::unordered_map<Maths::Point2D<GLint>, Region*> const& getLoadRegionMap() const;
                    std::unordered_map<Maths::Point2D<GLint>, Region*> const& getSaveRegionMap() const;
                    std::stack<Chunk*> const& getConstructionStack() const;
                    Chunk* const& getChunk(Maths::Point2D<GLint> const& p);
                    Chunk* const& getChunk(GLint const& x, GLint const& y);
                    Maths::Vector2D<GLuint> const& getHExtent() const;
                    Maths::Vector2D<GLint> const& getShift() const;
                    FastNoise const& getSoilGenerator() const;
                    FastNoise const& getMoistureGenerator() const;
                    bool* getVoxelMergingGlobalCache() const;
                    bool const& getVoxelMergingFace(Maths::Point3D<GLuint> const& p, int const& face) const;
                    bool const& getVoxelMergingFace(GLuint const& x, GLuint const& y, GLuint const& z, int const& face) const;

                    //## Setter ##//
                    void setChunkMap(std::unordered_map<Maths::Point2D<GLint>, Chunk*> const& map);
                    void setLoadRegionMap(std::unordered_map<Maths::Point2D<GLint>, Region*> const& map);
                    void setSaveRegionMap(std::unordered_map<Maths::Point2D<GLint>, Region*> const& map);
                    void setConstructionStack(std::stack<Chunk*> const& stack);
                    void setChunk(Maths::Point2D<GLint> const& p, Chunk* const& chunk);
                    void setChunk(GLint const& x, GLint const& y, Chunk* const& chunk);
                    void setHExtent(Maths::Vector2D<GLuint> const& size);
                    void setShift(Maths::Vector2D<GLint> const& size);
                    void setSoilGenerator(FastNoise const& gen);
                    void setMoistureGenerator(FastNoise const& gen);
                    void setVoxelMergingGlobalCache(bool* (&cache));
                    void setVoxelMergingFace(Maths::Point3D<GLuint> const& p, int const& face, bool const& state);
                    void setVoxelMergingFace(GLuint const& x, GLuint const& y, GLuint const& z, int const& face, bool const& state);

                    //## Methods ##//
                    void constructChunksMesh();
                    void render(Renderer::Shader const& shader, Maths::Matrix4x4<NREfloat> &modelview, Maths::Matrix4x4<NREfloat> &projection, Camera::FixedCamera* const& camera = 0);
                    void resetVoxelMergingGlobalCache();
                    NREfloat const getSoilNoise(NREfloat const& x, NREfloat const& y) const;
                    NREfloat const getMoistureNoise(NREfloat const& x, NREfloat const& y) const;
                    void addChunkToLoadRegion(Chunk *chunk);
                    void addChunkToSaveRegion(Chunk *chunk);
                    void addChunkToSaveRegion(Chunk *chunk, Maths::Point2D<GLint> const& coord);
                    void addChunkToConstruction(Chunk *chunk);
                    void emptyLoadRegionMap();
                    void emptySaveRegionMap();
                    void emptyConstructionStack();
                    void shiftChunks(Maths::Vector2D<GLint> shiftSize);

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
                    static int DEFAULT_SOIL_SEED;
                    static int DEFAULT_MOISTURE_SEED;
            };

            GLuint getVoxelCacheIndex(GLuint const& x, GLuint const& y, GLuint const& z, GLuint const& face);

        };
    };
