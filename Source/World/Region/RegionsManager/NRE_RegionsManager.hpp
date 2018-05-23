
    /**
     * @file NRE_RegionsManager.hpp
     * @brief Declaration of Engine's World's Object : RegionsManager
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include <unordered_map>
    #include "../NRE_Region.hpp"

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
             * @class RegionsManager
             * @brief World's Object : Manage regions, manage saving and loading for chunks into region
             */
            class RegionsManager {
                private:
                    World* w;
                    std::unordered_map<Maths::Point2D<GLint>, Region*> saveMap;
                    std::unordered_map<Maths::Point2D<GLint>, Region*> loadMap;

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        RegionsManager() = delete;
                        RegionsManager(World* w);

                    //## Copy-Constructor ##//
                        /**
                         * Copy rm into this
                         * @param rm the regions manager to copy the content
                         */
                        RegionsManager(RegionsManager const& rm);

                    //## Move-Constructor ##//
                        /**
                         * Move rm into this, leaving rm empty
                         * @param rm the regions manager to move
                         */
                        RegionsManager(RegionsManager && rm);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * RegionsManager Deconstructor
                         */
                        ~RegionsManager();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Add a chunk to the load map, construct region on fly if necessary
                         * @param chunk the chunk to add
                         */
                        void addChunkToLoad(Chunk *chunk);
                        /**
                         * Add a chunk to the save map, construct region on fly if necessary
                         * @param chunk the chunk to add
                         */
                        void addChunkToSave(Chunk *chunk);
                        /**
                         * Add a chunk with different coordinates to the save map, construct region on fly if necessary
                         * @param chunk the chunk to add
                         * @param coord the chunk's coordinates used when the chunk will be saved
                         */
                        void addChunkToSave(Chunk *chunk, Maths::Point2D<GLint> const& coord);
                        /**
                         * Update the load map, process the first chunk in the map
                         */
                        void updateLoadMap();
                        /**
                         * Update the save map, process the first chunk in the map
                         */
                        void updateSaveMap();
                        /**
                         * Empty the load map, process all chunk in the map
                         */
                        void emptyLoadMap();
                        /**
                         * Empty the save map, process all chunk in the map
                         */
                        void emptySaveMap();
                        /**
                         * Flush the load map, just erase them from the map
                         */
                        void flushLoadMap();
                        /**
                         * Flush the save map, just erase them from the map
                         */
                        void flushSaveMap();

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of rm into this
                         * @param rm the regions manager to copy into this
                         * @return the reference of himself
                         */
                        RegionsManager& operator=(RegionsManager const& rm);
                        /**
                         * Move assigment of rm into this, leaving rm empty
                         * @param rm the regions manager to move into this
                         * @return the reference of himself
                         */
                        RegionsManager& operator=(RegionsManager && rm);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
