
    #include "NRE_RegionsManager.hpp"

    namespace NRE {
        namespace World {

            RegionsManager::RegionsManager() : RegionsManager(0) {
            }

            RegionsManager::RegionsManager(World* w) : w(w) {
            }

            RegionsManager::RegionsManager(RegionsManager const& rm) : w(rm.w), saveMap(rm.saveMap), loadMap(rm.loadMap) {
            }

            RegionsManager::RegionsManager(RegionsManager && rm) : w(std::move(rm.w)), saveMap(std::move(rm.saveMap)), loadMap(std::move(rm.loadMap)) {
            }

            RegionsManager::~RegionsManager() {
                emptySaveMap();
            }

            void RegionsManager::addChunkToLoad(Chunk *chunk) {
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
                if (loadMap.count(regionCoord) == 0) {
                    loadMap[regionCoord] = new Region(chunk);
                } else {
                    auto it = loadMap.find(regionCoord);
                    it->second->add(chunk);
                }
            }

            void RegionsManager::addChunkToSave(Chunk *chunk) {
                addChunkToSave(chunk, chunk->getCoord());
            }

            void RegionsManager::addChunkToSave(Chunk *chunk, Maths::Point2D<GLint> const& coord) {
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
                if (saveMap.count(regionCoord) == 0) {
                    saveMap[regionCoord] = new Region(chunk);
                } else {
                    auto it = saveMap.find(regionCoord);
                    it->second->add(chunk, coord);
                }
            }

            void RegionsManager::updateLoadMap() {
                if (!loadMap.empty()) {
                    auto it = loadMap.begin();
                    it->second->load(w);
                    delete it->second;
                    loadMap.erase(loadMap.begin());
                }
            }

            void RegionsManager::updateSaveMap() {
                if (!saveMap.empty()) {
                    auto it = saveMap.begin();
                    it->second->save();
                    delete it->second;
                    saveMap.erase(saveMap.begin());
                }
            }

            void RegionsManager::emptyLoadMap() {
                while (!loadMap.empty()) {
                    updateLoadMap();
                }
            }

            void RegionsManager::emptySaveMap() {
                while (!saveMap.empty()) {
                    updateSaveMap();
                }
            }

            void RegionsManager::flushLoadMap() {
                while (!loadMap.empty()) {
                    auto it = loadMap.begin();
                    delete it->second;
                    loadMap.erase(loadMap.begin());
                }
            }

            void RegionsManager::flushSaveMap() {
                while (!saveMap.empty()) {
                    auto it = saveMap.begin();
                    delete it->second;
                    saveMap.erase(saveMap.begin());
                }
            }

            RegionsManager& RegionsManager::operator=(RegionsManager const& rm) {
                saveMap = rm.saveMap;
                loadMap = rm.loadMap;
                return *this;
            }

            RegionsManager& RegionsManager::operator=(RegionsManager && rm) {
                saveMap = std::move(rm.saveMap);
                loadMap = std::move(rm.loadMap);
                return *this;
            }

        };
    };
