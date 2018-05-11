
    #include "NRE_World.hpp"

    namespace NRE {
        namespace World {

            int World::DEFAULT_SOIL_SEED = 6'032'018;
            int World::DEFAULT_MOISTURE_SEED = 21'032'018;

            World::World() : World(Maths::Vector2D<GLuint>(0, 0), Maths::Vector2D<GLint>(0, 0)) {
            }

            World::World(Maths::Vector2D<GLuint> const& hExtent, Maths::Vector2D<GLuint> const& shift) : chunkMap((hExtent.getX() * 2 + 1) * (hExtent.getY() * 2 + 1)), hExtent(hExtent), shift(shift){
                FastNoise worldGen, worldGen2;
                worldGen.SetNoiseType(FastNoise::Simplex);
                worldGen.SetSeed(DEFAULT_SOIL_SEED);
                worldGen.SetFrequency(0.004);
                worldGen2.SetNoiseType(FastNoise::Simplex);
                worldGen2.SetSeed(DEFAULT_MOISTURE_SEED);
                soilGenerator = worldGen;
                moistureGenerator = worldGen2;

                for (int x = -getHExtent().getX(); x <= static_cast <GLint> (getHExtent().getX()); x = x + 1) {
                    for (int y = -getHExtent().getY(); y <= static_cast<GLint> (getHExtent().getY()); y = y + 1) {
                        Maths::Point2D<GLint> tmp(x + getShift().getX(), y + getShift().getY());
                        chunkMap[tmp] = new Chunk(tmp, true);
                    }
                }

                for (auto &it : chunkMap) {
                    setChunkNeighbor(it.second->getCoord());
                }
            }

            World::World(World && w) : chunkMap(std::move(w.chunkMap)), loadRegionMap(std::move(w.loadRegionMap)), saveRegionMap(std::move(w.saveRegionMap)), constructionQueue(std::move(w.constructionQueue)),
                                        hExtent(std::move(w.getHExtent())), shift(std::move(w.getShift())), soilGenerator(std::move(w.getSoilGenerator())), moistureGenerator(std::move(w.getMoistureGenerator())) {
            }

            World::~World() {
                for (auto &it : chunkMap) {
                    addChunkToSaveRegion(it.second);
                }
                emptySaveRegionMap();
                for (const auto &it : chunkMap) {
                    delete it.second;
                }
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

            Maths::Vector2D<GLint> const& World::getShift() const {
                return shift;
            }

            FastNoise const& World::getSoilGenerator() const {
                return soilGenerator;
            }

            FastNoise const& World::getMoistureGenerator() const {
                return moistureGenerator;
            }

            void World::setShift(Maths::Vector2D<GLint> const& size) {
                shift = size;
            }

            void World::render(Maths::Matrix4x4<NREfloat> &modelview, Maths::Matrix4x4<NREfloat> &projection, Camera::FixedCamera* const& camera) {

                const Renderer::Shader* shader = Renderer::EngineShader::getShader("GBuffer");

                shader->bind();
                    shader->useMat4("modelview", 1, &modelview);
                    shader->useMat4("projection", 1, &projection);
                    for (auto &it : chunkMap) {
                        it.second->checkActiveState(camera);
                        if (!it.second->isLoaded()) {
                            if (!it.second->isLoading()) {
                                addChunkToLoadRegion(it.second);
                            }
                        }
                        if (it.second->isLoaded() && !it.second->isConstructed()) {
                            if (!it.second->isConstructing()) {
                                addChunkToConstruction(it.second);
                            }
                        }
                        if (it.second->isActive()) {
                            if (it.second->isLoaded() && it.second->isConstructed()) {
                                it.second->draw();
                            }
                        }
                    }
                shader->unbind();
            }

            void World::update(GLuint const& loadLimit) {
                emptyLoadRegionMap();
                for (GLuint i = 0; i < loadLimit; i = i + 1) {
                    updateConstructionQueue();
                }
                emptySaveRegionMap();
            }

            NREfloat const World::getSoilNoise(NREfloat const& x, NREfloat const& y) const {
                return (getSoilGenerator().GetNoise(x, y) + 1.0) / 2.0;
            }

            NREfloat const World::getMoistureNoise(NREfloat const& x, NREfloat const& y) const {
                return (getMoistureGenerator().GetNoise(x, y) + 1.0) / 2.0;
            }

            void World::addChunkToLoadRegion(Chunk *chunk) {
                chunk->setLoading(true);
                Maths::Point2D<GLint> regionCoord;
                if (chunk->getCoord().getX() < 0) {
                    regionCoord.setX((chunk->getCoord().getX() / 16) - 1);
                } else {
                    regionCoord.setX((chunk->getCoord().getX() / 16));
                }
                if (chunk->getCoord().getY() < 0) {
                    regionCoord.setY((chunk->getCoord().getY() / 16) - 1);
                } else {
                    regionCoord.setY((chunk->getCoord().getY() / 16));
                }
                if (loadRegionMap.count(regionCoord) == 0) {
                    loadRegionMap[regionCoord] = new Region(chunk);
                } else {
                    auto it = loadRegionMap.find(regionCoord);
                    it->second->add(chunk);
                }
            }

            void World::addChunkToSaveRegion(Chunk *chunk) {
                addChunkToSaveRegion(chunk, chunk->getCoord());
            }

            void World::addChunkToSaveRegion(Chunk *chunk, Maths::Point2D<GLint> const& coord) {
                Maths::Point2D<GLint> regionCoord;
                if (chunk->getCoord().getX() < 0) {
                    regionCoord.setX((chunk->getCoord().getX() / 16) - 1);
                } else {
                    regionCoord.setX((chunk->getCoord().getX() / 16));
                }
                if (chunk->getCoord().getY() < 0) {
                    regionCoord.setY((chunk->getCoord().getY() / 16) - 1);
                } else {
                    regionCoord.setY((chunk->getCoord().getY() / 16));
                }
                if (saveRegionMap.count(regionCoord) == 0) {
                    saveRegionMap[regionCoord] = new Region(chunk);
                } else {
                    auto it = saveRegionMap.find(regionCoord);
                    it->second->add(chunk, coord);
                }
            }

            void World::addChunkToConstruction(Chunk *chunk) {
                chunk->setConstructing(true);
                constructionQueue.push(chunk);
            }

            void World::updateLoadRegionMap() {
                if (!loadRegionMap.empty()) {
                    auto it = loadRegionMap.begin();
                    it->second->load(this);
                    delete it->second;
                    loadRegionMap.erase(loadRegionMap.begin());
                }
            }

            void World::updateSaveRegionMap() {
                if (!saveRegionMap.empty()) {
                    auto it = saveRegionMap.begin();
                    it->second->save();
                    delete it->second;
                    saveRegionMap.erase(saveRegionMap.begin());
                }
            }

            void World::updateConstructionQueue() {
                if (!constructionQueue.empty()) {
                    constructionQueue.front()->process(GL_STATIC_DRAW, constructionQueue.front()->getCoord());
                    constructionQueue.front()->setConstructed(true);
                    constructionQueue.front()->setConstructing(false);
                    constructionQueue.pop();
                }
            }

            void World::emptyLoadRegionMap() {
                while (!loadRegionMap.empty()) {
                    updateLoadRegionMap();
                }
            }

            void World::emptySaveRegionMap() {
                while (!saveRegionMap.empty()) {
                    updateSaveRegionMap();
                }
            }

            void World::emptyConstructionQueue() {
                while (!constructionQueue.empty()) {
                    updateConstructionQueue();
                }
            }


            void World::flushLoadRegionMap() {
                while (!loadRegionMap.empty()) {
                    auto it = loadRegionMap.begin();
                    delete it->second;
                    loadRegionMap.erase(loadRegionMap.begin());
                }
            }

            void World::flushSaveRegionMap() {
                while (!saveRegionMap.empty()) {
                    auto it = saveRegionMap.begin();
                    delete it->second;
                    saveRegionMap.erase(saveRegionMap.begin());
                }
            }

            void World::flushConstructionQueue() {
                while (!constructionQueue.empty()) {
                    constructionQueue.pop();
                }
            }

            void World::shiftChunks(Maths::Vector2D<GLint> shiftSize) {
                if (shiftSize.getX() > 0) {
                    while (shiftSize.getX() > 0) {
                        shiftChunksRight();
                        shiftSize.setX(shiftSize.getX() - 1);
                    }
                }
                emptySaveRegionMap();
                if (shiftSize.getX()  < 0) {
                    while (shiftSize.getX() < 0) {
                        shiftChunksLeft();
                        shiftSize.setX(shiftSize.getX() + 1);
                    }
                }
                emptySaveRegionMap();
                if (shiftSize.getY() > 0) {
                    while (shiftSize.getY() > 0) {
                        shiftChunksFront();
                        shiftSize.setY(shiftSize.getY() - 1);
                    }
                }
                emptySaveRegionMap();
                if (shiftSize.getY() < 0) {
                    while (shiftSize.getY() < 0) {
                        shiftChunksBack();
                        shiftSize.setY(shiftSize.getY() + 1);
                    }
                }
                emptySaveRegionMap();
            }

            void World::shiftChunksRight() {
                for (GLint y = -getHExtent().getY(); y <= static_cast <GLint> (getHExtent().getY()); y = y + 1) {
                    Maths::Point2D<GLint> coord(getHExtent().getX() + getShift().getX(), y + getShift().getY());
                    Maths::Point2D<GLint> tmp = coord;
                    tmp.setX(-(getHExtent().getX() - getShift().getX() + 1));
                    addChunkToSaveRegion(getChunk(coord), coord);
                    getChunk(coord)->setCoord(tmp);
                    getChunk(coord)->reload();
                    Chunk* adr = getChunk(coord);
                    chunkMap.erase(coord);
                    chunkMap[tmp] = adr;
                    setChunkNeighbor(tmp);
                }
                shift.setX(getShift().getX() - 1);
            }

            void World::shiftChunksLeft() {
                for (GLint y = -getHExtent().getY(); y <= static_cast <GLint> (getHExtent().getY()); y = y + 1) {
                    Maths::Point2D<GLint> coord(-(getHExtent().getX()) + getShift().getX(), y + getShift().getY());
                    Maths::Point2D<GLint> tmp = coord;
                    tmp.setX(getHExtent().getX() + getShift().getX() + 1);
                    addChunkToSaveRegion(getChunk(coord), coord);
                    getChunk(coord)->setCoord(tmp);
                    getChunk(coord)->reload();
                    Chunk* adr = getChunk(coord);
                    chunkMap.erase(coord);
                    chunkMap[tmp] = adr;
                    setChunkNeighbor(tmp);
                }
                shift.setX(getShift().getX() + 1);
            }

            void World::shiftChunksFront() {
                for (GLint x = -getHExtent().getX(); x <= static_cast <GLint> (getHExtent().getX()); x = x + 1) {
                    Maths::Point2D<GLint> coord(x  + getShift().getX(), getHExtent().getY() + getShift().getY());
                    Maths::Point2D<GLint> tmp = coord;
                    tmp.setY(-(getHExtent().getY() - getShift().getY() + 1));
                    addChunkToSaveRegion(getChunk(coord), coord);
                    getChunk(coord)->setCoord(tmp);
                    getChunk(coord)->reload();
                    Chunk* adr = getChunk(coord);
                    chunkMap.erase(coord);
                    chunkMap[tmp] = adr;
                    setChunkNeighbor(tmp);
                }
                shift.setY(getShift().getY() - 1);
            }

            void World::shiftChunksBack() {
                for (GLint x = -getHExtent().getX(); x <= static_cast <GLint> (getHExtent().getX()); x = x + 1) {
                    Maths::Point2D<GLint> coord(x + getShift().getX(), -(getHExtent().getY()) + getShift().getY());
                    Maths::Point2D<GLint> tmp = coord;
                    tmp.setY(getHExtent().getY() + getShift().getY() + 1);
                    addChunkToSaveRegion(getChunk(coord), coord);
                    getChunk(coord)->setCoord(tmp);
                    getChunk(coord)->reload();
                    Chunk* adr = getChunk(coord);
                    chunkMap.erase(coord);
                    chunkMap[tmp] = adr;
                    setChunkNeighbor(tmp);
                }
                shift.setY(getShift().getY() + 1);
            }

           void World::setChunkNeighbor(Maths::Point2D<GLint> const& coord) {
               Maths::Point2D<GLint> neighbor(coord);
               if (coord.getX() - 1 >= static_cast <GLint> (-getHExtent().getX() + getShift().getX())) {
                   neighbor.setX(neighbor.getX() - 1);
                   getChunk(coord)->setLeft(*getChunk(neighbor));
                   neighbor = coord;
               }
               if (coord.getX() + 1 <= static_cast <GLint> (getHExtent().getX() + getShift().getX())) {
                   neighbor.setX(neighbor.getX() + 1);
                   getChunk(coord)->setRight(*getChunk(neighbor));
                   neighbor = coord;
               }
               if (coord.getY() - 1 >= static_cast <GLint> (-getHExtent().getY() + getShift().getY())) {
                   neighbor.setY(neighbor.getY() - 1);
                   getChunk(coord)->setBack(*getChunk(neighbor));
                   neighbor = coord;
               }
               if (coord.getY() + 1 <= static_cast <GLint> (getHExtent().getX() + getShift().getY())) {
                   neighbor.setY(neighbor.getY() + 1);
                   getChunk(coord)->setFront(*getChunk(neighbor));
                   neighbor = coord;
               }
           }

            World& World::operator=(World && w) {
                chunkMap = std::move(w.chunkMap);
                loadRegionMap = std::move(w.loadRegionMap);
                saveRegionMap = std::move(w.saveRegionMap);
                constructionQueue = std::move(w.constructionQueue);
                hExtent = std::move(w.hExtent);
                shift = std::move(w.shift);
                soilGenerator = std::move(w.soilGenerator);
                moistureGenerator = std::move(w.moistureGenerator);
                return *this;
            }

        };
    };
