
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
         * @namespace Camera
         * @brief Engine's Camera Module
         */
        namespace Camera {

            /**
             * @class Mouse
             * @brief Input's Object : A particular input system
             */
            class Mouse : public KeyBinder {
                private:
                    Maths::Point2D<unsigned short int> click;   /**< The last click position */
                    Maths::Point2D<unsigned short int> cursor;  /**< The cursor position */
                    NREfloat sensitivity;                       /**< The mouse sensitivity */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Mouse();
                        /**
                         * Construct a mouse with a base attributes
                         * @param click       the mouse's click position
                         * @param cursor      the mouse's cursor position
                         * @param sensitivity the mouse's sensitivity
                         */
                        Mouse(Maths::Point2D<unsigned short int> const& click, Maths::Point2D<unsigned short int> const& cursor, NREfloat const& sensitivity);

                    //## Copy-Constructor ##//
                        /**
                         * Copy m into this
                         * @param m the mouse to copy the content
                         */
                        Mouse(Mouse const& m);

                    //## Move-Constructor ##//
                        /**
                         * Move m into this, leaving m empty
                         * @param m the mouse to move
                         */
                        Mouse(Mouse && m);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * Mouse Deconstructor
                         */
                        virtual ~Mouse();

                    //## Getter ##//
                        /**
                         * CLick getter
                         * @return the last click's position
                         */
                        Maths::Point2D<unsigned short int> const& getClick() const;
                        /**
                         * Cursor getter
                         * @return the cursor's position
                         */
                        Maths::Point2D<unsigned short int> const& getCursor() const;
                        /**
                         * sensitivity getter
                         * @return the mouse's sensitivity
                         */
                        NREfloat const& getSensitivity() const;

                    //## Setter ##//
                        /**
                         * Click setter
                         * @param p the new click's position
                         */
                        void setClick(Maths::Point2D<unsigned short int> const& p);
                        /**
                         * Cursor setter
                         * @param p the new cursor's position
                         */
                        void setCursor(Maths::Point2D<unsigned short int> const& p);
                        /**
                         * sensitivity setter
                         * @param s the new sensitivity value
                         */
                        void setSensitivity(NREfloat const& s);

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of m into this
                         * @param m the mouse to copy into this
                         * @return the reference of himself
                         */
                        Mouse& operator=(Mouse const& m);
                        /**
                         * Move assigment of m into this, leaving m empty
                         * @param m the mouse to move into this
                         * @return the reference of himself
                         */
                        Mouse& operator=(Mouse && m);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
                    static unsigned int NUM_BUTTONS;        /**< Number of buttons in a mouse */
                    static NREfloat DEFAULT_SENSITIVITY;    /**< The default mouse's sensitivity */
            };

            /**
             * Outstream operation for Mouse
             * @param stream the out stream to add the mouse m
             * @param m the mouse to add in the stream
             * @return the modified outstream
             */
            inline std::ostream& operator<<(std::ostream &stream, Mouse const& m) {
                stream << KeyBinder(m) << "(" << m.getClick() << "," << m.getCursor() << "," << m.getSensitivity() << ")" << std::endl;
                return stream;
            }
        };
    };
