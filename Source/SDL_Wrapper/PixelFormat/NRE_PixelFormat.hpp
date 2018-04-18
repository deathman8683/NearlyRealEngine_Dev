
    /**
     * @file NRE_PixelFormat.hpp
     * @brief Declaration of Engine's SDL's Object : PixelFormat
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../Generic/NRE_Type.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace SDL
         * @brief Engine's SDL's Wrapper's Module
         */
        namespace SDL {

            /**
             * @class PixelFormat
             * @brief SDL's Object : Wrapper of SDL_PixelFormat*
             */
            class PixelFormat {
                private:
                    SDL_PixelFormat* item;
                    bool allocated;

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        PixelFormat();
                        /**
                         * Construct a pixelFormat from the given format
                         * @param allocate tell if PixelFormat has to be allocated or not
                         * @param format   the pixelFormat construction enum
                         */
                        PixelFormat(bool const& allocate, Uint32 const& format);

                    //## Copy-Constructor ##//
                        /**
                         * Copy pf into this
                         * @param pf the pixelFormat to copy the content
                         */
                        PixelFormat(PixelFormat const& pf);

                    //## Move-Constructor ##//
                        /**
                         * Move pf into this, leaving pf empty
                         * @param pf the pixelFormat to move
                         */
                        PixelFormat(PixelFormat && pf);

                    //## Convertor ##//
                        /**
                         * Convert a C-style SDL_PixelFormat into his wrapped version
                         * @param e the C-style SDL_PixelFormat
                         */
                        PixelFormat(SDL_PixelFormat* const& pf);

                    //## Deconstructor ##//
                        /**
                         * PixelFormat Deconstructor
                         */
                        ~PixelFormat();

                    //## Getter ##//
                        /**
                         * Wrapped Item getter
                         * @return the wrapped item
                         */
                        SDL_PixelFormat* const& getItem() const;
                        /**
                         * Allocated state getter
                         * @return the allocation state
                         */
                        bool const& isAllocated() const;
                        /**
                         * PixelFormat BitsPerPixel getter
                         * @return the bits per pixel value from the pixelFormat
                         */
                        Uint8 const& getBitsPerPixel() const;
                        /**
                         * PixelFormat BytesPerPixel getter
                         * @return the bytes per pixel value from the pixelFormat
                         */
                        Uint8 const& getBytesPerPixel() const;
                        /**
                         * PixelFormat Red mask getter
                         * @return the red mask value
                         */
                        Uint32 const& getRMask() const;
                        /**
                         * PixelFormat Green mask getter
                         * @return the green mask value
                         */
                        Uint32 const& getGMask() const;
                        /**
                         * PixelFormat Blue mask getter
                         * @return the blue mask value
                         */
                        Uint32 const& getBMask() const;
                        /**
                         * PixelFormat Alpha mask getter
                         * @return the alpha mask value
                         */
                        Uint32 const& getAMask() const;
                        /**
                         * PixelFormat format getter
                         * @return the pixelFormat's format
                         */
                        Uint32 const& getFormat() const;

                    //## Setter ##//
                        /**
                         * Allocation state setter
                         * @param state the new allocation state
                         */
                        void setAllocated(bool const& state);

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * Copy assigment of pf into this
                         * @param pf the pixelFormat to copy into this
                         * @return the reference of himself
                         */
                        PixelFormat& operator=(PixelFormat const& pf);
                        /**
                         * Move assigment of pf into this, leaving pf empty
                         * @param pf the pixelFormat to move into this
                         * @return the reference of himself
                         */
                        PixelFormat& operator=(PixelFormat && pf);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
