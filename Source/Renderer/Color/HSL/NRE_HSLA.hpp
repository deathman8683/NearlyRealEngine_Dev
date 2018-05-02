
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
                    NREfloat a;     /**< The color's alpha */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        HSLA();
                        /**
                         * Construct the color from their base value
                         * @param h the new hue value
                         * @param s the new saturation value
                         * @param l the new luminosity value
                         * @param a the new alpha value
                         */
                        HSLA(unsigned short int const& h, NREfloat const& s, NREfloat const& l, NREfloat const& a);

                    //## Copy-Constructor ##//
                        /**
                         * Copy color into this
                         * @param color the HSLA color to copy the content
                         */
                        HSLA(HSLA const& color);

                    //## Move-Constructor ##//
                        /**
                         * Move color into this, leaving color empty
                         * @param color the HSLA color to move
                         */
                        HSLA(HSLA && color);

                    //## Convertor ##//
                        /**
                         * Convert a RGBA color into the HSLA color
                         * @param color the color to convert
                         */
                        HSLA(RGBA const& color);
                        /**
                         * Convert a base HSL colro into a HSLA color with a default a value
                         * @param color the HSL color to convert
                         */
                        HSLA(HSL const& color);
                        /**
                         * Convert a base HSL color into a HSLA color with a passed a value
                         * @param color the HSL color to convert
                         * @param a     the new a value
                         */
                        HSLA(HSL const& color, NREfloat const& a);

                    //## Deconstructor ##//
                        /**
                         * HSLA Deconstructor
                         */
                         ~HSLA();

                    //## Getter ##//
                        /**
                         * Alpha getter
                         * @return the alpha value
                         */
                        NREfloat const& getA() const;

                    //## Setter ##//
                        /**
                         * Alpha setter
                         * @param value the new value for a
                         */
                        void setA(NREfloat const& value);

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of color into this
                         * @param color the HSLA color to copy into this
                         * @return the reference of himself
                         */
                        HSLA& operator=(HSLA const& color);
                        /**
                         * Move assigment of color into this, leaving color empty
                         * @param color the HSLA color to move into this
                         * @return the reference of himself
                         */
                        HSLA& operator=(HSLA && color);

                    //## Shortcut Operator ##//
                        /**
                         * Add c to this
                         * @param c the color to add
                         * @return the reference of himself
                         */
                        HSLA& operator+=(HSLA const& c);
                        /**
                         * Subtract c to this
                         * @param c the color to subtract
                         * @return the reference of himself
                         */
                        HSLA& operator-=(HSLA const& c);

                    //## Arithmetic Operator ##//
                        /**
                         * Compute the color resulting in the addition of c into this
                         * @param c the color to add
                         * @return the newly computed color
                         */
                        HSLA operator+(HSLA const& c);
                        /**
                         * Compute the color resulting in the subtraction of c into this
                         * @param c the color to subtract
                         * @return the newly computed color
                         */
                        HSLA operator-(HSLA const& c);
                        /**
                         * Compute the negative color of this
                         * @return the newly negative color of this
                         */
                        HSLA operator-();

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
                    static NREfloat DEFAULT_A;  /**< default alpha value */
            };

            /**
             * Outstream operation for HSLA color
             * @param stream the out stream to add the color c
             * @param c the color to add in the stream
             * @return the modified outstream
             */
            inline std::ostream& operator<<(std::ostream &stream, HSLA const& c) {
                stream << "(" << c.getH() << "," << c.getS() << "," << c.getL() << "," << c.getA() << ")";
                return stream;
            }

        };
    };
