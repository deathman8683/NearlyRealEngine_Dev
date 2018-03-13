
    /**
     * @file NRE_TextureBuffer.hpp
     * @brief Declaration of Engine's Buffer's Object : TextureBuffer
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "<Path>/Generic/NRE_Type.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace Buffer
         * @brief <Module_Desc>
         */
        namespace Buffer {

            /**
             * @class TextureBuffer
             * @brief Buffer's Object : A particular buffer for texture id
             */
            class TextureBuffer {
                private:
                    GLuint id;

                public:
                    //## Constructor ##//
                    TextureBuffer();
                    TextureBuffer(bool const& generate);

                    //## Copy-Constructor ##//
                    TextureBuffer(TextureBuffer const& buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~TextureBuffer();

                    //## Getter ##//
                    GLuint const& getID() const;

                    //## Setter ##//
                    void setID(GLuint const& id);

                    //## Methods ##//
                    void generateID();
                    void deleteID();
                    void reload();

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
