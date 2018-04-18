
    #include "NRE_FBO.hpp"

    namespace NRE {
        namespace GL {

            FBO::FBO() {
            }

            FBO::FBO(GLsizei const& w, GLsizei const& h) : FrameBuffer::FrameBuffer(true), depthBuffer(0), size(w, h) {
            }

            FBO::FBO(FBO && buf) : BufferObject::BufferObject(std::move(buf)), FrameBuffer::FrameBuffer(std::move(buf)), colorBuffers(std::move(buf.colorBuffers)), depthBuffer(std::move(buf.getDepthBuffer())) {
            }

            FBO::~FBO() {
                for (Texture2D* buf : colorBuffers) {
                    delete buf;
                }
                colorBuffers.erase(colorBuffers.begin(), colorBuffers.end());
                delete depthBuffer;
            }

            Texture2D* const& FBO::getColorBuffer(GLuint const& index) const {
                return colorBuffers[index];
            }

            DepthBuffer* const& FBO::getDepthBuffer() const {
                return depthBuffer;
            }

            Maths::Vector2D<GLushort> const& FBO::getSize() const {
                return size;
            }

            void FBO::setDepthBuffer(DepthBuffer* const& buffer) {
                depthBuffer = buffer;
            }

            void FBO::allocateColorBuffer(GLuint const& nbColorBuffer, std::vector<GLenum> const& format, std::vector<GLint> const& internalFormat, std::vector<GLenum> const& type) {
                bind();
                    for (GLuint i = 0; i < nbColorBuffer; i = i + 1) {
                        Texture2D *tmp = new Texture2D(getSize().getW(), getSize().getH(), format[i], internalFormat[i], type[i]);
                        tmp->attach(GL_COLOR_ATTACHMENT0 + i);
                        colorBuffers.push_back(tmp);
                    }
                unbind();
            }

            void FBO::attachDepthBuffer(GLenum const& attachment) const {
                bind();
                    depthBuffer->attach(attachment);
                unbind();
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

            FBO& FBO::operator=(FBO && buf) {
                BufferObject::operator=(std::move(buf));
                FrameBuffer::operator=(std::move(buf));
                colorBuffers = std::move(buf.colorBuffers);
                depthBuffer = std::move(buf.depthBuffer);
                size = std::move(buf.size);
                return *this;
            }

        };
    };
