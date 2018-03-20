
    /**
     * @file NRE_ExceptionHandler.hpp
     * @brief Declaration of Engine's Exception's Object : ExceptionHandler
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include <exception>
    #include "../Generic/NRE_Type.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace Exception
         * @brief Engine's Exception Handler Module
         */
        namespace Exception {

            /**
             * @class ExceptionHandler
             * @brief Exception's Object : Manage Engine's generic exception
             */
            class ExceptionHandler {
                private:
                    std::string log;

                public:
                    //## Constructor ##//
                    ExceptionHandler() throw();
                    ExceptionHandler(std::string const& log) throw();

                    //## Copy-Constructor ##//
                    ExceptionHandler(ExceptionHandler const& e) throw();

                    //## Convertor ##//

                    //## Deconstructor ##//
                    virtual ~ExceptionHandler() throw();

                    //## Getter ##//
                    std::string const& getLog() const throw();

                    //## Setter ##//
                    void setLog(std::string const& log) throw();

                    //## Methods ##//
                    virtual const char* what() const throw();

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
