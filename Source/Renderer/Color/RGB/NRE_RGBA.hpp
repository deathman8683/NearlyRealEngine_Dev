
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

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        RGBA();
                        /**
                         * Construct the color from their base value
                         * @param r the new red value
                         * @param g the new green value
                         * @param b the new blue value
                         * @param a the new alpha value
                         */
                        RGBA(GLubyte const& r, GLubyte const& g, GLubyte const& b, GLubyte const& a);

                    //## Copy-Constructor ##//
                        /**
                         * Copy color into this
                         * @param color the RGBA color to copy the content
                         */
                        RGBA(RGBA const& color);

                    //## Move-Constructor ##//
                        /**
                         * Move color into this, leaving color empty
                         * @param color the RGBA color to move
                         */
                        RGBA(RGBA && color);

                    //## Convertor ##//
                        /**
                         * Convert a HSLA color into the RGBA color
                         * @param color the color to convert
                         */
                        RGBA(HSLA const& color);
                        /**
                         * Convert a base RGB color into a RGBA color with a default a value
                         * @param color the RGB color to convert
                         */
                        RGBA(RGB const& color);
                        /**
                         * Convert a base RGB color into a RGBA color with a passed a value
                         * @param color the RGB color to convert
                         * @param a     the new a value
                         */
                        RGBA(RGB const& color, GLubyte const& a);

                    //## Deconstructor ##//
                        /**
                         * RGBA Deconstructor
                         */
                        ~RGBA();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of color into this
                         * @param color the RGBA color to copy into this
                         * @return the reference of himself
                         */
                        RGBA& operator=(RGBA const& color);
                        /**
                         * Move assigment of color into this, leaving color empty
                         * @param color the RGBA color to move into this
                         * @return the reference of himself
                         */
                        RGBA& operator=(RGBA && color);

                    //## Shortcut Operator ##//
                        /**
                         * Add c to this
                         * @param c the color to add
                         * @return the reference of himself
                         */
                        RGBA& operator+=(RGBA const& c);
                        /**
                         * Subtract c to this
                         * @param c the color to subtract
                         * @return the reference of himself
                         */
                        RGBA& operator-=(RGBA const& c);

                    //## Arithmetic Operator ##//
                        /**
                         * Compute the color resulting in the addition of c into this
                         * @param c the color to add
                         * @return the newly computed color
                         */
                        RGBA operator+(RGBA const& c);
                        /**
                         * Compute the color resulting in the subtraction of c into this
                         * @param c the color to subtract
                         * @return the newly computed color
                         */
                        RGBA operator-(RGBA const& c);
                        /**
                         * Compute the negative color of this
                         * @return the newly negative color of this
                         */
                        RGBA operator-();

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
                    static GLubyte DEFAULT_R;   /**< default red value */
                    static GLubyte DEFAULT_G;   /**< default green value */
                    static GLubyte DEFAULT_B;   /**< default blue value */
                    static GLubyte DEFAULT_A;   /**< default alpha value */
            };

        };
    };
