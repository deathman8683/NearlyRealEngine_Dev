
    /**
     * @file NRE_Region.hpp
     * @brief Declaration of Engine's World's Object : Region
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include <queue>
    #include "../Chunk/NRE_Chunk.hpp"

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
             * @class Region
             * @brief World's Object : Manage the saving/loading of a collection of chunk
             */
            class Region {
                private:
                    std::string path;                                           /**< The Region file path */
                    std::queue<std::pair<Maths::Point2D<GLint>, Chunk*>> chunk; /**< The Region chunk queue */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Region() = delete;
                        /**
                         * Construct a region from a path to region file
                         * @param path the path to a region file
                         */
                        Region(std::string const& path);
                        /**
                         * Construct a region from a chunk to add directly in the queue
                         * @param chunk the chunk to add directly, used to get the region path
                         */
                        Region(Chunk *chunk);

                    //## Copy-Constructor ##//
                        /**
                         * Copy reg into this
                         * @param reg the region to copy the content
                         */
                        Region(Region const& reg);

                    //## Move-Constructor ##//
                        /**
                         * Move reg into this, leaving reg empty
                         * @param reg the region to move
                         */
                        Region(Region && reg);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * Region Deconstructor
                         */
                        ~Region();

                    //## Getter ##//
                        /**
                         * Path getter
                         * @return the region path value
                         */
                        std::string const& getPath() const;

                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Test if the chunk queue is empty
                         * @return if the chunk queue is empty or not
                         */
                        bool isEmpty() const;
                        /**
                         * Save all chunk in the queue
                         */
                        void save();
                        /**
                         * Load all chunk in the queue
                         * @param w the world used for chunk border computation
                         */
                        void load(World* w);
                        /**
                         * Create the lookup table in the region file
                         */
                        void createTable();
                        /**
                         * Add a chunk in the queue
                         * @param chunk the chunk to add
                         */
                        void add(Chunk *chunk);
                        /**
                         * Add a chunk with different coordinates, used when the chunk has to be shifted
                         * @param chunk the chunk to add
                         * @param coord the chunk's coord to set in the queue
                         */
                        void add(Chunk *chunk, Maths::Point2D<GLint> const& coord);

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of reg into this
                         * @param reg the region to copy into this
                         * @return the reference of himself
                         */
                        Region& operator=(Region const& reg);
                        /**
                         * Move assigment of reg into this, leaving reg empty
                         * @param reg the region to move into this
                         * @return the reference of himself
                         */
                        Region& operator=(Region && reg);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
