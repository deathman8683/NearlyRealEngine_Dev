
    /**
     * @file NRE_LightsManager.hpp
     * @brief Declaration of Engine's Light's Object : LightsManager
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_Light.hpp"
    #include "../DirectionnalLight/NRE_DirectionnalLight.hpp"
    #include "../PointLight/NRE_PointLight.hpp"

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
                        /**
                         * Light getter
                         * @param  index the light's index
                         * @return       the corresponding light
                         */
                        static Light& getLight(GLuint const& index);
                        /**
                         * Size getter
                         * @return the light's array size
                         */
                        static size_t const getSize();

                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Initialize the light's manager
                         */
                        static void init();
                        /**
                         * Desallocate the light's manager
                         */
                        static void free();
                        /**
                         * Push back a new light into the manager
                         * @param l the light to add
                         */
                        static void push_back(Light && l);

                private:
                    static std::vector<Light>* lights;  /**< The manager light's array */
            };

        };
    };
