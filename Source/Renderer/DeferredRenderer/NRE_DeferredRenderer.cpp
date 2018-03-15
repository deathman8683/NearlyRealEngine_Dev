
    #include "NRE_BufferObject.hpp"

    namespace NRE {
        namespace GL {

            DeferredRenderer::DeferredRenderer() {
            }

            DeferredRenderer::DeferredRenderer(Maths::Vector2D<GLushort> const& size) : gBuffer(size.getX(), size.getY()) {
            }

            DeferredRenderer::DeferredRenderer(DeferredRenderer const& renderer) : gBuffer(renderer.getFrameBuffer()), modelview(renderer.getModelview()), projection(renderer.getProjection()) {
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

            void DeferredRenderer::setFrameBuffer(GL::FBO const& buffer) {
                gBuffer = buffer;
            }

            void DeferredRenderer::setModelview(Maths::Matrix4x4<NREfloat> const& mat) {
                modelview = mat;
            }

            void DeferredRenderer::setProjection(Maths::Matrix4x4<NREfloat> const& mat) {
                projection = mat;
            }

            void DeferredRenderer::render(Shader const& shader) {

            }

        };
    };
