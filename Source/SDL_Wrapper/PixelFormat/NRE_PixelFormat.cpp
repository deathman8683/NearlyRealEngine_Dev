
    #include "NRE_PixelFormat.hpp"

    namespace NRE {
        namespace SDL {

            PixelFormat::PixelFormat() : item(0), allocated(false) {
            }

            PixelFormat::PixelFormat(bool const& allocate, Uint32 const& format) : item(0), allocated(allocate) {
                if (allocate) {
                    item = SDL_AllocFormat(format);
                }
            }

            PixelFormat::PixelFormat(PixelFormat const& pf) : item(pf.getItem()), allocated(pf.isAllocated()) {
            }

            PixelFormat::PixelFormat(SDL_PixelFormat* const& pf) : item(pf), allocated(false) {
            }

            PixelFormat::~PixelFormat() {
                if (allocated) {
                    SDL_FreeFormat(item);
                }
            }

            SDL_PixelFormat* const& PixelFormat::getItem() const {
                return item;
            }

            bool const& PixelFormat::isAllocated() const {
                return allocated;
            }

            Uint8 const& PixelFormat::getBitsPerPixel() const {
                return getItem()->BitsPerPixel;
            }

            Uint8 const& PixelFormat::getBytesPerPixel() const {
                return getItem()->BytesPerPixel;
            }

            Uint32 const& PixelFormat::getRMask() const {
                return getItem()->Rmask;
            }

            Uint32 const& PixelFormat::getGMask() const {
                return getItem()->Gmask;
            }

            Uint32 const& PixelFormat::getBMask() const {
                return getItem()->Bmask;
            }

            Uint32 const& PixelFormat::getAMask() const {
                return getItem()->Amask;
            }

            Uint32 const& PixelFormat::getFormat() const {
                return getItem()->format;
            }

            void PixelFormat::setItem(SDL_PixelFormat* const& pf) {
                item = pf;
            }

            void PixelFormat::setAllocated(bool const& state) {
                allocated = state;
            }

        };
    };
