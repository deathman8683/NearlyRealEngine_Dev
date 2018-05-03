
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
                    std::unordered_map<std::string, GLint> locations;   /**< A HashMap to store uniform name and their locations */

                public:
                    //## Constructor ##//
                        /**
                         * Default Construct
                         */
                        ShaderMap();
                        /**
                         * Construct the shader map with a default size for the hashmap
                         * @param n the minimum size for the hashmap on construction
                         */
                        ShaderMap(size_t const& n);

                    //## Copy-Constructor ##//
                        /**
                         * Copy map into this
                         * @param map the shader map to copy the content
                         */
                        ShaderMap(ShaderMap const& map);

                    //## Move-Constructor ##//
                        /**
                         * Move map into this, leaving map empty
                         * @param map the shader map to move
                         */
                        ShaderMap(ShaderMap && map);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * ShaderMap Deconstructor
                         */
                        ~ShaderMap();

                    //## Getter ##//
                        /**
                         * Specific Location getter
                         * @param  key the uniform name to get his location
                         * @return     the uniform location
                         */
                        GLint const& getLocation(std::string const& key) const;

                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Used to fill the hashmap with a new uniform location from his name and a shader program id
                         * @param id  the shader program id
                         * @param key the uniform name
                         */
                        void queryLocation(GLuint const& id, std::string const& key);
                        /**
                         * Return the Shader map size, the hashmap size
                         * @return the shader map size
                         */
                        size_t const size() const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of map into this
                         * @param map the shader map to copy into this
                         * @return the reference of himself
                         */
                        ShaderMap& operator=(ShaderMap const& map);
                        /**
                         * Move assigment of map into this, leaving map empty
                         * @param map the shader map to move into this
                         * @return the reference of himself
                         */
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
