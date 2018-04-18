
    #include "NRE_CubeMap.hpp"

    namespace NRE {
        namespace GL {

            CubeMap::CubeMap() {
            }

            CubeMap::CubeMap(bool const& generate) {
                if (generate) {
                    generateID();
                }
            }

            CubeMap::CubeMap(CubeMap && buf) : Buffer::Buffer(std::move(buf)) {
            }

            CubeMap::~CubeMap() {
                deleteID();
            }

            void CubeMap::generateID() {
                glGenTextures(1, &id);
            }

            void CubeMap::deleteID() {
                glDeleteTextures(1, &id);
            }

            void CubeMap::bind() const {
                glBindTexture(GL_TEXTURE_CUBE_MAP, getID());
            }

            void CubeMap::unbind() const {
                glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
            }

            void CubeMap::allocate(GLint const& level, GLint const& internalFormat, GLsizei const& w, GLsizei const& h, GLenum const& format, bool const& callFilter) const {
                bind();
                    glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, level, internalFormat, w, h, 0, format, getType(), 0);
                    glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, level, internalFormat, w, h, 0, format, getType(), 0);
                    glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, level, internalFormat, w, h, 0, format, getType(), 0);
                    glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, level, internalFormat, w, h, 0, format, getType(), 0);
                    glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, level, internalFormat, w, h, 0, format, getType(), 0);
                    glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, level, internalFormat, w, h, 0, format, getType(), 0);
                    if (callFilter) {
                        applyFilter();
                    }
                unbind();
            }

            void CubeMap::update(GLint const& level, GLint const& xOffset, GLint const& yOffset, GLsizei const& w, GLsizei const& h, GLenum const& format, std::vector<GLvoid*> const& data) const {
                bind();
                    glTexSubImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, level, xOffset, yOffset, w, h, format, getType(), data[0]);
                    glTexSubImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, level, xOffset, yOffset, w, h, format, getType(), data[1]);
                    glTexSubImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, level, xOffset, yOffset, w, h, format, getType(), data[2]);
                    glTexSubImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, level, xOffset, yOffset, w, h, format, getType(), data[3]);
                    glTexSubImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, level, xOffset, yOffset, w, h, format, getType(), data[4]);
                    glTexSubImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, level, xOffset, yOffset, w, h, format, getType(), data[5]);
                unbind();
            }

            void CubeMap::allocateAndFill(GLint const& level, GLint const& internalFormat, GLsizei const& w, GLsizei const& h, GLenum const& format, std::vector<GLvoid*> const& data, bool const& callFilter) const {
                bind();
                    glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, level, internalFormat, w, h, 0, format, getType(), data[0]);
                    glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, level, internalFormat, w, h, 0, format, getType(), data[1]);
                    glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, level, internalFormat, w, h, 0, format, getType(), data[2]);
                    glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, level, internalFormat, w, h, 0, format, getType(), data[3]);
                    glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, level, internalFormat, w, h, 0, format, getType(), data[4]);
                    glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, level, internalFormat, w, h, 0, format, getType(), data[5]);
                    if (callFilter) {
                        applyFilter();
                    }
                unbind();
            }

            void CubeMap::access() const {
                bind();
            }

            CubeMap& CubeMap::operator=(CubeMap && buf) {
                Buffer::operator=(std::move(buf));
                return *this;
            }

        };
    };
