
    #include "NRE_EnvironmentMap.hpp"

    #include <stb_image.h>

    namespace NRE {
        namespace Renderer {

            EnvironmentMap::EnvironmentMap() {
            }

            EnvironmentMap::EnvironmentMap(std::string const& path, Shader const& captureShader, Shader const& irradianceShader) {
                capture(path, captureShader, irradianceShader);
                fillBuffer();
            }

            EnvironmentMap::EnvironmentMap(EnvironmentMap const& map) : map(map.getMap()), irradianceMap(map.getIrradienceMap()), buffer(true), vao(true) {
                fillBuffer();
            }

            EnvironmentMap::~EnvironmentMap() {
            }

            GL::SkyBox const& EnvironmentMap::getMap() const {
                return map;
            }

            GL::SkyBox const& EnvironmentMap::getIrradienceMap() const {
                return irradianceMap;
            }

            GL::IBO const& EnvironmentMap::getBuffer() const {
                return buffer;
            }

            GL::VAO const& EnvironmentMap::getVAO() const {
                return vao;
            }

            void EnvironmentMap::setMap(GL::SkyBox const& map) {
                this->map = map;
            }

            void EnvironmentMap::setIrradience(GL::SkyBox const& map) {
                irradianceMap = map;
            }

            void EnvironmentMap::setBuffer(GL::IBO const& buf) {
                buffer = buf;
            }

            void EnvironmentMap::setVAO(GL::VAO const& vao) {
                this->vao = vao;
            }

            void EnvironmentMap::allocate() {
                map.allocate(true);
                irradianceMap.allocate(true);
            }

            void EnvironmentMap::fillBuffer() {
                GLint vData[24] = {
                    -1, -1, -1,
                    -1, -1, 1,
                    -1, 1, -1,
                    -1, 1, 1,
                    1, 1, 1,
                    1, 1, -1,
                    1, -1, 1,
                    1, -1, -1
                };

                GLuint iData[36] = {
                    2, 0, 7, 7, 5, 2,
                    1, 0, 2, 2, 3, 1,
                    7, 6, 4, 4, 5, 7,
                    1, 3, 4, 4, 6, 1,
                    2, 5, 4, 4, 3, 2,
                    0, 1, 7, 7, 1, 6,
                };

                std::vector<GLvoid*> data;
                data.push_back(vData);

                buffer.allocateAndFill(sizeof(GLint), 24, 36, GL_STATIC_DRAW, data, iData);
                vao.access(buffer, GL_INT, true);
            }

            void EnvironmentMap::capture(std::string const& path, Shader const& captureShader, Shader const& irradianceShader) {
                GL::Texture2D cubeMap;

                cubeMap.setType(GL_FLOAT);
                cubeMap.setGLInternalFormat(GL_RGB16F);
                cubeMap.setGLFormat(GL_RGB);

                stbi_set_flip_vertically_on_load(true);

                int w, h, nrComponents;
                float *data = stbi_loadf(path.c_str(), &w, &h, &nrComponents, 0);
                cubeMap.setGLW(w);
                cubeMap.setGLH(h);
                cubeMap.TextureBuffer::allocateAndFill(0, cubeMap.getGLInternalFormat(), cubeMap.getGLW(), cubeMap.getGLH(), cubeMap.getGLFormat(), data, true);
                cubeMap.setAllocated(true);

                stbi_image_free(data);
            }

            void EnvironmentMap::render(Shader const& shader, Maths::Matrix4x4<NREfloat> &projection, Maths::Matrix4x4<NREfloat> &modelview) {
                map.render(shader, projection, modelview);
            }

        };
    };
