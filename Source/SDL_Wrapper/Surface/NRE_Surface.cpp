
    #include "NRE_Surface.hpp"

    namespace NRE {
        namespace SDL {

            Surface::Surface() : item(0) {
            }

            Surface::Surface(std::string const& path) : item(0) {
            }

            Surface::Surface(Surface const& s) : item(s.getItem()) {
            }

            Surface::Surface(SDL_Surface* const& s) : item(s) {
            }

            Surface::~Surface() {
                SDL_FreeSurface(getItem());
            }

            SDL_Surface* const& Surface::getItem() const {
                return item;
            }

            SDL_Rect const& Surface::getClipRect() const {
                return getItem()->clip_rect;
            }

            Uint32 const& Surface::getFlags() const {
                return getItem()->flags;
            }

            PixelFormat const Surface::getFormat() const {
                return PixelFormat(getItem()->format);
            }

            int const& Surface::getW() const {
                return getItem()->w;
            }

            int const& Surface::getH() const {
                return getItem()->h;
            }

            Maths::Vector2D<int> const Surface::getSize() const {
                return Maths::Vector2D<int>(getW(), getH());
            }

            int const& Surface::getPitch() const {
                return getItem()->pitch;
            }

            void* const& Surface::getPixels() const {
                return getItem()->pixels;
            }


        };
    };
