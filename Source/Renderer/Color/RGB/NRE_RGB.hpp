
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
                        /**
                         * Default Constructor
                         */
                        RGB();
                        /**
                         * Construct the color from their base value
                         * @param r the new red value
                         * @param g the new green value
                         * @param b the new blue value
                         */
                        RGB(GLubyte const& r, GLubyte const& g, GLubyte const& b);

                    //## Copy-Constructor ##//
                        /**
                         * Copy color into this
                         * @param color the RGB color to copy the content
                         */
                        RGB(RGB const& color);

                    //## Move-Constructor ##//
                        /**
                         * Move color into this, leaving color empty
                         * @param color the RGB color to move
                         */
                        RGB(RGB && color);

                    //## Convertor ##//
                        /**
                         * Convert a HSL color into the RGB color
                         * @param color the color to convert
                         */
                        RGB(HSL const& color);

                    //## Deconstructor ##//
                        /**
                         * HSL Deconstructor
                         */
                        ~RGB();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of color into this
                         * @param color the RGB color to copy into this
                         * @return the reference of himself
                         */
                        RGB& operator=(RGB const& color);
                        /**
                         * Move assigment of color into this, leaving color empty
                         * @param color the RGB color to move into this
                         * @return the reference of himself
                         */
                        RGB& operator=(RGB && color);

                    //## Shortcut Operator ##//
                        /**
                         * Add c to this
                         * @param c the color to add
                         * @return the reference of himself
                         */
                        RGB& operator+=(RGB const& c);
                        /**
                         * Subtract c to this
                         * @param c the color to subtract
                         * @return the reference of himself
                         */
                        RGB& operator-=(RGB const& c);

                    //## Arithmetic Operator ##//
                        /**
                         * Compute the color resulting in the addition of c into this
                         * @param c the color to add
                         * @return the newly computed color
                         */
                        RGB operator+(RGB const& c);
                        /**
                         * Compute the color resulting in the subtraction of c into this
                         * @param c the color to subtract
                         * @return the newly computed color
                         */
                        RGB operator-(RGB const& c);
                        /**
                         * Compute the negative color of this
                         * @return the newly negative color of this
                         */
                        RGB operator-();

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                protected:
                    static GLubyte DEFAULT_R;   /**< default red value */
                    static GLubyte DEFAULT_G;   /**< default green value */
                    static GLubyte DEFAULT_B;   /**< default blue value */
            };

        };
    };
