
    /**
     * @file NRE_MaterialManager.hpp
     * @brief Declaration of Engine's Renderer's Object : MaterialManager
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_Material.hpp"
    #include "../../../GL_Wrapper/BufferObject/Texture2DArray/NRE_Texture2DArray.hpp"
    #include "../../../World/Voxel/Type/VoxelTypes/NRE_VoxelTypes.hpp"

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
             * @class MaterialManager
             * @brief Renderer's Object : Manage all materials
             */
            class MaterialManager {
                public:
                    //## Getter ##//
                        static Material& getMaterial(GLuint const& index);
                        static size_t const getSize();
                        static GL::Texture2DArray& getMaterialArray();

                    //## Setter ##//

                    //## Methods ##//
                        static void init();
                        static void free();
                        static void sendMaterial();

                private:
                    static std::vector<Material>* materials;
                    static GL::Texture2DArray* materialsAlbedo;
            };

        };
    };
