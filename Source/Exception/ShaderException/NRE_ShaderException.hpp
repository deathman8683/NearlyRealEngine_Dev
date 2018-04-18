
    /**
     * @file NRE_ShaderException.hpp
     * @brief Declaration of Engine's Exception's Object : ShaderException
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
             * @class ShaderException
             * @brief Exception's Object : A Shader Exception
             */
            class ShaderException : public ExceptionHandler {
                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        ShaderException() throw();
                        /**
                         * Construct an exception with a custom log
                         * @param log the exception's log
                         */
                        ShaderException(std::string const& log) throw();

                    //## Copy-Constructor ##//
                        /**
                         * Copy e into this
                         * @param e the exception to copy the content
                         */
                        ShaderException(ShaderException const& e) throw();

                    //## Move-Constructor ##//
                        /**
                         * Move e into this, leaving e empty
                         * @param e the exception to move
                         */
                        ShaderException(ShaderException && e) throw();

                    //## Deconstructor ##//
                        /**
                         * ShaderException Deconstructor
                         */
                        virtual ~ShaderException() throw();

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of e into this
                         * @param e the exception to copy into this
                         * @return the reference of himself
                         */
                        ShaderException& operator=(ShaderException const& e);
                        /**
                         * Move assigment of e into this, leaving e empty
                         * @param e the exception to move into this
                         * @return the reference of himself
                         */
                        ShaderException& operator=(ShaderException && e);
            };

        };
    };
