
    /**
     * @file NRE_BinaryOutputFile.hpp
     * @brief Declaration of Engine's IO's Object : BinaryOutputFile
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../../Output/OutputFile/NRE_OutputFile.hpp"
    #include "../BinaryOutputStream/NRE_BinaryOutputStream.hpp"

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
             * @class BinaryOutputFile
             * @brief IO's Object : Manage Binary Output file stream
             */
            class BinaryOutputFile : public OutputFile, public BinaryOutputStream {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        BinaryOutputFile() = delete;
                        /**
                         * Construct a binary output file stream with a given file's path
                         * @param path the file's stream path
                         */
                        BinaryOutputFile(File const& path);

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param f the Output file to copy the content
                         */
                        BinaryOutputFile(BinaryOutputFile const& f) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move f into this, leaving f empty
                         * @param f the Output file to move
                         */
                        BinaryOutputFile(BinaryOutputFile && f);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * BinaryOutputFile Deconstructor
                         */
                        ~BinaryOutputFile();

                    //## Getter ##//
                        /**
                         * Opening mode getter
                         * @return the binary output file stream opening mode
                         */
                        std::ios_base::openmode const getMode() const override;
                        /**
                         * Stream getter
                         * @return the binary output file's stream
                         */
                        std::fstream& getStream() override;

                    //## Setter ##//

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy allowed
                         * @param f the Output file to copy into this
                         * @return the reference of himself
                         */
                        BinaryOutputFile& operator=(BinaryOutputFile const& f) = delete;
                        /**
                         * Move assigment of f into this, leaving f empty
                         * @param f the Output file to move into this
                         * @return the reference of himself
                         */
                        BinaryOutputFile& operator=(BinaryOutputFile && f);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
