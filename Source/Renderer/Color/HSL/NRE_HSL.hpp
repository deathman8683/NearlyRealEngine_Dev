
    /**
     * @file NRE_HSL.hpp
     * @brief Declaration of Engine's Color's Object : HSL
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../../Generic/NRE_Type.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace Color
         * @brief Engine's Color's Managment System
         */
        namespace Color {

            class RGB;

            /**
             * @class HSL
             * @brief Color's Object : HSL color system : Hue - Saturation - Luminosity
             */
            class HSL {
                protected:
                    unsigned short int h;
                    NREfloat s;
                    NREfloat l;

                public:
                    //## Constructor ##//
                    HSL();
                    HSL(unsigned short int const& h, NREfloat const& s, NREfloat const& l);

                    //## Copy-Constructor ##//
                    HSL(HSL const& color);

                    //## Convertor ##//
                    HSL(RGB const& color);

                    //## Deconstructor ##//
                    ~HSL();

                    //## Getter ##//
                    unsigned short int const& getH() const;
                    NREfloat const& getS() const;
                    NREfloat const& getL() const;

                    //## Setter ##//
                    void setH(unsigned short int const& value);
                    void setS(NREfloat const& value);
                    void setL(NREfloat const& value);

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//
                    HSL& operator+=(HSL const& c);
                    HSL& operator-=(HSL const& c);

                    //## Arithmetic Operator ##//
                    HSL operator+(HSL const& c);
                    HSL operator-(HSL const& c);
                    HSL operator-();

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                protected:
                    static unsigned short int DEFAULT_H;
                    static NREfloat DEFAULT_S;
                    static NREfloat DEFAULT_L;
            };

            inline std::ostream& operator<<(std::ostream &stream, HSL const& c) {
                stream << "(" << c.getH() << "," << c.getS() << "," << c.getL() << ")";
                return stream;
            }
            
        };
    };
