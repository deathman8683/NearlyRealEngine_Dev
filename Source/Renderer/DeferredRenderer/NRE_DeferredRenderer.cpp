
    #include "NRE_DeferredRenderer.hpp"

    namespace NRE {
        namespace Renderer {

            DeferredRenderer::DeferredRenderer() {
            }

            DeferredRenderer::DeferredRenderer(Maths::Vector2D<GLushort> const& size) : gBuffer(size.getX(), size.getY(), 3), buffer(true), vao(true) {
                projection.ortho(0, size.getX(), 0, size.getY(), 0.1, 2);
                buffer.push_back(new GL::UVBuffer(true));
                fillBuffer();
            }

            DeferredRenderer::DeferredRenderer(DeferredRenderer const& renderer) : gBuffer(renderer.getFrameBuffer()), modelview(renderer.getModelview()), projection(renderer.getProjection()), buffer(renderer.getBuffer()), vao(renderer.getVAO()) {
            }

            DeferredRenderer::~DeferredRenderer() {
            }

            GL::FBO const& DeferredRenderer::getFrameBuffer() const {
                return gBuffer;
            }

            Maths::Matrix4x4<NREfloat> const& DeferredRenderer::getModelview() const {
                return modelview;
            }

            Maths::Matrix4x4<NREfloat> const& DeferredRenderer::getProjection() const {
                return projection;
            }

            GL::VBO const& DeferredRenderer::getBuffer() const {
                return buffer;
            }

            GL::VAO const& DeferredRenderer::getVAO() const {
                return vao;
            }

            void DeferredRenderer::setFrameBuffer(GL::FBO const& buffer) {
                gBuffer = buffer;
            }

            void DeferredRenderer::setModelview(Maths::Matrix4x4<NREfloat> const& mat) {
                modelview = mat;
            }

            void DeferredRenderer::setProjection(Maths::Matrix4x4<NREfloat> const& mat) {
                projection = mat;
            }

            void DeferredRenderer::setBuffer(GL::VBO const& buffer) {
                this->buffer = buffer;
            }

            void DeferredRenderer::setVAO(GL::VAO const& vao) {
                this->vao = vao;
            }

            void DeferredRenderer::render(Shader const& shader) {
                modelview.setIdentity();
                glUseProgram(shader.getProgramID());
                    vao.bind();
                        glActiveTexture(GL_TEXTURE0);
                        glEnable(GL_TEXTURE_2D);
                        getFrameBuffer().getColorBuffer(0)->bind();
                            glUniform1i(glGetUniformLocation(shader.getProgramID(), "texDiffuse"), 0);

                        glActiveTexture(GL_TEXTURE1);
                        glEnable(GL_TEXTURE_2D);
                        getFrameBuffer().getColorBuffer(1)->bind();
                            glUniform1i(glGetUniformLocation(shader.getProgramID(), "texPosition"), 1);

                        glActiveTexture(GL_TEXTURE2);
                        glEnable(GL_TEXTURE_2D);
                        getFrameBuffer().getColorBuffer(2)->bind();
                            glUniform1i(glGetUniformLocation(shader.getProgramID(), "texNormal"), 2);

                        modelview.translate(Maths::Vector3D<NREfloat>(0, 0, -1.0));

                        glUniformMatrix4fv(glGetUniformLocation(shader.getProgramID(), "modelview"), 1, GL_TRUE, modelview.value());
                        glUniformMatrix4fv(glGetUniformLocation(shader.getProgramID(), "projection"), 1, GL_TRUE, projection.value());

                        glDrawArrays(GL_TRIANGLES, 0, 6);

                            glActiveTexture(GL_TEXTURE2);
                            glDisable(GL_TEXTURE_2D);
                        getFrameBuffer().getColorBuffer(2)->unbind();
                            glActiveTexture(GL_TEXTURE1);
                            glDisable(GL_TEXTURE_2D);
                        getFrameBuffer().getColorBuffer(1)->unbind();
                            glActiveTexture(GL_TEXTURE0);
                            glDisable(GL_TEXTURE_2D);
                        getFrameBuffer().getColorBuffer(0)->unbind();
                    vao.unbind();
                glUseProgram(0);
            }

            void DeferredRenderer::startFBO() {
                getFrameBuffer().bind();
                    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                    glActiveTexture(GL_TEXTURE0);
                    glEnable(GL_TEXTURE_2D);

                    GLenum buffers[] = {GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1, GL_COLOR_ATTACHMENT2};
                    glDrawBuffers(3, buffers);
            }

            void DeferredRenderer::endFBO() {
                getFrameBuffer().unbind();
            }

            void DeferredRenderer::fillBuffer() {
                GLint vData[18] = {
                    0, 0, 0, getFrameBuffer().getSize().getX(), 0, 0, getFrameBuffer().getSize().getX(), getFrameBuffer().getSize().getY(), 0,
                    getFrameBuffer().getSize().getX(), getFrameBuffer().getSize().getY(), 0, 0, getFrameBuffer().getSize().getY(), 0, 0, 0, 0
                };

                GLuint uvData[12] = {
                    0, 0, 1, 0, 1, 1,
                    1, 1, 0, 1, 0, 0
                };

                std::vector<GLvoid*> data;
                data.push_back(vData);
                data.push_back(uvData);

                buffer.allocateAndFill(sizeof(GLint), 12, GL_STATIC_DRAW, data);
                vao.access(buffer, GL_INT, true);
            }

        };
    };
