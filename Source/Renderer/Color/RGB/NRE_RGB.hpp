
    /**
     * @file NRE_RGB.hpp
     * @brief Declaration of Engine's Color's Object : RGB
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

            class HSL;

            /**
             * @class RGB
             * @brief Color's Object : RGB color system : Red - Green - Blue
             */
            class RGB {
                protected:
                    GLubyte r;
                    GLubyte g;
                    GLubyte b;

                public:
                    //## Constructor ##//
                    RGB();
                    RGB(GLubyte const& r, GLubyte const& g, GLubyte const& b);

                    //## Copy-Constructor ##//
                    RGB(RGB const& color);

                    //## Convertor ##//
                    RGB(HSL const& color);

                    //## Deconstructor ##//
                    virtual ~RGB();

                    //## Getter ##//
                    GLubyte const& getR() const;
                    GLubyte const& getG() const;
                    GLubyte const& getB() const;

                    //## Setter ##//
                    void setR(GLubyte const& value);
                    void setG(GLubyte const& value);
                    void setB(GLubyte const& value);

                    //## Methods ##//
                    virtual NREfloat distance(RGB const& c = {DEFAULT_R, DEFAULT_G, DEFAULT_B}) const;
                    virtual NREfloat distanceSquared(RGB const& c = {DEFAULT_R, DEFAULT_G, DEFAULT_B}) const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//
                    virtual RGB& operator+=(RGB const& c);
                    virtual RGB& operator-=(RGB const& c);

                    //## Arithmetic Operator ##//
                    virtual RGB operator+(RGB const& c);
                    virtual RGB operator-(RGB const& c);
                    virtual RGB operator-();

                    //## Comparison Operator ##//
                    virtual bool operator==(RGB const& c);
                    virtual bool operator!=(RGB const& c);
                    virtual bool operator<(RGB const& c);
                    virtual bool operator>(RGB const& c);
                    virtual bool operator<=(RGB const& c);
                    virtual bool operator>=(RGB const& c);

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                protected:
                    static GLubyte DEFAULT_R;
                    static GLubyte DEFAULT_G;
                    static GLubyte DEFAULT_B;
            };

            std::ostream& operator<<(std::ostream &stream, RGB const& c);

        };
    };
