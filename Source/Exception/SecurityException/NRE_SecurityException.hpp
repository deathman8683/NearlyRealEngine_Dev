
    /**
     * @file NRE_SecurityException.hpp
     * @brief Declaration of Engine's Exception's Object : SecurityException
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_ExceptionHandler.hpp"

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
             * @class SecurityException
             * @brief Exception's Object : An OpenSecurity Exception
             */
            class SecurityException : public ExceptionHandler {
                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        SecurityException() throw();
                        /**
                         * Construct an exception with a custom log
                         * @param log the exception's log
                         */
                        SecurityException(std::string const& log) throw();

                    //## Copy-Constructor ##//
                        /**
                         * Copy e into this
                         * @param e the exception to copy the content
                         */
                        SecurityException(SecurityException const& e) throw();

                    //## Move-Constructor ##//
                        /**
                         * Move e into this, leaving e empty
                         * @param e the exception to move
                         */
                        SecurityException(SecurityException && e) throw();

                    //## Deconstructor ##//
                        /**
                         * SecurityException Deconstructor
                         */
                        virtual ~SecurityException() throw();

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of e into this
                         * @param e the exception to copy into this
                         * @return the reference of himself
                         */
                        SecurityException& operator=(SecurityException const& e);
                        /**
                         * Move assigment of e into this, leaving e empty
                         * @param e the exception to move into this
                         * @return the reference of himself
                         */
                        SecurityException& operator=(SecurityException && e);
            };

        };
    };
