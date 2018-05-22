
    /**
     * @file NRE_Material.hpp
     * @brief Declaration of Engine's Renderer's Object : Material
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../Maths/NRE_Maths.hpp"
    #include "../../Generic/NRE_Type.hpp"
    #include "../../GL_Wrapper/BufferObject/Texture2D/NRE_Texture2D.hpp"

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
             * @class Material
             * @brief Renderer's Object : A material, grouping some properties use in PBR shader
             */
            class Material {
                private:
                    NREfloat metallic;                  /**< The material metallic aspect */
                    NREfloat roughness;                 /**< The material roughness */
                    GL::Texture2D* albedo;
                    GL::Texture2D* normal;

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Material();
                        /**
                         * Construct a material from his different attributes
                         * @param metallic  the new material metallic aspect
                         * @param roughness the new material roughness
                         * @param path      the path to the material's textures
                         */
                        Material(NREfloat const& metallic, NREfloat const& roughness, std::string const& path);

                    //## Copy-Constructor ##//
                        /**
                         * Copy mat into this
                         * @param mat the material to copy the content
                         */
                        Material(Material const& mat);

                    //## Move-Constructor ##//
                        /**
                         * Move mat into this, leaving mat empty
                         * @param mat the material to move
                         */
                        Material(Material && mat);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * Material Deconstructor
                         */
                        ~Material();

                    //## Getter ##//
                        /**
                         * Metallic Aspect getter
                         * @return the material metallic aspect
                         */
                        NREfloat const& getMetallic() const;
                        /**
                         * Roughness getter
                         * @return the material roughness
                         */
                        NREfloat const& getRoughness() const;
                        GL::Texture2D const& getAlbedo() const;
                        GL::Texture2D const& getNormal() const;
                        /**
                         * Metallic pointer getter
                         * @return the material metallic pointer, used with uniform in shader
                         */
                        NREfloat* const getMetallicValue();
                        /**
                         * Roughness pointer getter
                         * @return the material roughness pointer, used with uniform in shader
                         */
                        NREfloat* const getRoughnessValue();

                    //## Setter ##//
                        /**
                         * Metallic Aspect setter
                         * @param value the new metallic aspect value
                         */
                        void setMetallic(NREfloat const& value);
                        /**
                         * Roughness setter
                         * @param value the new roughness value
                         */
                        void setRoughness(NREfloat const& value);

                    //## Methods ##//
                        void freeTextures();

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of mat into this
                         * @param mat the material to copy into this
                         * @return the reference of himself
                         */
                        Material& operator=(Material const& mat);
                        /**
                         * Move assigment of mat into this, leaving mat empty
                         * @param mat the material to move into this
                         * @return the reference of himself
                         */
                        Material& operator=(Material && mat);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
