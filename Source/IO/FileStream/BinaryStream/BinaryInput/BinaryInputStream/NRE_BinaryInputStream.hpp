
    /**
     * @file NRE_BinaryInputStream.hpp
     * @brief Declaration of Engine's IO's Object : BinaryInputStream
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../../../File/NRE_File.hpp"

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
             * @class BinaryInputStream
             * @brief IO's Object : Base interface for Input related stream
             */
            class BinaryInputStream {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        BinaryInputStream();

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param s the binary input stream to copy the content
                         */
                        BinaryInputStream(BinaryInputStream const& s) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move s into this, leaving s empty
                         * @param s the binary input stream to move
                         */
                        BinaryInputStream(BinaryInputStream && s);

                    //## Deconstructor ##//
                        /**
                         * BinaryInputStream Deconstructor
                         */
                        ~BinaryInputStream();

                    //## Getter ##//
                        /**
                         * Stream getter
                         * @return the file's stream
                         */
                        virtual std::fstream& getStream() = 0;

                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Read a given number of bytes into the passed data from the file stream
                         * @param object        the data to store the read return
                         * @param sizeInBytes   the number of bytes to read
                         */
                        template <class T>
                        void readBinary(T& object, size_t const& sizeInBytes);

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy allowed
                         * @param s the binary input stream to copy into this
                         * @return the reference of himself
                         */
                        BinaryInputStream& operator=(BinaryInputStream const& s) = delete;
                        /**
                         * Move assigment of s into this, leaving s empty
                         * @param s the binary input stream to move into this
                         * @return the reference of himself
                         */
                        BinaryInputStream& operator=(BinaryInputStream && s);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
