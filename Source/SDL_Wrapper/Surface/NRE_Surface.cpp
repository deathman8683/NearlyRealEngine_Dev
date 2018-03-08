
    #include "NRE_Surface.hpp"

    namespace NRE {
        namespace SDL {

            Surface::Surface() : item(0) {
            }

            Surface::Surface(std::string const& path) : item(0) {
                loadByIMG(path);
            }

            Surface::Surface(Surface const& s) : item(s.getItem()) {
            }

            Surface::Surface(SDL_Surface* const& s) : item(s) {
            }

            Surface::~Surface() {
                free();
            }

            SDL_Surface* const& Surface::getItem() const {
                return item;
            }

            GLenum const& Surface::getGLFormat() const {
                return glFormat;
            }

            GLenum const& Surface::getGLInternalFormat() const {
                return glInternalFormat;
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

            void Surface::setItem(SDL_Surface* const& s) {
                item = s;
            }

            void Surface::setGLFormat(GLenum const& f) {
                glFormat = f;
            }

            void Surface::setGLInternalFormat(GLenum const& f) {
                glInternalFormat = f;
            }

            void Surface::free() {
                if (getItem() != 0) {
                    SDL_FreeSurface(getItem());
                }
            }

            void Surface::lock() {
                SDL_LockSurface(getItem());
            }

            void Surface::unlock() {
                SDL_UnlockSurface(getItem());
            }

            void Surface::loadByIMG(std::string const& path) {
                item = IMG_Load(path.c_str());

                flip();

                if (getFormat().getBitsPerPixel() == 3) {
                    setGLInternalFormat(GL_RGB);
                    if (getFormat().getRMask() == 0xFF) {
                        setGLFormat(GL_RGB);
                    } else {
                        setGLFormat(GL_BGR);
                    }
                } else if (getFormat().getBitsPerPixel() == 4) {
                    setGLInternalFormat(GL_RGBA);
                    if (getFormat().getRMask() == 0xFF) {
                        setGLFormat(GL_RGBA);
                    } else {
                        setGLFormat(GL_BGRA);
                    }
                }
            }

            void Surface::flip() {
                int pitch;
                Surface flippedSurface(SDL_CreateRGBSurface(SDL_SWSURFACE,
                                                            getW(),getH(),
                                                            getFormat().getBitsPerPixel(),
                                                            getFormat().getRMask(),
                                                            getFormat().getGMask(),
                                                            getFormat().getBMask(),
                                                            getFormat().getAMask()));

                lock();
                flippedSurface.lock();

                pitch = getPitch();
                for (unsigned int currentLine = 0; currentLine < static_cast <unsigned int> (getH()); currentLine = currentLine + 1) {
                    memcpy(&((unsigned char*)flippedSurface.getPixels())[currentLine * pitch],
                           &((unsigned char*)getPixels())[(getH() - 1 - currentLine) * pitch],
                           pitch);
                }

                flippedSurface.unlock();
                unlock();

                free();
                setItem(flippedSurface.getItem());
                flippedSurface.setItem(0);
            }


        };
    };
