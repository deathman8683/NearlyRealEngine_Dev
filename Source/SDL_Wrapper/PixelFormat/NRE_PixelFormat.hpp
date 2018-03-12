
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
                    PixelFormat();
                    PixelFormat(bool const& allocate, Uint32 const& format);

                    //## Copy-Constructor ##//
                    PixelFormat(PixelFormat const& pf);

                    //## Convertor ##//
                    PixelFormat(SDL_PixelFormat* const& pf);

                    //## Deconstructor ##//
                    ~PixelFormat();

                    //## Getter ##//
                    SDL_PixelFormat* const& getItem() const;
                    bool const& isAllocated() const;
                    Uint8 const& getBitsPerPixel() const;
                    Uint8 const& getBytesPerPixel() const;
                    Uint32 const& getRMask() const;
                    Uint32 const& getGMask() const;
                    Uint32 const& getBMask() const;
                    Uint32 const& getAMask() const;
                    Uint32 const& getFormat() const;

                    //## Setter ##//
                    void setItem(SDL_PixelFormat* const& pf);
                    void setAllocated(bool const& state);

                    //## Methods ##//

                    //## Access Operator ##//

                    //## Assignment Operator ##//

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
