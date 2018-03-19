
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
                    SDL::Surface xNeg;
                    SDL::Surface yNeg;
                    SDL::Surface zNeg;
                    SDL::Surface xPos;
                    SDL::Surface yPos;
                    SDL::Surface zPos;
                    IBO buffer;
                    VAO vao;

                public:
                    //## Constructor ##//
                    SkyBox();
                    SkyBox(std::string const& path, std::string const& ext);

                    //## Copy-Constructor ##//
                    SkyBox(SkyBox const& sb);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~SkyBox();

                    //## Getter ##//
                    SDL::Surface const& getXNeg() const;
                    SDL::Surface const& getYNeg() const;
                    SDL::Surface const& getZNeg() const;
                    SDL::Surface const& getXPos() const;
                    SDL::Surface const& getYPos() const;
                    SDL::Surface const& getZPos() const;
                    IBO const& getBuffer() const;
                    VAO const& getVAO() const;
                    GLenum const getType() const;

                    //## Setter ##//
                    void setXNeg(SDL::Surface const& t);
                    void setYNeg(SDL::Surface const& t);
                    void setZNeg(SDL::Surface const& t);
                    void setXPos(SDL::Surface const& t);
                    void setYPos(SDL::Surface const& t);
                    void setZPos(SDL::Surface const& t);
                    void setBuffer(IBO const& buf);
                    void setVAO(VAO const& vao);

                    //## Methods ##//
                    void bind() const;
                    void unbind() const;
                    void allocate(bool const& callFilter);
                    void update(std::vector<GLint> const& xOffset, std::vector<GLint> const& yOffset, std::vector<GLsizei> const& w, std::vector<GLsizei> const& h, std::vector<GLenum> const& format, std::vector<GLvoid*> const& data) const;
                    void allocateAndFill(bool const& callFilter);
                    void applyFilter() const;
                    void access() const;
                    void free();
                    void fillBuffer();
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
            };

        };
    };
