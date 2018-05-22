
    /**
     * @file NRE_DeferredRenderer.hpp
     * @brief Declaration of Engine's Renderer's Object : DeferredRenderer
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include <sstream>
    #include <fstream>
    #include "../../Object/2D/NRE_Object2D.hpp"
    #include "../EnvironmentMap/NRE_EnvironmentMap.hpp"
    #include "../../Camera/FixedCamera/NRE_FixedCamera.hpp"
    #include "../../World/NRE_World.hpp"
    #include "../SSAO/NRE_SSAO.hpp"
    #include "../Material/MaterialsManager/NRE_MaterialsManager.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace Renderer
         * @brief Engine's Renderer Module
         */
        namespace Renderer {

            /**
             * @class DeferredRenderer
             * @brief Renderer's Object : Manage deferred renderding techniques using FBO
             */
            class DeferredRenderer : public Object::Object2D {
                private:
                    GL::FBO gBuffer;    /**< The Deferred Renderer G-Buffer to store scene information */
                    SSAO ssao;          /**< The Deferred Renderer SSAO effect/object */

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        DeferredRenderer();
                        /**
                         * Construct a Deferred Renderer with the screen size
                         * @param size the screen size for the rendering
                         */
                        DeferredRenderer(Maths::Vector2D<GLushort> const& size);

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param def the Deferred Renderer to copy
                         */
                        DeferredRenderer(DeferredRenderer const& def) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move def into this, leaving def empty
                         * @param def the Deferred Renderer to move
                         */
                        DeferredRenderer(DeferredRenderer && def);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * DeferredRenderer Deconstructor
                         */
                        ~DeferredRenderer();

                    //## Getter ##//

                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Render the gBuffer with a lighting pass, use it in last pass in the rendering pipeline
                         * @param invModelview  the inverse modelview matrix
                         * @param rotation      the rotation matrix for the skybox
                         * @param camera        the player camera
                         * @param skyBox        the skybox to render
                         */
                        void render(Maths::Matrix4x4<NREfloat> const& invModelview, Maths::Matrix4x4<NREfloat> const& rotation, Camera::FixedCamera const& camera, EnvironmentMap const& skyBox);
                        /**
                         * Setup draw command to start filling the G-Buffer
                         */
                        void startGBufferPass();
                        /**
                         * Setup draw command to end filling the G-Buffer
                         */
                        void endGBufferPass();
                        /**
                         * Process the SSAO pass
                         */
                        void SSAOPass();

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy assigment allowed
                         * @param def the Deferred Renderer to copy
                         */
                        DeferredRenderer& operator=(DeferredRenderer const& def) = delete;
                        /**
                         * Move assigment of def into this, leaving def empty
                         * @param def the Deferred Renderer to move into this
                         * @return the reference of himself
                         */
                        DeferredRenderer& operator=(DeferredRenderer && def);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
