
    /**
     * @file NRE_BinaryIOFile.hpp
     * @brief Declaration of Engine's IO's Object : BinaryIOFile
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../IOFile/NRE_IOFile.hpp"
    #include "../BinaryInput/BinaryInputStream/NRE_BinaryInputStream.hpp"
    #include "../BinaryOutput/BinaryOutputStream/NRE_BinaryOutputStream.hpp"

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
             * @class BinaryIOFile
             * @brief IO's Object : Manage Binary Input-Output file stream
             */
            class BinaryIOFile : public IOFile, public BinaryInputStream, public BinaryOutputStream {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        BinaryIOFile() = delete;
                        BinaryIOFile(std::string const& path);

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param f the IO file to copy the content
                         */
                        BinaryIOFile(BinaryIOFile const& f) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move f into this, leaving f empty
                         * @param f the IO file to move
                         */
                        BinaryIOFile(BinaryIOFile && f);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * BinaryIOFile Deconstructor
                         */
                        ~BinaryIOFile();

                    //## Getter ##//
                        std::ios_base::openmode const getMode() const override;
                        std::fstream& getStream() override;

                    //## Setter ##//

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy allowed
                         * @param f the IO file to copy into this
                         * @return the reference of himself
                         */
                        BinaryIOFile& operator=(BinaryIOFile const& f) = delete;
                        /**
                         * Move assigment of f into this, leaving f empty
                         * @param f the IO file to move into this
                         * @return the reference of himself
                         */
                        BinaryIOFile& operator=(BinaryIOFile && f);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
