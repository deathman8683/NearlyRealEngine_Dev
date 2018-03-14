
    #include "NRE_FBO.hpp"

    namespace NRE {
        namespace GL {

            FBO::FBO() {
            }

            FBO::FBO(GLsizei const& w, GLisizei const& h) : FBO::FBO(w, h, 1) {
            }

            FBO::FBO(GLsizei const& w, GLisizei const& h, GLint const& nbColorBuffer) : FrameBuffer::FrameBuffer(true), depthStencilBuffer(true) {
                allocateColorBuffer(nbColorBuffer);
                allocateRenderBuffer
            }

            FBO::FBO(FBO const& buf) : BufferObject::BufferObject(buf), FrameBuffer::FrameBuffer(buf), colorBuffer(buf.getColorBuffers()), depthStencilBuffer(buf.getDepthStencilBuffer()) {
            }

            FBO::~FBO() {
                for (Texture2D* buf : colorBuffer) {
                    delete buf;
                }
                colorBuffer.clear();
            }

            std::vector<Texture2D*> const& FBO::getColorBuffers() const {
                return colorBuffer;
            }

            Texture2D* const& FBO::getColorBuffer(GLuint const& index) const {
                return colorBuffer[index];
            }

            RenderBuffer const& FBO::FBO::getDepthStencilBuffer() const {
                return depthStencilBuffer;
            }

            void FBO::setColorBuffers(std::vector<Texture2D*> const& buffers) {
                colorBuffer = buffers;
            }

            void FBO::setColorBuffer(GLuint const& index, Texture2D* const&& buffer) {
                colorBuffer[index] = buffer;
            }

            void FBO::setDepthStencilBuffer(RenderBuffer const& buffer) {
                depthStencilBuffer = buffer;
            }

            void FBO::allocateColorBuffer(GLint const& nbColorBuffer) {
                for (GLuint i = 0; i < nbColorBuffer; i = i + 1) {
                    push_back(new Texture2D())
                }
            }
            void FBO::allocateRenderBuffer();
            void FBO::push_back(Texture2D* const& buffer);
            void FBO::access();

        };
    };
