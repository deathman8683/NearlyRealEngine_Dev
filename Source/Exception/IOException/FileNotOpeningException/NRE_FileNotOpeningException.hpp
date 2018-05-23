
    /**
     * @file NRE_FileNotOpeningException.hpp
     * @brief Declaration of Engine's Exception's Object : FileNotOpeningException
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_IOException.hpp"

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
             * @class FileNotOpeningException
             * @brief Exception's Object : A special IO exception to tell that a file is not existing
             */
            class FileNotOpeningException : public IOException {
                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        FileNotOpeningException() throw();
                        /**
                         * Construct an exception with a custom log
                         * @param log the exception's log
                         */
                        FileNotOpeningException(std::string const& log) throw();

                    //## Copy-Constructor ##//
                        /**
                         * Copy e into this
                         * @param e the exception to copy the content
                         */
                        FileNotOpeningException(FileNotOpeningException const& e) throw();

                    //## Move-Constructor ##//
                        /**
                         * Move e into this, leaving e empty
                         * @param e the exception to move
                         */
                        FileNotOpeningException(FileNotOpeningException && e) throw();

                    //## Deconstructor ##//
                        /**
                         * FileNotOpeningException Deconstructor
                         */
                        virtual ~FileNotOpeningException() throw();

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of e into this
                         * @param e the exception to copy into this
                         * @return the reference of himself
                         */
                        FileNotOpeningException& operator=(FileNotOpeningException const& e);
                        /**
                         * Move assigment of e into this, leaving e empty
                         * @param e the exception to move into this
                         * @return the reference of himself
                         */
                        FileNotOpeningException& operator=(FileNotOpeningException && e);
            };

        };
    };
