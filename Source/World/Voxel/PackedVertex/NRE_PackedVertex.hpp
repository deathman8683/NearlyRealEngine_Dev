
    /**
     * @file NRE_PackedVertex.hpp
     * @brief Declaration of Engine's Voxel's Object : PackedVertex
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
         * @brief Engine's Voxel's Type's Module
         */
        namespace Voxel {

            /**
             * @class PackedVertex
             * @brief Voxel's Object : A vertex with his attributes : Color + Normal
             */
            class PackedVertex : public Maths::Point3D<GLint>, public Maths::Vector<GLbyte>, public Color::RGB {
                private:
                    size_t nCode;
                    size_t cCode;

                public:
                    //## Constructor ##//
                    PackedVertex()
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
                    void setNCode(size_t const& code) const;
                    void setCCode(size_t const& code) const;

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//
                    bool operator<(PackedVertex const& p);
                    bool operator>(PackedVertex const& p);

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

            namespace std {
                class hash<PackedVertex> {
                    public:
                        size_t operator()(PackedVertex const& p) const;
                }
            };

        };
    };
