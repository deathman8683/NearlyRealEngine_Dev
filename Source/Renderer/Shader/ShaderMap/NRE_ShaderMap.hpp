
    /**
     * @file NRE_ShaderMap.hpp
     * @brief Declaration of Engine's Renderer's Object : ShaderMap
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include <unordered_map>
    #include "../../../Generic/NRE_Type.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace Renderer
         * @brief Engine's Renderer Module
         */
        namespace Renderer {
            /**
             * @class ShaderMap
             * @brief Renderer's Object : Store all uniform location efficiently
             */
            class ShaderMap {
                private:
                    std::unordered_map<std::string, GLint> locations;

                public:
                    //## Constructor ##//
                        ShaderMap();
                        ShaderMap(size_t const& n);

                    //## Copy-Constructor ##//
                        ShaderMap(ShaderMap const& map);

                    //## Move-Constructor ##//
                        ShaderMap(ShaderMap && map);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        ~ShaderMap();

                    //## Getter ##//
                        GLint const& getLocation(std::string const& key) const;

                    //## Setter ##//

                    //## Methods ##//
                        void queryLocation(GLuint const& id, std::string const& key);
                        size_t const size() const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        ShaderMap& operator=(ShaderMap const& map);
                        ShaderMap& operator=(ShaderMap && map);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
