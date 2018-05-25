
    #include "NRE_Surface.hpp"

    namespace NRE {
        namespace SDL {

            Surface::Surface(IO::File const& file) : item(0), glW(0), glH(0), glFormat(0), glInternalFormat(0) {
                loadByIMG(file);
            }

            Surface::Surface(GLsizei const& w, GLsizei const& h, GLenum const& glFormat, GLint const& glInternalFormat) : item(0), glW(w), glH(h), glFormat(glFormat), glInternalFormat(glInternalFormat) {
            }

            Surface::Surface(Surface const& s) : item(s.getItem()), glW(s.getGLW()), glH(s.getGLH()), glFormat(s.getGLFormat()), glInternalFormat(s.getGLInternalFormat()) {
            }

            Surface::Surface(Surface && s) : item(std::move(s.getItem())), glW(std::move(s.getGLW())), glH(std::move(s.getGLH())), glFormat(std::move(s.getGLFormat())), glInternalFormat(std::move(s.getGLInternalFormat())) {
            }

            Surface::Surface(SDL_Surface* const& s) : item(s) {
                loadFormat();
            }

            Surface::~Surface() {
                free();
            }

            SDL_Surface* const& Surface::getItem() const {
                return item;
            }

            GLsizei const& Surface::getGLW() const {
                return glW;
            }

            GLsizei const& Surface::getGLH() const {
                return glH;
            }

            GLenum const& Surface::getGLFormat() const {
                return glFormat;
            }

            GLint const& Surface::getGLInternalFormat() const {
                return glInternalFormat;
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

            void Surface::setGLW(GLsizei const& w) {
                glW = w;
            }

            void Surface::setGLH(GLsizei const& h) {
                glH = h;
            }

            void Surface::setGLFormat(GLenum const& f) {
                glFormat = f;
            }

            void Surface::setGLInternalFormat(GLint const& f) {
                glInternalFormat = f;
            }

            void Surface::free() {
                if (getItem() != 0) {
                    SDL_FreeSurface(getItem());
                    item = 0;
                }
            }

            void Surface::lock() {
                SDL_LockSurface(getItem());
            }

            void Surface::unlock() {
                SDL_UnlockSurface(getItem());
            }

            void Surface::loadByIMG(IO::File const& file) {
                if (!file.exist()) {
                    throw (Exception::FileNotExistingException(file.getPath()));
                }

                item = IMG_Load(file.getPath().c_str());

                if (item == 0) {
                    throw (Exception::SDLException("Could not load IMG : " + file.getPath()));
                }

                setGLW(getW());
                setGLH(getH());

                flip();

                try {
                    loadFormat();
                } catch (Exception::SDLException const& e) {
                    throw (Exception::SDLException("Unknown Pixel Format : " + file.getPath()));
                }
            }

            void Surface::flip() {
                Surface flippedSurface(SDL_CreateRGBSurface(SDL_SWSURFACE,
                                                            getW(),getH(),
                                                            getFormat().getBitsPerPixel(),
                                                            getFormat().getRMask(),
                                                            getFormat().getGMask(),
                                                            getFormat().getBMask(),
                                                            getFormat().getAMask()));

                lock();
                flippedSurface.lock();

                int pitch = getPitch();
                for (unsigned int currentLine = 0; currentLine < static_cast <unsigned int> (getH()); currentLine = currentLine + 1) {
                    memcpy(&((unsigned char*)flippedSurface.getPixels())[currentLine * pitch],
                           &((unsigned char*)getPixels())[(getH() - 1 - currentLine) * pitch],
                           pitch);
                }

                flippedSurface.unlock();
                unlock();

                free();
                item = flippedSurface.getItem();
                flippedSurface.item = 0;
            }

            void Surface::loadFormat() {
                if (getFormat().getBytesPerPixel() == 3) {
                    setGLInternalFormat(GL_RGB);
                    if (getFormat().getRMask() == 0xFF) {
                        setGLFormat(GL_RGB);
                    } else {
                        setGLFormat(GL_BGR);
                    }
                } else if (getFormat().getBytesPerPixel() == 4) {
                    setGLInternalFormat(GL_RGBA);
                    if (getFormat().getRMask() == 0xFF) {
                        setGLFormat(GL_RGBA);
                    } else {
                        setGLFormat(GL_BGRA);
                    }
                } else {
                    throw (Exception::SDLException("Unknown Pixel Format"));
                }
            }

            Surface& Surface::operator=(Surface const& s) {
                item = s.item;
                glW = s.glW;
                glH = s.glH;
                glFormat = s.glFormat;
                glInternalFormat = s.glInternalFormat;
                return *this;
            }

            Surface& Surface::operator=(Surface && s) {
                item = std::move(s.item);
                glW = std::move(s.glW);
                glH = std::move(s.glH);
                glFormat = std::move(s.glFormat);
                glInternalFormat = std::move(s.glInternalFormat);
                return *this;
            }


        };
    };
