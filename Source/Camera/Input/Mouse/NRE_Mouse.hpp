
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
                    virtual Maths::Point2D<unsigned short int> const& getClick() const;
                    virtual Maths::Point2D<unsigned short int> const& getCursor() const;
                    virtual NREfloat const& getSensitivity() const;

                    //## Setter ##//
                    virtual void setClick(Maths::Point2D<unsigned short int> const& p);
                    virtual void setCursor(Maths::Point2D<unsigned short int> const& p);
                    virtual void setSensitivity(NREfloat const& s);

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

            std::ostream& operator<<(std::ostream &stream, Mouse const& m);

        };
    };
