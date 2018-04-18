
    /**
     * @file NRE_Buffer.hpp
     * @brief Declaration of Engine's GL's Object : Buffer
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../Generic/NRE_Type.hpp"

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
             * @class Buffer
             * @brief GL's Object : A typical buffer used in BufferObject
             */
            class Buffer {
                protected:
                    GLuint id;  /**< Buffer OpenGL's id */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Buffer();

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param buf the buffer to copy
                         */
                        Buffer(Buffer const& buf) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move buf into this, leaving buf empty
                         * @param buf the buffer to move
                         */
                        Buffer(Buffer && buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * Buffer Deconstructor
                         */
                        virtual ~Buffer();

                    //## Getter ##//
                        /**
                         * ID getter
                         * @return the id value
                         */
                        GLuint const& getID() const;

                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Generate the buffer's id with different OpenGL command for different buffer
                         */
                        virtual void generateID() = 0;
                        /**
                         * Delete the buffer's id with different OpenGL command for different buffer
                         */
                        virtual void deleteID() = 0;
                        /**
                         * Reload the buffer by deleting and reloading the id
                         */
                        void reload();
                        /**
                         * Bind the current buffer with his custom target and OpenGL command
                         */
                        virtual void bind() const = 0;
                        /**
                         * Unbind the current buffer with his custom target and OpenGL command
                         */
                        virtual void unbind() const = 0;

                    //## Access Operator ##//

                    //## Assignment Operator ##/
                        /**
                         * No copy assigment allowed
                         * @param buf the buffer to copy
                         */
                        Buffer& operator=(Buffer const& buf) = delete;
                        /**
                         * Move assigment of buf into this, leaving buf empty
                         * @param buf the buffer to move into this
                         * @return the reference of himself
                         */
                        Buffer& operator=(Buffer && buf);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

            inline std::ostream& operator<<(std::ostream &stream, Buffer const& buf) {
                stream << "(" << buf.getID() << ")";
                return stream;
            }

        };
    };
