
    /**
     * @file NRE_VAO.hpp
     * @brief Declaration of Engine's GL's Object : VAO
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
             * @class VAO
             * @brief GL's Object : Manage the storage of functions' call, like for VBO
             */
            class VAO {
                private:
                    GLuint id;

                public:
                    //## Constructor ##//
                    VAO();

                    //## Copy-Constructor ##//
                    VAO(VAO const& arr);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~VAO();

                    //## Getter ##//
                    GLuint const& getID() const;

                    //## Setter ##//
                    void setID(GLuint const& id);

                    //## Methods ##//
                    void generateID();
                    void deleteID();
                    void bind();
                    void unbind();

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