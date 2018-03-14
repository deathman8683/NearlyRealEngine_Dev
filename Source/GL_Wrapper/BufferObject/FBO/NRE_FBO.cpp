
    #include "NRE_FBO.hpp"

    namespace NRE {
        namespace GL {

            GLenum FBO::DEFAULT_FORMAT = GL_RGBA;
            GLenum FBO::DEFAULT_INTERNAL_FORMAT = GL_RGBA;

            FBO::FBO() {
            }

            FBO::FBO(GLsizei const& w, GLsizei const& h) : FBO::FBO(w, h, 1) {
            }

            FBO::FBO(GLsizei const& w, GLsizei const& h, GLuint const& nbColorBuffer) : FrameBuffer::FrameBuffer(true), depthStencilBuffer(true), size(w, h) {
                allocateColorBuffer(nbColorBuffer);
                allocateRenderBuffer();
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

            RenderBuffer const& FBO::getDepthStencilBuffer() const {
                return depthStencilBuffer;
            }

            Maths::Vector2D<GLushort> const& FBO::getSize() const {
                return size;
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

            void FBO::setSize(Maths::Vector2D<GLushort> const& size) {
                this->size = size;
            }

            void FBO::allocateColorBuffer(GLuint const& nbColorBuffer) {
                bind();
                    for (GLuint i = 0; i < nbColorBuffer; i = i + 1) {
                        push_back(new Texture2D(getSize().getX(), getSize().getY(), DEFAULT_FORMAT, DEFAULT_INTERNAL_FORMAT));
                        attachColorBuffer(GL_COLOR_ATTACHMENT0 + i, *getColorBuffer(i));
                    }
                unbind();
            }

            void FBO::allocateRenderBuffer() {
                bind();
                    depthStencilBuffer.allocate(GL_DEPTH24_STENCIL8, getSize().getX(), getSize().getY());
                    attachRenderBuffer(GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, getDepthStencilBuffer().getID());
                unbind();
            }

            void FBO::push_back(Texture2D* const& buffer) {
                colorBuffer.push_back(buffer);
            }

        };
    };
