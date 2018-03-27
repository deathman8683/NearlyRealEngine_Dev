
    /**
     * @file NRE_RGB.hpp
     * @brief Declaration of Engine's Color's Object : RGB
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../../Generic/NRE_Type.hpp"
    #include "../../../Maths/NRE_Maths.hpp"

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

            class HSL;

            /**
             * @class RGB
             * @brief Color's Object : RGB color system : Red - Green - Blue
             */
            class RGB : public Maths::Vector3D<GLubyte> {
                protected:

                public:
                    //## Constructor ##//
                    RGB();
                    RGB(GLubyte const& r, GLubyte const& g, GLubyte const& b);

                    //## Copy-Constructor ##//
                    RGB(RGB const& color);

                    //## Convertor ##//
                    RGB(HSL const& color);

                    //## Deconstructor ##//
                    ~RGB();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//
                    RGB& operator+=(RGB const& c);
                    RGB& operator-=(RGB const& c);

                    //## Arithmetic Operator ##//
                    RGB operator+(RGB const& c);
                    RGB operator-(RGB const& c);
                    RGB operator-();

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                protected:
                    static GLubyte DEFAULT_R;
                    static GLubyte DEFAULT_G;
                    static GLubyte DEFAULT_B;
            };

        };
    };
