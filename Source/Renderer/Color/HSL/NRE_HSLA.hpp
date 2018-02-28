
    /**
     * @file NRE_HSLA.hpp
     * @brief Declaration of Engine's Color's Object : HSLA
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../../Generic/NRE_Type.hpp"
    #include "NRE_HSL.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace Color
         * @brief <Module_Desc>
         */
        namespace Color {

            class RGBA;

            /**
             * @class HSLA
             * @brief Color's Object : HSLA color system : Hue - Saturation - Luminosity - Alpha
             */
            class HSLA : public HSL {
                private:
                    NREfloat a;

                public:
                    //## Constructor ##//
                    HSLA();
                    HSLA(unsigned short int const& h, NREfloat const& s, NREfloat const& l, NREfloat const& a);
                    HSLA(HSL const& color, NREfloat const& a);

                    //## Copy-Constructor ##//
                    HSLA(HSLA const& color);

                    //## Convertor ##//
                    HSLA(RGBA const& color);

                    //## Deconstructor ##//
                    ~HSLA();

                    //## Getter ##//
                    NREfloat const& getA() const;

                    //## Setter ##//
                    void setA(NREfloat const& value);

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//
                    HSLA& operator+=(HSLA const& c);
                    HSLA& operator-=(HSLA const& c);

                    //## Arithmetic Operator ##//
                    HSLA operator+(HSLA const& c);
                    HSLA operator-(HSLA const& c);
                    HSLA operator-();

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
                    static NREfloat DEFAULT_A;
            };

            inline std::ostream& operator<<(std::ostream &stream, HSLA const& c) {
                stream << "(" << c.getH() << "," << c.getS() << "," << c.getL() << "," << c.getA() << ")";
                return stream;
            }
            
        };
    };
