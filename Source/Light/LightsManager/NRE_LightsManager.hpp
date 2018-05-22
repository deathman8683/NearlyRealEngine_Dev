
    /**
     * @file NRE_LightsManager.hpp
     * @brief Declaration of Engine's Light's Object : LightsManager
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_Light.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace Light
         * @brief Engine's Light Module
         */
        namespace Light {

            /**
             * @class LightsManager
             * @brief Light's Object : Manage the engine's lighting by regrouping all light's source
             */
            class LightsManager {
                public:
                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//
                        static void init();
                        static void free();
                        static void push_back(Light && l);

                private:
                    static std::vector<Light>* lights;
            };

        };
    };
