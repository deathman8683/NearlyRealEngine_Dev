
    #include "NRE_Viewport.hpp"

    namespace NRE {
        namespace Support {

            Viewport::Viewport(bool const& createCurrentViewport) {
                if (createCurrentViewport) {
                    createCurrent();
                }
            }

            Viewport::Viewport(Maths::Vector2D<GLushort> const& wSize, Maths::Vector2D<GLushort> const& glSize) : wSize(wSize), glSize(glSize) {
            }

            Viewport::Viewport(Viewport const& v) : wSize(v.getWSize()), glSize(v.getGLSize()) {
            }

            Viewport::~Viewport() {
            }

            Maths::Vector2D<GLushort> const& Viewport::getWSize() const {
                return wSize;
            }

            Maths::Vector2D<GLushort> const& Viewport::getGLSize() const {
                return glSize;
            }

            void Viewport::setWSize(Maths::Vector2D<GLushort> const& size) {
                wSize = size;
            }

            void Viewport::setGLSize(Maths::Vector2D<GLushort> const& size) {
                glSize = size;
            }

            void Viewport::createCurrent() {
                GLint tmp[4];
                glGetIntegerv(GL_VIEWPORT, tmp);
                setWSize(Maths::Vector2D<GLushort>(tmp[0], tmp[1]));
                setGLSize(Maths::Vector2D<GLushort>(tmp[2], tmp[3]));
            }

        };
    };
