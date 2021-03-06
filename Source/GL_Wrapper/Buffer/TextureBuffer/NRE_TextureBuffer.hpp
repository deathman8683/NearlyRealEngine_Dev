
    /**
     * @file NRE_TextureBuffer.hpp
     * @brief Declaration of Engine's GL's Object : TextureBuffer
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_Buffer.hpp"
    #include "../../../SDL_Wrapper/Surface/NRE_Surface.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace GL
         * @brief Engine's OpenGL's Wrapper's Module
         */
        namespace GL {

            /**
             * @class TextureBuffer
             * @brief GL's Object : A specialized buffer for texture managing
             */
            class TextureBuffer : public Buffer {
                private:
                    GLenum type;

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        TextureBuffer();
                        /**
                         * Construct the buffer and generate or not his id
                         * @param generate tell if the base class has to generate an id or not
                         */
                        TextureBuffer(bool const& generate);
                        /**
                         * Construct the buffer and generate or not his id
                         * @param generate  tell if the base class has to generate an id or not
                         * @param type      the texture's type enum
                         */
                        TextureBuffer(bool const& generate, GLenum const& type);

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param buf the buffer to copy
                         */
                        TextureBuffer(TextureBuffer const& buf) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move buf into this, leaving buf empty
                         * @param buf the buffer to move
                         */
                        TextureBuffer(TextureBuffer && buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * TextureBuffer Deconstructor
                         */
                        virtual ~TextureBuffer();

                    //## Getter ##//
                        /**
                         * Return the texture type enum, used with derived class
                         * @return the texture type enum
                         */
                        GLenum const& getType() const;
                        /**
                         * Return the attribute buffer target, used with derived class
                         * @return the attribute buffer target
                         */
                        virtual GLenum const getTarget() const = 0;

                    //## Setter ##//
                        /**
                         * Type setter
                         * @param t the new texture type
                         */
                        void setType(GLenum const& t);

                    //## Methods ##//
                        /**
                         * Generate the buffer's id with different OpenGL command for different buffer
                         */
                        void generateID() override;
                        /**
                         * Delete the buffer's id with different OpenGL command for different buffer
                         */
                        void deleteID() override;
                        /**
                         * Bind the current buffer with his custom target and OpenGL command
                         */
                        void bind() const override;
                        /**
                         * Unbind the current buffer with his custom target and OpenGL command
                         */
                        void unbind() const override;
                        /**
                         * Store calls for VAO managing
                         */
                        void access() const;
                        /**
                         * Texture specific filter
                         */
                        virtual void applyFilter() const = 0;

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy assigment allowed
                         * @param buf the buffer to copy
                         */
                        TextureBuffer& operator=(TextureBuffer const& buf) = delete;
                        /**
                         * Move assigment of buf into this, leaving buf empty
                         * @param buf the buffer to move into this
                         * @return the reference of himself
                         */
                        TextureBuffer& operator=(TextureBuffer && buf);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                protected:
                    static GLenum DEFAULT_TYPE; /**< The texture default type enum */
            };

        };
    };
