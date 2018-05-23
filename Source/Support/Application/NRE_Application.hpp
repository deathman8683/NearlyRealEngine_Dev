
    /**
     * @file NRE_Application.hpp
     * @brief Declaration of Engine's Support's Object : Application
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../Stage/NRE_Stage.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace Support
         * @brief Engine's Application's Support Module
         */
        namespace Support {

            /**
             * @class Application
             * @brief Support's Object : Manage an application running under the engine
             */
            class Application : public Stage {
                private:


                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Application() = delete;
                        Application(std::string const& title, Maths::Vector2D<GLuint> const& size);

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param app the application to copy the content
                         */
                        Application(Application const& app) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move app into this, leaving app empty
                         * @param app the application to move
                         */
                        Application(Application && app);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * Application Deconstructor
                         */
                        ~Application();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//
                        void init();

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy allowed
                         * @param app the application to copy into this
                         * @return the reference of himself
                         */
                        Application& operator=(Application const& app) = delete;
                        /**
                         * Move assigment of app into this, leaving app empty
                         * @param app the application to move into this
                         * @return the reference of himself
                         */
                        Application& operator=(Application && app);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
