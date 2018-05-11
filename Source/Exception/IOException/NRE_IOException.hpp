
    /**
     * @file NRE_IOException.hpp
     * @brief Declaration of Engine's Exception's Object : IOException
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
             * @class IOException
             * @brief Exception's Object : An IO Exception
             */
            class IOException : public ExceptionHandler {
                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        IOException() throw();
                        /**
                         * Construct an exception with a custom log
                         * @param log the exception's log
                         */
                        IOException(std::string const& log) throw();

                    //## Copy-Constructor ##//
                        /**
                         * Copy e into this
                         * @param e the exception to copy the content
                         */
                        IOException(IOException const& e) throw();

                    //## Move-Constructor ##//
                        /**
                         * Move e into this, leaving e empty
                         * @param e the exception to move
                         */
                        IOException(IOException && e) throw();

                    //## Deconstructor ##//
                        /**
                         * IOException Deconstructor
                         */
                        virtual ~IOException() throw();

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of e into this
                         * @param e the exception to copy into this
                         * @return the reference of himself
                         */
                        IOException& operator=(IOException const& e);
                        /**
                         * Move assigment of e into this, leaving e empty
                         * @param e the exception to move into this
                         * @return the reference of himself
                         */
                        IOException& operator=(IOException && e);
            };

        };
    };
