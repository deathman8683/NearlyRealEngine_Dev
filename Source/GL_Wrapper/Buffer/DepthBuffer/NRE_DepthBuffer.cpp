
    #include "NRE_DepthBuffer.hpp"

    namespace NRE {
        namespace GL {

            DepthBuffer::DepthBuffer() {
            }

            DepthBuffer::~DepthBuffer() {
            }

            void DepthBuffer::clampToBorder(Maths::Vector4D<NREfloat> const& borderColor) const {
                bind();
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
                    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor.value());
                unbind();
            }

        };
    };
