
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
                    GLException() throw();
                    GLException(std::string const& log) throw();

                    //## Copy-Constructor ##//
                    GLException(GLException const& e) throw();

                    //## Deconstructor ##//
                    virtual ~GLException() throw();
            };

        };
    };
