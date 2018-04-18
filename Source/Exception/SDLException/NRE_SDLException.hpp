
    /**
     * @file NRE_SDLException.hpp
     * @brief Declaration of Engine's Exception's Object : SDLException
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
             * @class SDLException
             * @brief Exception's Object : An SDL Exception
             */
            class SDLException : public ExceptionHandler {
                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        SDLException() throw();
                        /**
                         * Construct an exception with a custom log
                         * @param log the exception's log
                         */
                        SDLException(std::string const& log) throw();

                    //## Copy-Constructor ##//
                        /**
                         * Copy e into this
                         * @param e the exception to copy the content
                         */
                        SDLException(SDLException const& e) throw();

                    //## Move-Constructor ##//
                        /**
                         * Move e into this, leaving e empty
                         * @param e the exception to move
                         */
                        SDLException(SDLException && e) throw();

                    //## Deconstructor ##//
                        /**
                         * SDLException Deconstructor
                         */
                        virtual ~SDLException() throw();

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of e into this
                         * @param e the exception to copy into this
                         * @return the reference of himself
                         */
                        SDLException& operator=(SDLException const& e);
                        /**
                         * Move assigment of e into this, leaving e empty
                         * @param e the exception to move into this
                         * @return the reference of himself
                         */
                        SDLException& operator=(SDLException && e);
            };

        };
    };
