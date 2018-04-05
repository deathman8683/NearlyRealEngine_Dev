
    /**
     * @file NRE_SkyBox.hpp
     * @brief Declaration of Engine's GL's Object : SkyBox
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../Buffer/TextureBuffer/NRE_TextureBuffer.hpp"
    #include "../../../Renderer/Shader/NRE_Shader.hpp"
    #include "../../../Maths/NRE_Maths.hpp"
    #include "../../Buffer/VAO/NRE_VAO.hpp"
    #include "../FBO/NRE_FBO.hpp"
    #include "../IBO/NRE_IBO.hpp"

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
             * @class SkyBox
             * @brief GL's Object : A basic SkyBox with 6 texture using a cube map
             */
            class SkyBox : public TextureBuffer, public BufferObject {
                private:
                    FBO capture;
                    Texture2D* cubeMap;
                    IBO buffer;
                    VAO vao;

                public:
                    //## Constructor ##//
                    SkyBox();
                    SkyBox(std::string const& path);

                    //## Copy-Constructor ##//
                    SkyBox(SkyBox const& sb);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~SkyBox();

                    //## Getter ##//
                    FBO const& getCapture() const;
                    Texture2D* const& getCubeMap() const;
                    IBO const& getBuffer() const;
                    VAO const& getVAO() const;
                    GLenum const getType() const;

                    //## Setter ##//
                    void setCapture(FBO const& buf);
                    void setCubeMap(Texture2D* const& t);
                    void setBuffer(IBO const& buf);
                    void setVAO(VAO const& vao);

                    //## Methods ##//
                    void bind() const;
                    void unbind() const;
                    void allocate(bool const& callFilter);
                    void applyFilter() const;
                    void access() const;
                    void fillBuffer();
                    void captureCubeMap(Renderer::Shader const& shader);
                    void render(Renderer::Shader const& shader, Maths::Matrix4x4<NREfloat> &MVP, Maths::Point3D<NREfloat> const& eye);

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
                    static GLenum TYPE;
                    static GLuint SIZE;
            };

        };
    };
