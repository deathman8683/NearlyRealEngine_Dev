
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
                    SupportException() throw();
                    SupportException(std::string const& log) throw();

                    //## Copy-Constructor ##//
                    SupportException(SupportException const& e) throw();

                    //## Deconstructor ##//
                    virtual ~SupportException() throw();
            };

        };
    };
