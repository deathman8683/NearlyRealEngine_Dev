
    /**
     * @file NRE_AdvancedDate.hpp
     * @brief Declaration of Engine's Time's Object : AdvancedDate
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../Date/NRE_Date.hpp"

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
             * @class AdvancedDate
             * @brief Time's Object : A date and a precise time in ms
             */
            class AdvancedDate : public Date {
                private:
                    GLint ms;   /**< The date in ms */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        AdvancedDate();

                    //## Copy-Constructor ##//
                        /**
                         * Copy t into this
                         * @param t the advanced date to copy the content
                         */
                        AdvancedDate(AdvancedDate const& t);

                    //## Move-Constructor ##//
                        /**
                         * Move t into this, leaving t empty
                         * @param t the advanced date to move
                         */
                        AdvancedDate(AdvancedDate && t);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * AdvancedDate Deconstructor
                         */
                        virtual ~AdvancedDate();

                    //## Getter ##//
                        /**
                         * Ms getter
                         * @return the date in ms
                         */
                        GLint const& getMs() const;

                    //## Setter ##//
                        /**
                         * Ms setter
                         * @param t the new ms value
                         */
                        void setMs(GLint const& t);

                    //## Methods ##//
                        /**
                         * Update the date with an increment
                         * @param increment the increment to add
                         */
                        virtual void update(GLint const& increment);
                        /**
                         * Convert the ms value into a date
                         */
                        void convertMs();

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of t into this
                         * @param t the exception to copy into this
                         * @return the reference of himself
                         */
                        AdvancedDate& operator=(AdvancedDate const& t);
                        /**
                         * Move assigment of t into this, leaving t empty
                         * @param t the exception to move into this
                         * @return the reference of himself
                         */
                        AdvancedDate& operator=(AdvancedDate && t);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
