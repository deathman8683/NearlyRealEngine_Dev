
    /**
     * @file NRE_RegionsManager.hpp
     * @brief Declaration of Engine's World's Object : RegionsManager
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

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

            /**
             * @class RegionsManager
             * @brief World's Object : Manage regions, manage saving and loading for chunks into region
             */
            class RegionsManager {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        RegionsManager();

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
