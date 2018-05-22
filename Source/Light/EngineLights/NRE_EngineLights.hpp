
    /**
     * @file NRE_EngineLights.hpp
     * @brief Declaration of Engine's Light's Object : EngineLights
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
             * @class EngineLights
             * @brief Light's Object : Manage the engine's lighting by regrouping all light's source
             */
            class EngineLights {
                public:
                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//
                        static void init();
                        static void free();
                        static void push_back(Light l);

                private:
                    static std::vector<Light>* lights;
            };

        };
    };
