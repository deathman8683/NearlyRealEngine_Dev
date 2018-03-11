
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
                    GLint h;
                    GLint m;
                    GLint s;

                public:
                    //## Constructor ##//
                    Date();
                    Date(GLint const& h, GLint const& m, GLint const& s);
                    Date(GLint const& time);

                    //## Copy-Constructor ##//
                    Date(Date const& d);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    virtual ~Date();

                    //## Getter ##//
                    GLint const& getH() const;
                    GLint const& getM() const;
                    GLint const& getS() const;

                    //## Setter ##//
                    void setH(GLint const& v);
                    void setM(GLint const& v);
                    void setS(GLint const& v);

                    //## Methods ##//
                    virtual void convertMs(GLint const& time);

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
