
    /**
     * @file NRE_Object2D.hpp
     * @brief Declaration of Engine's Object's Object : Object2D
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_Object.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace Object
         * @brief The Engine's Object's managing system>
         */
        namespace Object {

            /**
             * @class Object2D
             * @brief Object's Object : Manage 2D object
             */
            class Object2D : public Object {
                private:

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Object2D();
                        Object2D(GLenum const& usage, Maths::Point2D<GLint> const& coord, Maths::Vector2D<GLint> size);

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param o the 2D object to copy the content
                         */
                        Object2D(Object2D const& o) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move o into this, leaving o empty
                         * @param o the 2D object to move
                         */
                        Object2D(Object2D && o);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * Object2D Deconstructor
                         */
                        virtual ~Object2D();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//
                        void process(GLenum const& usage, Maths::Point2D<GLint> const& coord, Maths::Vector2D<GLint> size);

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy allowed
                         * @param o the 2D object to copy into this
                         * @return the reference of himself
                         */
                        Object2D& operator=(Object2D const& o) = delete;
                        /**
                         * Move assigment of o into this, leaving o empty
                         * @param o the 2D object to move into this
                         * @return the reference of himself
                         */
                        Object2D& operator=(Object2D && o);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
