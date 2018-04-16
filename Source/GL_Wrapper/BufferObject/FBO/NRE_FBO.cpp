
    #include "NRE_FBO.hpp"

    namespace NRE {
        namespace GL {

            GLenum FBO::DEFAULT_FORMAT = GL_RGBA;
            GLenum FBO::DEFAULT_INTERNAL_FORMAT = GL_RGBA;

            FBO::FBO() {
            }

            FBO::FBO(GLsizei const& w, GLsizei const& h) : FrameBuffer::FrameBuffer(true), depthBuffer(0), size(w, h) {
            }

            FBO::FBO(FBO const& buf) : BufferObject::BufferObject(buf), FrameBuffer::FrameBuffer(buf), colorBuffer(buf.getColorBuffers()), depthBuffer(buf.getDepthBuffer()) {
            }

            FBO::~FBO() {
                for (Texture2D* buf : colorBuffer) {
                    delete buf;
                }
                colorBuffer.clear();
                delete depthBuffer;
            }

            std::vector<Texture2D*> const& FBO::getColorBuffers() const {
                return colorBuffer;
            }

            Texture2D* const& FBO::getColorBuffer(GLuint const& index) const {
                return colorBuffer[index];
            }

            DepthBuffer* const& FBO::getDepthBuffer() const {
                return depthBuffer;
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

            void FBO::setDepthBuffer(DepthBuffer* const& buffer) {
                depthBuffer = buffer;
            }

            void FBO::setSize(Maths::Vector2D<GLushort> const& size) {
                this->size = size;
            }

            void FBO::allocateColorBuffer(GLuint const& nbColorBuffer, std::vector<GLenum> const& format, std::vector<GLint> const& internalFormat, std::vector<GLenum> const& type) {
                bind();
                    for (GLuint i = 0; i < nbColorBuffer; i = i + 1) {
                        push_back(new Texture2D(getSize().getW(), getSize().getH(), format[i], internalFormat[i], type[i]));
                        colorBuffer.at(i)->attach(GL_COLOR_ATTACHMENT0 + i);
                    }
                unbind();
            }

            void FBO::attachDepthBuffer(GLenum const& attachment) const {
                bind();
                    depthBuffer->attach(attachment);
                unbind();
            }

            void FBO::push_back(Texture2D* const& buffer) {
                colorBuffer.push_back(buffer);
            }

            void FBO::checkIntegrity() {
                bind();
                    GLenum err = glCheckFramebufferStatus(GL_FRAMEBUFFER);
                    if (err != GL_FRAMEBUFFER_COMPLETE) {
                        std::ostringstream errStr;
                        errStr << err;
                        throw (Exception::GLException("FrameBufferObject Error : " + errStr.str()));
                    }
                unbind();
            }

        };
    };
