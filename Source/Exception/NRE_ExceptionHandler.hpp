
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
                    std::string log;    /**< Exception's log */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        ExceptionHandler() throw();
                        /**
                         * Construct an exception with a custom log
                         * @param log the exception's log
                         */
                        ExceptionHandler(std::string const& log) throw();

                    //## Copy-Constructor ##//
                        /**
                         * Copy e into this
                         * @param e the exception to copy the content
                         */
                        ExceptionHandler(ExceptionHandler const& e) throw();

                    //## Move-Constructor ##//
                        /**
                         * Move e into this, leaving e empty
                         * @param e the exception to move
                         */
                        ExceptionHandler(ExceptionHandler && e) throw();

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * ExceptionHandler Deconstructor
                         */
                        virtual ~ExceptionHandler() throw();

                    //## Getter ##//
                        /**
                         * Log getter
                         * @return the exception's logs
                         */
                        std::string const& getLog() const throw();

                    //## Methods ##//
                        /**
                         * Inherited methods for exception
                         * @return C-style string with the log
                         */
                        virtual const char* what() const throw();

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of e into this
                         * @param e the exception to copy into this
                         * @return the reference of himself
                         */
                        ExceptionHandler& operator=(ExceptionHandler const& e);
                        /**
                         * Move assigment of e into this, leaving e empty
                         * @param e the exception to move into this
                         * @return the reference of himself
                         */
                        ExceptionHandler& operator=(ExceptionHandler && e);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
