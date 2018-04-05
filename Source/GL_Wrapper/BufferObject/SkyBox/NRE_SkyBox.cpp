
    #include "NRE_SkyBox.hpp"

    #define STB_IMAGE_IMPLEMENTATION

    #include <stb_image.h>

    namespace NRE {
        namespace GL {

            GLenum SkyBox::TYPE = GL_FLOAT;

            SkyBox::SkyBox() : CubeMap::CubeMap(true) {
            }

            SkyBox::SkyBox(SkyBox const& sb) : CubeMap::CubeMap(sb), BufferObject::BufferObject(sb) {
            }

            SkyBox::~SkyBox() {
            }

            GLenum const SkyBox::getType() const {
                return TYPE;
            }

            GLenum const SkyBox::getTarget() const {
                return GL_TEXTURE_CUBE_MAP;
            }

            void SkyBox::allocate(GLsizei const& w, GLsizei const& h, bool const& callFilter) {
                CubeMap::allocate(0, GL_RGB16F, w, h, GL_RGB, callFilter);
                setAllocated(true);
            }

            void SkyBox::applyFilter() const {
                glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
                glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
                glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
            }

        };
    };
