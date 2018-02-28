
    /**
     * @file NRE_RGBA.hpp
     * @brief Declaration of Engine's Color's Object : RGBA
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../../Generic/NRE_Type.hpp"
    #include "NRE_RGB.hpp"

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

            class HSLA;

            /**
             * @class RGBA
             * @brief Color's Object : RGBA color system : Red - Green - Blue - Alpha
             */
            class RGBA : public RGB {
                private:
                    GLubyte a;

                public:
                    //## Constructor ##//
                    RGBA();
                    RGBA(GLubyte const& r, GLubyte const& g, GLubyte const& b, GLubyte const& a);
                    RGBA(RGB const& color, GLubyte const& a);

                    //## Copy-Constructor ##//
                    RGBA(RGBA const& color)

                    //## Convertor ##//
                    RGBA(HSLA const& color);

                    //## Deconstructor ##//
                    ~RGBA();

                    //## Getter ##//
                    GLubyte const& getA() const;

                    //## Setter ##//
                    void setA(GLubyte const& value);

                    //## Methods ##//
                    NREfloat distance(RGBA const& c = {RGB::DEFAULT_R, RGB::DEFAULT_G, RGB::DEFAULT_B, DEFAULT_A}) const;
                    NREfloat distanceSquared(RGBA const& c = {RGB::DEFAULT_R, RGB::DEFAULT_G, RGB::DEFAULT_B, DEFAULT_A}) const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//
                    RGBA& operator+=(RGBA const& c);
                    RGBA& operator-=(RGBA const& c);

                    //## Arithmetic Operator ##//
                    RGBA operator+(RGBA const& c);
                    RGBA operator-(RGBA const& c);
                    RGBA operator-();

                    //## Comparison Operator ##//
                    bool operator==(RGBA const& c);
                    bool operator!=(RGBA const& c);
                    bool operator<(RGBA const& c);
                    bool operator>(RGBA const& c);
                    bool operator<=(RGBA const& c);
                    bool operator>=(RGBA const& c);

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
                    static GLubyte DEFAULT_A;
            };

            inline std::ostream& operator<<(std::ostream &stream, RGBA const& c);

        };
    };
