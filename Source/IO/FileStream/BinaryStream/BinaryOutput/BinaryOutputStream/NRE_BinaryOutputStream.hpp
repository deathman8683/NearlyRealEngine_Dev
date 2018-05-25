
    /**
     * @file NRE_BinaryOutputStream.hpp
     * @brief Declaration of Engine's IO's Object : BinaryOutputStream
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
             * @class BinaryOutputStream
             * @brief IO's Object : Base interface for Output related stream
             */
            class BinaryOutputStream {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        BinaryOutputStream();

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param s the binary output stream to copy the content
                         */
                        BinaryOutputStream(BinaryOutputStream const& s) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move s into this, leaving s empty
                         * @param s the binary output stream to move
                         */
                        BinaryOutputStream(BinaryOutputStream && s);

                    //## Deconstructor ##//
                        /**
                         * BinaryOutputStream Deconstructor
                         */
                        ~BinaryOutputStream();

                    //## Getter ##//
                        virtual std::fstream& getStream() = 0;

                    //## Setter ##//

                    //## Methods ##//
                        template <class T>
                        void writeBinary(T const& object, size_t const& sizeInBytes);

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy allowed
                         * @param s the binary output stream to copy into this
                         * @return the reference of himself
                         */
                        BinaryOutputStream& operator=(BinaryOutputStream const& s) = delete;
                        /**
                         * Move assigment of s into this, leaving s empty
                         * @param s the binary output stream to move into this
                         * @return the reference of himself
                         */
                        BinaryOutputStream& operator=(BinaryOutputStream && s);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
