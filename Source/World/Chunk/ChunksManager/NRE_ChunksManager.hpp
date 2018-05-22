
    /**
     * @file NRE_ChunksManager.hpp
     * @brief Declaration of Engine's World's Object : ChunksManager
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include <queue>
    #include "../NRE_Chunk.hpp"

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

            class World;

            /**
             * @class ChunksManager
             * @brief World's Object : Manage chunks, manage saving and loading with a region manager and chunk's construction
             */
            class ChunksManager {
                private:
                    std::queue<Chunk*> constructionQueue;

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        ChunksManager();

                    //## Copy-Constructor ##//
                        /**
                         * Copy cm into this
                         * @param cm the chunks manager to copy the content
                         */
                        ChunksManager(ChunksManager const& cm);

                    //## Move-Constructor ##//
                        /**
                         * Move cm into this, leaving cm empty
                         * @param cm the chunks manager to move
                         */
                        ChunksManager(ChunksManager && cm);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * ChunksManager Deconstructor
                         */
                        ~ChunksManager();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Add a chunk to the construction queue
                         * @param chunk the chunk to add
                         */
                        void addChunkToConstruction(Chunk *chunk);
                        /**
                         * Update the construction queue, process the first chunk in the queue
                         */
                        void updateConstructionQueue();
                        /**
                         * Empty the construction queue, process all chunk in the queue
                         */
                        void emptyConstructionQueue();
                        /**
                         * Flush the construction queue, just erase them from the queue
                         */
                        void flushConstructionQueue();

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of cm into this
                         * @param cm the chunks manager to copy into this
                         * @return the reference of himself
                         */
                        ChunksManager& operator=(ChunksManager const& cm);
                        /**
                         * Move assigment of cm into this, leaving cm empty
                         * @param cm the chunks manager to move into this
                         * @return the reference of himself
                         */
                        ChunksManager& operator=(ChunksManager && cm);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
