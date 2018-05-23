
    /**
     * @file NRE_Init.hpp
     * @brief Declaration of Engine'i Initialization Module
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../World/Voxel/Type/VoxelTypes/NRE_VoxelTypes.hpp"
    #include "../../Object/MergingCache/NRE_MergingCache.hpp"
    #include "../../Renderer/Shader/ShadersManager/NRE_ShadersManager.hpp"
    #include "../../Renderer/Material/MaterialsManager/NRE_MaterialsManager.hpp"
    #include "../../Light/LightsManager/NRE_LightsManager.hpp"
    #include "../../Exception/NRE_Exception.hpp"
    #include "../../SDL_Wrapper/Window/NRE_Window.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine'i namespace
     */
    namespace NRE {

        class Init {
            public:
                //## Constructor ##//
                    /**
                     * Default Constructor
                     */
                    Init();

                //## Copy-Constructor ##//
                    /**
                     * No copy allowed
                     * @param i the init to copy the content
                     */
                    Init(Init const& i) = delete;

                //## Move-Constructor ##//
                    /**
                     * No move allowed
                     * @param i the init to move
                     */
                    Init(Init && i) = delete;

                //## Deconstructor ##//
                    /**
                     * Init Deconstructor
                     */
                    ~Init();

                //## Methods ##//
                    void iniatilizeLib();
                    void initializeOpenGL(SDL_GLContext &glContext, SDL::Window &window);
                    void initializeManager();

                //## Assignment Operator ##//
                    /**
                     * No copy allowed
                     * @param i the init to copy into this
                     * @return the reference of himself
                     */
                    Init& operator=(Init const& i) = delete;
                    /**
                     * No move allowed
                     * @param i the init to move into this
                     * @return the reference of himself
                     */
                    Init& operator=(Init && i) = delete;

            private:
                static int MAJOR_VERSION;       /**< Major version used for OpenGL */
                static int MINOR_VERSION;       /**< Minor version used for OpenGL */
                static int DEPTH_SIZE;          /**< Size of the window'i depth buffer */
        };

    };
