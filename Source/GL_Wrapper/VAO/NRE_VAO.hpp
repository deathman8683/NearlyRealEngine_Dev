
    /**
     * @file NRE_ArrayBuffer.hpp
     * @brief Declaration of Engine's GL's Object : VAO
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../BufferObject/VBO/NRE_VBO.hpp"

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
             * @class VAO
             * @brief GL's Object : A specialized buffer for VAO managing
             */
            class VAO {
                private:
                    GLuint id;

                public:
                    //## Constructor ##//
                    VAO();
                    VAO(bool const& generate);

                    //## Copy-Constructor ##//
                    VAO(VAO const& buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    virtual ~VAO();

                    //## Getter ##//
                    GLuint const& getID() const;

                    //## Setter ##//
                    void setID(GLuint const& id);

                    //## Methods ##//
                    void generateID();
                    void deleteID();
                    void bind() const;
                    void unbind() const;
                    void access(VBO const& buffer, GLenum const& vertexType, bool const& enableVAA = true) const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

            inline std::ostream& operator<<(std::ostream &stream, VAO const& arr) {
                stream << "(" << arr.getID() << ")";
                return stream;
            }

        };
    };
