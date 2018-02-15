
    /**
     * @file NRE_Buffer.hpp
     * @brief Declaration of Engine's GL's Object : Buffer
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../../Generic/NRE_Type.hpp"

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
                private:
                    GLuint id;

                public:
                    //## Constructor ##//
                    Buffer();

                    //## Copy-Constructor ##//

                    //## Convertor ##//

                    //## Deconstructor ##//
                    virtual ~Buffer();

                    //## Getter ##//
                    virtual GLuint const& getID() const;

                    //## Setter ##//
                    virtual void setID(GLuint const& id);

                    //## Methods ##//
                    virtual void generateID() = 0;
                    virtual void deleteID() = 0;
                    virtual void reload() = 0;
                    virtual void allocate(unsigned int const& vertices, GLenum const& usage) = 0;
                    virtual void update(unsigned int const& vertices, GLvoid* const data) = 0;

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
