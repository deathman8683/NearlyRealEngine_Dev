
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
                    unsigned short int h;   /**< The color's hue */
                    NREfloat s;             /**< The color's saturation */
                    NREfloat l;             /**< The color's luminosity */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        HSL();
                        /**
                         * Construct the color from their base value
                         * @param h the new hue value
                         * @param s the new saturation value
                         * @param l the new luminosity value
                         */
                        HSL(unsigned short int const& h, NREfloat const& s, NREfloat const& l);

                    //## Copy-Constructor ##//
                        /**
                         * Copy color into this
                         * @param color the HSL color to copy the content
                         */
                        HSL(HSL const& color);

                    //## Move-Constructor ##//
                        /**
                         * Move color into this, leaving color empty
                         * @param color the HSL color to move
                         */
                        HSL(HSL && color);

                    //## Convertor ##//
                        /**
                         * Convert a RGB color into the HSL color
                         * @param color the color to convert
                         */
                        HSL(RGB const& color);

                    //## Deconstructor ##//
                        /**
                         * HSL Deconstructor
                         */
                        ~HSL();

                    //## Getter ##//
                        /**
                         * Hue getter
                         * @return the hue value
                         */
                        unsigned short int const& getH() const;
                        /**
                         * Saturation getter
                         * @return the saturation value
                         */
                        NREfloat const& getS() const;
                        /**
                         * Luminosity getter
                         * @return the luminosity value
                         */
                        NREfloat const& getL() const;

                    //## Setter ##//
                        /**
                         * Hue setter
                         * @param value the new value for h
                         */
                        void setH(unsigned short int const& value);
                        /**
                         * Saturation setter
                         * @param value the new value for s
                         */
                        void setS(NREfloat const& value);
                        /**
                         * Luminosity setter
                         * @param value the new value for l
                         */
                        void setL(NREfloat const& value);

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of color into this
                         * @param color the HSL color to copy into this
                         * @return the reference of himself
                         */
                        HSL& operator=(HSL const& color);
                        /**
                         * Move assigment of color into this, leaving color empty
                         * @param color the HSL color to move into this
                         * @return the reference of himself
                         */
                        HSL& operator=(HSL && color);

                    //## Shortcut Operator ##//
                        /**
                         * Add c to this
                         * @param c the color to add
                         * @return the reference of himself
                         */
                        HSL& operator+=(HSL const& c);
                        /**
                         * Subtract c to this
                         * @param c the color to subtract
                         * @return the reference of himself
                         */
                        HSL& operator-=(HSL const& c);

                    //## Arithmetic Operator ##//
                        /**
                         * Compute the color resulting in the addition of c into this
                         * @param c the color to add
                         * @return the newly computed color
                         */
                        HSL operator+(HSL const& c);
                        /**
                         * Compute the color resulting in the subtraction of c into this
                         * @param c the color to subtract
                         * @return the newly computed color
                         */
                        HSL operator-(HSL const& c);
                        /**
                         * Compute the negative color of this
                         * @return the newly negative color of this
                         */
                        HSL operator-();

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                protected:
                    static unsigned short int DEFAULT_H;    /**< default hue value */
                    static NREfloat DEFAULT_S;              /**< default saturation value */
                    static NREfloat DEFAULT_L;              /**< default luminosity value */
            };

            /**
             * Outstream operation for HSL color
             * @param stream the out stream to add the color c
             * @param c the color to add in the stream
             * @return the modified outstream
             */
            inline std::ostream& operator<<(std::ostream &stream, HSL const& c) {
                stream << "(" << c.getH() << "," << c.getS() << "," << c.getL() << ")";
                return stream;
            }

        };
    };
