
    /**
     * @file NRE_Region.hpp
     * @brief Declaration of Engine's World's Object : Region
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include <stack>
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
                    std::string path;
                    std::stack<Chunk*> chunk;

                public:
                    //## Constructor ##//
                    Region();
                    Region(std::string const& path);
                    Region(Chunk *chunk);

                    //## Copy-Constructor ##//
                    Region(Region const& reg);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~Region();

                    //## Getter ##//
                    std::string const& getPath() const;
                    std::stack<Chunk*> const& getChunk() const;

                    //## Setter ##//
                    void setPath(std::string const& path);
                    void setChunk(std::stack<Chunk*> const& chunk);

                    //## Methods ##//
                    bool isEmpty() const;
                    void save();
                    void load(World* w);
                    void createTable(std::fstream &chunkFile);
                    void add(Chunk *chunk);

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
