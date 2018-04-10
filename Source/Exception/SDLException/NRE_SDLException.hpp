
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
                    SDLException() throw();
                    SDLException(std::string const& log) throw();

                    //## Copy-Constructor ##//
                    SDLException(SDLException const& e) throw();

                    //## Deconstructor ##//
                    virtual ~SDLException() throw();
            };

        };
    };
