
    /**
     * @file NRE_Object>.hpp
     * @brief Declaration of Engine's Object's Object : Object
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../Generic/NRE_Type.hpp"
    #include "../GL_Wrapper/BufferObject/VBO/NRE_VBO.hpp"
    #include "../GL_Wrapper/BufferObject/VAO/NRE_VAO.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace Object
         * @brief The Engine's Object's managing system
         */
        namespace Object {

            /**
             * @class Object
             * @brief Object's Object : Manage a simple object with a VBO (or IBO) and a VAO
             */
            class Object {
                private:
                    GL::VBO* buffer;    /**< The object's rendering buffer */
                    GL::VAO vao;       /**< The object's rendering VAO */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Object();
                        /**
                         * Construct an object with his rendering buffer
                         * @param buf the rendering buffer, containing (or not yet) the object's model
                         */
                        Object(GL::VBO* buf);

                    //## Copy-Constructor ##//
                        /**
                         * Copy o into this
                         * @param o the object to copy the content
                         */
                        Object(Object const& o);

                    //## Move-Constructor ##//
                        /**
                         * Move o into this, leaving o empty
                         * @param o the object to move
                         */
                        Object(Object && o);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * Object Deconstructor
                         */
                        ~Object();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Draw the current object, need to be call from a rendering context (Shader bind)
                         */
                        void draw() const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of o into this
                         * @param o the object to copy into this
                         * @return the reference of himself
                         */
                        Object& operator=(Object const& o);
                        /**
                         * Move assigment of o into this, leaving o empty
                         * @param o the object to move into this
                         * @return the reference of himself
                         */
                        Object& operator=(Object && o);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
