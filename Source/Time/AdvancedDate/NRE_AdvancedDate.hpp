
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
                    GLint ms;

                public:
                    //## Constructor ##//
                    AdvancedDate();

                    //## Copy-Constructor ##//
                    AdvancedDate(AdvancedDate const& t);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    virtual ~AdvancedDate();

                    //## Getter ##//
                    GLint const& getMs() const;

                    //## Setter ##//
                    void setMs(GLint const& t);

                    //## Methods ##//
                    virtual void update(GLint const& increment);
                    void convertMs();

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
