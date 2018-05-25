
    /**
     * @file NRE_InputFile.hpp
     * @brief Declaration of Engine's IO's Object : InputFile
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../NRE_FileStream.hpp"

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
             * @class InputFile
             * @brief IO's Object : Manage Input file stream
             */
            class InputFile : public FileStream, public InputStream {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        InputFile() = delete;
                        InputFile(std::string const& path);

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param f the Input file to copy the content
                         */
                        InputFile(InputFile const& f) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move f into this, leaving f empty
                         * @param f the Input file to move
                         */
                        InputFile(InputFile && f);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * InputFile Deconstructor
                         */
                        ~InputFile();

                    //## Getter ##//
                        std::ios_base::openmode const getMode() const override;
                        std::fstream& getStream() override;

                    //## Setter ##//

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy allowed
                         * @param f the Input file to copy into this
                         * @return the reference of himself
                         */
                        InputFile& operator=(InputFile const& f) = delete;
                        /**
                         * Move assigment of f into this, leaving f empty
                         * @param f the Input file to move into this
                         * @return the reference of himself
                         */
                        InputFile& operator=(InputFile && f);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
