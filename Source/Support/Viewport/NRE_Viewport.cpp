
    #include "NRE_Viewport.hpp"

    namespace NRE {
        namespace Support {

            Viewport::Viewport() {
            }

            Viewport::Viewport(bool const& createCurrentViewport) {
                if (createCurrentViewport) {
                    createCurrent();
                }
            }

            Viewport::Viewport(Maths::Point2D<GLushort> const& coord, Maths::Vector2D<GLushort> const& size) : coord(coord), size(size) {
            }

            Viewport::Viewport(Viewport const& v) : coord(v.getCoord()), size(v.getSize()) {
            }

            Viewport::Viewport(Viewport && v) : coord(std::move(v.getCoord())), size(std::move(v.getSize())) {
            }

            Viewport::~Viewport() {
            }

            Maths::Point2D<GLushort> const& Viewport::getCoord() const {
                return coord;
            }

            Maths::Vector2D<GLushort> const& Viewport::getSize() const {
                return size;
            }

            void Viewport::setCoord(Maths::Point2D<GLushort> const& coord) {
                this->coord = coord;
            }

            void Viewport::setSize(Maths::Vector2D<GLushort> const& size) {
                this->size = size;
            }

            void Viewport::createCurrent() {
                GLint tmp[4];
                glGetIntegerv(GL_VIEWPORT, tmp);
                setCoord(Maths::Point2D<GLushort>(tmp[0], tmp[1]));
                setSize(Maths::Vector2D<GLushort>(tmp[2], tmp[3]));
            }

            Viewport& Viewport::operator=(Viewport const& v) {
                coord = v.getCoord();
                size = v.getSize();
                return *this;
            }

            Viewport& Viewport::operator=(Viewport && v) {
                coord = std::move(v.getCoord());
                size = std::move(v.getSize());
                return *this;
            }

        };
    };
