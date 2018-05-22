
    #include "NRE_ChunksManager.hpp"

    namespace NRE {
        namespace World {

            ChunksManager::ChunksManager() {
            }

            ChunksManager::ChunksManager(ChunksManager const& cm) : constructionQueue(cm.constructionQueue) {
            }

            ChunksManager::ChunksManager(ChunksManager && cm) : constructionQueue(std::move(cm.constructionQueue)) {
            }

            ChunksManager::~ChunksManager() {
            }

            void ChunksManager::addChunkToConstruction(Chunk *chunk) {
                chunk->setConstructing(true);
                constructionQueue.push(chunk);
            }

            void ChunksManager::updateConstructionQueue() {
                if (!constructionQueue.empty()) {
                    constructionQueue.front()->process(GL_STATIC_DRAW, constructionQueue.front()->getCoord());
                    constructionQueue.front()->setConstructed(true);
                    constructionQueue.front()->setConstructing(false);
                    constructionQueue.pop();
                }
            }

            void ChunksManager::emptyConstructionQueue() {
                while (!constructionQueue.empty()) {
                    updateConstructionQueue();
                }
            }

            void ChunksManager::flushConstructionQueue() {
                while (!constructionQueue.empty()) {
                    constructionQueue.pop();
                }
            }

            ChunksManager& ChunksManager::operator=(ChunksManager const& cm) {
                constructionQueue = cm.constructionQueue;
                return *this;
            }

            ChunksManager& ChunksManager::operator=(ChunksManager && cm) {
                constructionQueue = std::move(cm.constructionQueue);
                return *this;
            }

        };
    };
