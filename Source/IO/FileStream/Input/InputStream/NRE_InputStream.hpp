
    /**
     * @file NRE_InputStream.hpp
     * @brief Declaration of Engine's IO's Object : InputStream
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../../File/NRE_File.hpp"

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
             * @class InputStream
             * @brief IO's Object : Base interface for Input related stream
             */
            class InputStream {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        InputStream();

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param s the input stream to copy the content
                         */
                        InputStream(InputStream const& s) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move s into this, leaving s empty
                         * @param s the input stream to move
                         */
                        InputStream(InputStream && s);

                    //## Deconstructor ##//
                        /**
                         * InputStream Deconstructor
                         */
                        ~InputStream();

                    //## Getter ##//
                        std::fstream& getStream() = 0;

                    //## Setter ##//

                    //## Methods ##//
                        template <class T>
                        void read(T& object);

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy allowed
                         * @param s the input stream to copy into this
                         * @return the reference of himself
                         */
                        InputStream& operator=(InputStream const& s) = delete;
                        /**
                         * Move assigment of s into this, leaving s empty
                         * @param s the input stream to move into this
                         * @return the reference of himself
                         */
                        InputStream& operator=(InputStream && s);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };

    #include "NRE_InputStream.tpp"
