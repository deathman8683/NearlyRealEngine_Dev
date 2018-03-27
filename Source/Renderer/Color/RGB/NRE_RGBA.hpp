
    /**
     * @file NRE_RGBA.hpp
     * @brief Declaration of Engine's Color's Object : RGBA
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

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
            class RGBA : public Maths::Vector4D<GLubyte> {
                private:
                    GLubyte a;

                public:
                    //## Constructor ##//
                    RGBA();
                    RGBA(GLubyte const& r, GLubyte const& g, GLubyte const& b, GLubyte const& a);
                    RGBA(RGB const& color, GLubyte const& a);

                    //## Copy-Constructor ##//
                    RGBA(RGBA const& color);

                    //## Convertor ##//
                    RGBA(HSLA const& color);

                    //## Deconstructor ##//
                    ~RGBA();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//

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

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
                    static GLubyte DEFAULT_R;
                    static GLubyte DEFAULT_G;
                    static GLubyte DEFAULT_B;
                    static GLubyte DEFAULT_A;
            };

        };
    };
