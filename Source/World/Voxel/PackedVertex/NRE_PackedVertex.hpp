
    /**
     * @file NRE_PackedVertex.hpp
     * @brief Declaration of Engine's World's Object : PackedVertex
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../../Generic/NRE_Type.hpp"
    #include "../../../Maths/NRE_Maths.hpp"
    #include "../../../Renderer/Color/RGB/NRE_RGB.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace Voxel
         * @brief Engine's World's Module
         */
        namespace World {

            /**
             * @class PackedVertex
             * @brief World's Object : A vertex with his attributes : Color + Normal
             */
            class PackedVertex : public Maths::Point3D<GLint>, public Maths::Vector3D<GLbyte>, public Color::RGB {
                private:
                    size_t nCode;
                    size_t cCode;

                public:
                    //## Constructor ##//
                    PackedVertex();
                    PackedVertex(Maths::Point3D<GLint> const& p, Maths::Vector3D<GLbyte> const& n, Color::RGB const& c, size_t const& nCode, size_t const& cCode);

                    //## Copy-Constructor ##//
                    PackedVertex(PackedVertex const& p);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~PackedVertex();

                    //## Getter ##//
                    size_t const& getNCode() const;
                    size_t const& getCCode() const;

                    //## Setter ##//
                    void setNCode(size_t const& code);
                    void setCCode(size_t const& code);

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//
                    bool operator==(PackedVertex const& p) const;
                    bool operator<(PackedVertex const& p) const;
                    bool operator>(PackedVertex const& p) const;

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };


    namespace std {
        template <>
        class hash<NRE::World::PackedVertex> {
            public:
                size_t operator()(NRE::World::PackedVertex const& p) const
                {
                    size_t hV = p.NRE::Maths::Point3D<GLint>::getZ() * 100'000'000
                              + p.NRE::Maths::Point3D<GLint>::getY() * 1'000'000
                              + p.NRE::Maths::Point3D<GLint>::getX() * 10'000
                              + p.getNCode() * 1'000
                              + p.getCCode();
                    return hV;
                }
        };
    };
