
    /**
     * @file NRE_Date.hpp
     * @brief Declaration of Engine's Time's Object : Date
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../Generic/NRE_Type.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace Time
         * @brief Engine's Time's Module
         */
        namespace Time {

            /**
             * @class Date
             * @brief Time's Object : a simple Date : HH:MM:SS
             */
            class Date {
                private:
                    GLint h;    /**< The date's hours */
                    GLint m;    /**< The date's minutes */
                    GLint s;    /**< The date's seconds */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Date();
                        /**
                         * Construct a date with passed value
                         * @param h the date's hours value
                         * @param m the date's minutes value
                         * @param s the date's seconds value
                         */
                        Date(GLint const& h, GLint const& m, GLint const& s);
                        /**
                         * Construct a date with a time passed in ms
                         * @param time the time to convert into a date
                         */
                        Date(GLint const& time);

                    //## Copy-Constructor ##//
                        /**
                         * Copy d into this
                         * @param d the date to copy the content
                         */
                        Date(Date const& d);

                    //## Move-Constructor ##//
                        /**
                         * Move d into this, leaving d empty
                         * @param d the date to move
                         */
                        Date(Date && d);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * Date Deconstructor
                         */
                        virtual ~Date();

                    //## Getter ##//
                        /**
                         * Hours getter
                         * @return the hours value
                         */
                        GLint const& getH() const;
                        /**
                         * Minutes getter
                         * @return the minutes value
                         */
                        GLint const& getM() const;
                        /**
                         * Seconds getter
                         * @return the seconds value
                         */
                        GLint const& getS() const;

                    //## Setter ##//
                        /**
                         * Hours setter
                         * @param v the new hours value
                         */
                        void setH(GLint const& v);
                        /**
                         * Minutes setter
                         * @param v the new minutes value
                         */
                        void setM(GLint const& v);
                        /**
                         * Seconds setter
                         * @param v the new seconds value
                         */
                        void setS(GLint const& v);

                    //## Methods ##//
                        /**
                         * Convert a time in ms into a date
                         * @param time the time to convert into a date
                         */
                        void convertMs(GLint const& time);

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of d into this
                         * @param d the date to copy into this
                         * @return the reference of himself
                         */
                        Date& operator=(Date const& d);
                        /**
                         * Move assigment of d into this, leaving d empty
                         * @param d the date to move into this
                         * @return the reference of himself
                         */
                        Date& operator=(Date && d);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
