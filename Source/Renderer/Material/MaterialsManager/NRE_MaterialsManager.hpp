
    /**
     * @file NRE_MaterialsManager.hpp
     * @brief Declaration of Engine's Renderer's Object : MaterialsManager
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
             * @class MaterialsManager
             * @brief Renderer's Object : Manage all materials
             */
            class MaterialsManager {
                public:
                    //## Getter ##//
                        /**
                         * Material getter
                         * @param  index the material's index
                         * @return       the corresponding material
                         */
                        static Material& getMaterial(GLuint const& index);
                        /**
                         * Size getter
                         * @return the material's array size
                         */
                        static size_t const getSize();
                        /**
                         * Albedo Texture 2D Array Getter
                         * @return the manager's albedo texture 2D array
                         */
                        static GL::Texture2DArray& getMaterialsAlbedo();
                        /**
                         * Normal Texture 2D Array Getter
                         * @return the manager's normal texture 2D array
                         */
                        static GL::Texture2DArray& getMaterialsNormal();
                        /**
                         * Roughness Texture 2D Array Getter
                         * @return the manager's roughness texture 2D array
                         */
                        static GL::Texture2DArray& getMaterialsRoughness();
                        /**
                         * Metallic Texture 2D Array Getter
                         * @return the manager's metallic texture 2D array
                         */
                        static GL::Texture2DArray& getMaterialsMetallic();

                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Initialize the material manager
                         */
                        static void init();
                        /**
                         * Desallocate the material manager
                         */
                        static void free();

                private:
                    static std::vector<Material*>* materials;       /**< The materials array */
                    static GL::Texture2DArray* materialsAlbedo;     /**< The albedo texture 2D array */
                    static GL::Texture2DArray* materialsNormal;     /**< The normal texture 2D array */
                    static GL::Texture2DArray* materialsRoughness;  /**< The roughness texture 2D array */
                    static GL::Texture2DArray* materialsMetallic;   /**< The metallic texture 2D array */
                    static size_t RESOLUTION;                       /**< The material's texture's resolution */
            };

        };
    };
