
    /**
     * @file NRE_GLException.hpp
     * @brief Declaration of Engine's Exception's Object : GLException
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
             * @class GLException
             * @brief Exception's Object : An OpenGL Exception
             */
            class GLException : public ExceptionHandler {
                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        GLException() throw();
                        /**
                         * Construct an exception with a custom log
                         * @param log the exception's log
                         */
                        GLException(std::string const& log) throw();

                    //## Copy-Constructor ##//
                        /**
                         * Copy e into this
                         * @param e the exception to copy the content
                         */
                        GLException(GLException const& e) throw();

                    //## Move-Constructor ##//
                        /**
                         * Move e into this, leaving e empty
                         * @param e the exception to move
                         */
                        GLException(GLException && e) throw();

                    //## Deconstructor ##//
                        /**
                         * GLException Deconstructor
                         */
                        virtual ~GLException() throw();

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of e into this
                         * @param e the exception to copy into this
                         * @return the reference of himself
                         */
                        GLException& operator=(GLException const& e);
                        /**
                         * Move assigment of e into this, leaving e empty
                         * @param e the exception to move into this
                         * @return the reference of himself
                         */
                        GLException& operator=(GLException && e);
            };

        };
    };
