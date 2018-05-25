
    /**
     * @file NRE_BinaryInputFile.hpp
     * @brief Declaration of Engine's IO's Object : BinaryInputFile
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../../Input/InputFile/NRE_InputFile.hpp"
    #include "../BinaryInputStream/NRE_BinaryInputStream.hpp"

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
             * @class BinaryInputFile
             * @brief IO's Object : Manage Binary Input file stream
             */
            class BinaryInputFile : public InputFile, public BinaryInputStream {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        BinaryInputFile() = delete;
                        BinaryInputFile(std::string const& path);

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param f the Input file to copy the content
                         */
                        BinaryInputFile(BinaryInputFile const& f) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move f into this, leaving f empty
                         * @param f the Input file to move
                         */
                        BinaryInputFile(BinaryInputFile && f);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * BinaryInputFile Deconstructor
                         */
                        ~BinaryInputFile();

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
                        BinaryInputFile& operator=(BinaryInputFile const& f) = delete;
                        /**
                         * Move assigment of f into this, leaving f empty
                         * @param f the Input file to move into this
                         * @return the reference of himself
                         */
                        BinaryInputFile& operator=(BinaryInputFile && f);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
