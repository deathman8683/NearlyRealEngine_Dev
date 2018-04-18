
    /**
     * @file NRE_SupportException.hpp
     * @brief Declaration of Engine's Exception's Object : SupportException
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
             * @class SupportException
             * @brief Exception's Object : A Support Exception
             */
            class SupportException : public ExceptionHandler {
                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        SupportException() throw();
                        /**
                         * Construct an exception with a custom log
                         * @param log the exception's log
                         */
                        SupportException(std::string const& log) throw();

                    //## Copy-Constructor ##//
                        /**
                         * Copy e into this
                         * @param e the exception to copy the content
                         */
                        SupportException(SupportException const& e) throw();

                    //## Move-Constructor ##//
                        /**
                         * Move e into this, leaving e empty
                         * @param e the exception to move
                         */
                        SupportException(SupportException && e) throw();

                    //## Deconstructor ##//
                        /**
                         * SupportException Deconstructor
                         */
                        virtual ~SupportException() throw();

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of e into this
                         * @param e the exception to copy into this
                         * @return the reference of himself
                         */
                        SupportException& operator=(SupportException const& e);
                        /**
                         * Move assigment of e into this, leaving e empty
                         * @param e the exception to move into this
                         * @return the reference of himself
                         */
                        SupportException& operator=(SupportException && e);
            };

        };
    };
