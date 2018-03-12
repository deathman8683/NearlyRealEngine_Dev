
    /**
     * @file NRE_SkyBox.hpp
     * @brief Declaration of Engine's GL's Object : SkyBox
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../SDL_Wrapper/Surface/NRE_Surface.hpp"
    #include "../../Renderer/Shader/NRE_Shader.hpp"
    #include "../../Maths/NRE_Maths.hpp"
    #include "../VAO/NRE_VAO.hpp"

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
            class SkyBox {
                private:
                    GLuint id;
                    SDL::Surface xNeg;
                    SDL::Surface yNeg;
                    SDL::Surface zNeg;
                    SDL::Surface xPos;
                    SDL::Surface yPos;
                    SDL::Surface zPos;
                    NRE::Buffer::VertexBuffer vertex;
                    NRE::Buffer::IndexBuffer index;
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
                    GLuint const& getID() const;
                    NRE::Buffer::VertexBuffer const& getVertexBuffer() const;
                    NRE::Buffer::IndexBuffer const& getIndexBuffer() const;
                    VAO const& getVAO() const;
                    SDL::Surface const& getXNeg() const;
                    SDL::Surface const& getYNeg() const;
                    SDL::Surface const& getZNeg() const;
                    SDL::Surface const& getXPos() const;
                    SDL::Surface const& getYPos() const;
                    SDL::Surface const& getZPos() const;

                    //## Setter ##//
                    void setID(GLuint const& id);
                    void setVertexBuffer(NRE::Buffer::VertexBuffer const& buf);
                    void setIndexBuffer(NRE::Buffer::IndexBuffer const& buf);
                    void setVAO(VAO const& vao);
                    void setXNeg(SDL::Surface const& t);
                    void setYNeg(SDL::Surface const& t);
                    void setZNeg(SDL::Surface const& t);
                    void setXPos(SDL::Surface const& t);
                    void setYPos(SDL::Surface const& t);
                    void setZPos(SDL::Surface const& t);

                    //## Methods ##//
                    void generateID();
                    void deleteID();
                    void reload();
                    void bind() const;
                    void unbind() const;
                    void load();
                    void applyFilter();
                    void free();
                    void fillBuffer();
                    void render(Renderer::Shader const& shader, Maths::Matrix4x4<NREfloat> &modelview, Maths::Matrix4x4<NREfloat> &projection, Maths::Point3D<NREfloat> const& eye);

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
