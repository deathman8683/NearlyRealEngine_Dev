
    /**
     * @file NRE_Mouse.hpp
     * @brief Declaration of Engine's Input's Object : Mouse
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../../Generic/NRE_Type.hpp"
    #include "../KeyBinder/NRE_KeyBinder.hpp"
    #include "../../../Maths/NRE_Maths.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace Input
         * @brief Engine's Input Module
         */
        namespace Input {

            /**
             * @class Mouse
             * @brief Input's Object : A particular input system
             */
            class Mouse : public KeyBinder {
                private:
                    Maths::Point2D<unsigned short int> click;
                    Maths::Point2D<unsigned short int> cursor;
                    NREfloat sensitivity;

                public:
                    //## Constructor ##//
                    Mouse();
                    Mouse(std::string const& path);
                    Mouse(Maths::Point2D<unsigned short int> const& click, Maths::Point2D<unsigned short int> const& cursor, NREfloat const& sensitivity);

                    //## Copy-Constructor ##//
                    Mouse(Mouse const& m);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    virtual ~Mouse();

                    //## Getter ##//
                    Maths::Point2D<unsigned short int> const& getClick() const;
                    Maths::Point2D<unsigned short int> const& getCursor() const;
                    NREfloat const& getSensitivity() const;

                    //## Setter ##//
                    void setClick(Maths::Point2D<unsigned short int> const& p);
                    void setCursor(Maths::Point2D<unsigned short int> const& p);
                    void setSensitivity(NREfloat const& s);

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
                    static unsigned int NUM_BUTTONS;
                    static NREfloat DEFAULT_SENSITIVITY;
            };

            inline std::ostream& operator<<(std::ostream &stream, Mouse const& m) {
                stream << KeyBinder(m) << "(" << m.getClick() << "," << m.getCursor() << "," << m.getSensitivity() << ")" << std::endl;
                return stream;
            }
        };
    };
