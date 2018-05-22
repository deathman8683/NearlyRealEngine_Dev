
    #include "NRE_World.hpp"

    namespace NRE {
        namespace World {

            int World::DEFAULT_SOIL_SEED = 6'032'018;
            int World::DEFAULT_MOISTURE_SEED = 21'032'018;

            World::World() : World(Maths::Vector2D<GLuint>(0, 0), Maths::Vector2D<GLint>(0, 0)) {
            }

            World::World(Maths::Vector2D<GLuint> const& hExtent, Maths::Vector2D<GLuint> const& shift) : chunkMap((hExtent.getX() * 2 + 1) * (hExtent.getY() * 2 + 1)), regionsManager(0), hExtent(hExtent), shift(shift) {
                FastNoise worldGen, worldGen2;
                worldGen.SetNoiseType(FastNoise::Simplex);
                worldGen.SetSeed(DEFAULT_SOIL_SEED);
                worldGen.SetFrequency(0.004);
                worldGen2.SetNoiseType(FastNoise::Simplex);
                worldGen2.SetSeed(DEFAULT_MOISTURE_SEED);
                soilGenerator = worldGen;
                moistureGenerator = worldGen2;

                regionsManager = new RegionsManager(this);

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

            World::World(World && w) : chunkMap(std::move(w.chunkMap)), regionsManager(std::move(w.regionsManager)), constructionQueue(std::move(w.constructionQueue)),
                                        hExtent(std::move(w.getHExtent())), shift(std::move(w.getShift())), soilGenerator(std::move(w.getSoilGenerator())), moistureGenerator(std::move(w.getMoistureGenerator())) {
            }

            World::~World() {
                for (auto &it : chunkMap) {
                    regionsManager->addChunkToSave(it.second);
                }
                delete regionsManager;
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

            void World::render(Maths::Matrix4x4<NREfloat> const& modelview, Camera::FixedCamera* const& camera) {

                const Renderer::GBufferShader* shader = static_cast <const Renderer::GBufferShader*> (Renderer::ShadersManager::getShader("GBuffer"));

                shader->bind();
                    shader->sendModelview(modelview);
                    for (auto &it : chunkMap) {
                        it.second->checkActiveState(camera);
                        if (!it.second->isLoaded()) {
                            if (!it.second->isLoading()) {
                                regionsManager->addChunkToLoad(it.second);
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
                regionsManager->emptyLoadMap();
                for (GLuint i = 0; i < loadLimit; i = i + 1) {
                    updateConstructionQueue();
                }
                regionsManager->emptySaveMap();
            }

            NREfloat const World::getSoilNoise(NREfloat const& x, NREfloat const& y) const {
                return (getSoilGenerator().GetNoise(x, y) + 1.0) / 2.0;
            }

            NREfloat const World::getMoistureNoise(NREfloat const& x, NREfloat const& y) const {
                return (getMoistureGenerator().GetNoise(x, y) + 1.0) / 2.0;
            }

            void World::addChunkToConstruction(Chunk *chunk) {
                chunk->setConstructing(true);
                constructionQueue.push(chunk);
            }

            void World::updateConstructionQueue() {
                if (!constructionQueue.empty()) {
                    constructionQueue.front()->process(GL_STATIC_DRAW, constructionQueue.front()->getCoord());
                    constructionQueue.front()->setConstructed(true);
                    constructionQueue.front()->setConstructing(false);
                    constructionQueue.pop();
                }
            }

            void World::emptyConstructionQueue() {
                while (!constructionQueue.empty()) {
                    updateConstructionQueue();
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
                regionsManager->emptySaveMap();
                if (shiftSize.getX()  < 0) {
                    while (shiftSize.getX() < 0) {
                        shiftChunksLeft();
                        shiftSize.setX(shiftSize.getX() + 1);
                    }
                }
                regionsManager->emptySaveMap();
                if (shiftSize.getY() > 0) {
                    while (shiftSize.getY() > 0) {
                        shiftChunksFront();
                        shiftSize.setY(shiftSize.getY() - 1);
                    }
                }
                regionsManager->emptySaveMap();
                if (shiftSize.getY() < 0) {
                    while (shiftSize.getY() < 0) {
                        shiftChunksBack();
                        shiftSize.setY(shiftSize.getY() + 1);
                    }
                }
                regionsManager->emptySaveMap();
            }

            void World::shiftChunksRight() {
                for (GLint y = -getHExtent().getY(); y <= static_cast <GLint> (getHExtent().getY()); y = y + 1) {
                    Maths::Point2D<GLint> coord(getHExtent().getX() + getShift().getX(), y + getShift().getY());
                    Maths::Point2D<GLint> tmp = coord;
                    tmp.setX(-(getHExtent().getX() - getShift().getX() + 1));
                    regionsManager->addChunkToSave(getChunk(coord), coord);
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
                    regionsManager->addChunkToSave(getChunk(coord), coord);
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
                    regionsManager->addChunkToSave(getChunk(coord), coord);
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
                    regionsManager->addChunkToSave(getChunk(coord), coord);
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
                   getChunk(coord)->setLeft(0, getChunk(neighbor)->getVoxelSet(0));
                   neighbor = coord;
               }
               if (coord.getX() + 1 <= static_cast <GLint> (getHExtent().getX() + getShift().getX())) {
                   neighbor.setX(neighbor.getX() + 1);
                   getChunk(coord)->setRight(0, getChunk(neighbor)->getVoxelSet(0));
                   neighbor = coord;
               }
               if (coord.getY() - 1 >= static_cast <GLint> (-getHExtent().getY() + getShift().getY())) {
                   neighbor.setY(neighbor.getY() - 1);
                   getChunk(coord)->setBack(0, getChunk(neighbor)->getVoxelSet(0));
                   neighbor = coord;
               }
               if (coord.getY() + 1 <= static_cast <GLint> (getHExtent().getX() + getShift().getY())) {
                   neighbor.setY(neighbor.getY() + 1);
                   getChunk(coord)->setFront(0, getChunk(neighbor)->getVoxelSet(0));
                   neighbor = coord;
               }
           }

           bool const World::isInBound(Maths::Point3D<GLint> const& p) const {
               return p.getX() > static_cast <GLint> (((-getHExtent().getX() + getShift().getX()) * Chunk::SIZE_X)) && p.getX() < static_cast <GLint> (((getHExtent().getX() + getShift().getX()) * Chunk::SIZE_X)) &&
                      p.getY() > static_cast <GLint> (((-getHExtent().getY() + getShift().getY()) * Chunk::SIZE_Y)) && p.getY() < static_cast <GLint> (((getHExtent().getY() + getShift().getY()) * Chunk::SIZE_Y)) &&
                      p.getZ() > 0 && p.getX() < static_cast <GLint> (Chunk::SIZE_Z);
           }

            World& World::operator=(World && w) {
                chunkMap = std::move(w.chunkMap);
                regionsManager = std::move(w.regionsManager);
                constructionQueue = std::move(w.constructionQueue);
                hExtent = std::move(w.hExtent);
                shift = std::move(w.shift);
                soilGenerator = std::move(w.soilGenerator);
                moistureGenerator = std::move(w.moistureGenerator);
                return *this;
            }

        };
    };
