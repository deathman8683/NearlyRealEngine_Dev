
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
                    ShaderException();
                    ShaderException(std::string const& log);

                    //## Copy-Constructor ##//
                    ShaderException(ShaderException const& e);

                    //## Deconstructor ##//
                    ~ShaderException();
            };

        };
    };
