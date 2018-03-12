
    /**
     * @file NRE_Buffer.hpp
     * @brief Declaration of Engine's GL's Object : Buffer
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../../../Generic/NRE_Type.hpp"

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
             * @brief GL's Object : A typical buffer used in BufferObject - Interface for specilized buffer
             */
            class Buffer {
                protected:
                    GLuint id;

                public:
                    //## Constructor ##//
                    Buffer();

                    //## Copy-Constructor ##//
                    Buffer(Buffer const& buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    virtual ~Buffer();

                    //## Getter ##//
                    GLuint const& getID() const;

                    //## Setter ##//
                    void setID(GLuint const& id);

                    //## Methods ##//
                    void generateID();
                    void deleteID();
                    void reload();
                    virtual void allocate(GLsizeiptr const& size, GLenum const& usage, GLenum const& target);
                    virtual void update(GLintptr const& offset, GLsizeiptr const& size, GLvoid* const& data, GLenum const& target);
                    virtual void allocateAndFill(GLsizeiptr const& size, GLenum const& usage, GLvoid* const& data, GLenum const& target);
                    virtual void bind(GLenum const& target) const;
                    virtual void unbind(GLenum const& target) const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//

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