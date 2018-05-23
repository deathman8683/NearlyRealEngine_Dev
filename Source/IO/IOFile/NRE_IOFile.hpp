
    /**
     * @file NRE_IOFile.hpp
     * @brief Declaration of Engine's IO's Object : IOFile
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../File/NRE_File.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace IO
         * @brief Engine's IO's Module
         */
        namespace IO {

            /**
             * @class IOFile
             * @brief IO's Object : Manage a input/output base with users-defined opening mode
             */
            class IOFile : public File {
                private:
                    std::fstream file;

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        IOFile();

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param f the IO file to copy the content
                         */
                        IOFile(IOFile const& f) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move f into this, leaving f empty
                         * @param f the IO file to move
                         */
                        IOFile(IOFile && f);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * IOFile Deconstructor
                         */
                        ~IOFile();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy allowed
                         * @param f the IO file to copy into this
                         * @return the reference of himself
                         */
                        IOFile& operator=(IOFile const& f) = delete;
                        /**
                         * Move assigment of f into this, leaving f empty
                         * @param f the IO file to move into this
                         * @return the reference of himself
                         */
                        IOFile& operator=(IOFile && f);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
