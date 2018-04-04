
    /**
     * @file NRE_Material.hpp
     * @brief Declaration of Engine's Renderer's Object : Material
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../Maths/NRE_Maths.hpp"
    #include "../../Generic/NRE_Type.hpp"

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
                    Maths::Vector3D<NREfloat> albedo;
                    NREfloat metallic;
                    NREfloat roughness;

                public:
                    //## Constructor ##//
                    Material();
                    Material(Maths::Vector3D<NREfloat> const& albedo, NREfloat const& metallic, NREfloat const& roughness);

                    //## Copy-Constructor ##//
                    Material(Material const& mat);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~Material();

                    //## Getter ##//
                    Maths::Vector3D<NREfloat> const& getAlbedo() const;
                    NREfloat const& getMetallic() const;
                    NREfloat const& getRoughness() const;
                    NREfloat* const getMetallicValue();
                    NREfloat* const getRoughnessValue();

                    //## Setter ##//
                    void setAlbedo(Maths::Vector3D<NREfloat> const& albedo);
                    void setMetallic(NREfloat const& value);
                    void setRoughness(NREfloat const& value);

                    //## Methods ##//

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
