
    /**
     * @file NRE_Texture2D.hpp
     * @brief Declaration of Engine's GL's Object : Texture2D
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_BufferObject.hpp"
    #include "../../Buffer/TextureBuffer/2D/NRE_Texture2DBuffer.hpp"
    #include "../../Buffer/DepthBuffer/NRE_DepthBuffer.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace GL
         * @brief Engine's OpenGL's Wrapper's Module
         */
        namespace GL {

            /**
             * @class Texture2D
             * @brief GL's Object : A simple 2D Texture
             */
            class Texture2D : public Texture2DBuffer, public BufferObject, public SDL::Surface, public DepthBuffer {
                private:
                    GLenum type;

                public:
                    //## Constructor ##//
                        /**
                         * Default Constructor
                         */
                        Texture2D();
                        /**
                         * Construct a texture with a path to a file which will be loaded by the SDL wrapper
                         * @param path the path to the texture file
                         */
                        Texture2D(std::string const& path);
                        /**
                         * Construct a texture base for further allocation
                         * @param w                the texture's width
                         * @param h                the texture's height
                         * @param glFormat         the texture's pixel format
                         * @param glInternalFormat the texture's pixel internal format
                         * @param t                the texture's type
                         */
                        Texture2D(GLsizei const& w, GLsizei const& h, GLenum const& glFormat, GLint const& glInternalFormat, GLenum const& t = DEFAULT_TYPE);

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param tex the texture to copy
                         */
                        Texture2D(Texture2D const& tex) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move tex into this, leaving tex empty
                         * @param tex the texture to move
                         */
                        Texture2D(Texture2D && tex);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * Texture2D Deconstructor
                         */
                        ~Texture2D();

                    //## Getter ##//
                        /**
                         * Return the texture type enum, used with derived class
                         * @return the texture type enum
                         */
                        GLenum const getType() const;
                        /**
                         * Return the texture target, used with derived class
                         * @return the texture target
                         */
                        GLenum const getTarget() const;

                    //## Setter ##//
                        /**
                         * Type setter
                         * @param t the new texture type
                         */
                        void setType(GLenum const& t);

                    //## Methods ##//
                        /**
                         * Bind the current texture with his custom target and OpenGL command
                         */
                        void bind() const;
                        /**
                         * Unbind the current texture with his custom target and OpenGL command
                         */
                        void unbind() const;
                        /**
                         * Allocate the texture storage
                         * @param callFilter tell if the function has to apply filter or not for the given binding
                         */
                        void allocate(bool const& callFilter);
                        /**
                         * Update a region of the texture storage
                         * @param xOffset the updated region xOffset
                         * @param yOffset the updated region yOffset
                         * @param data    the data to send
                         */
                        void update(GLint const& xOffset, GLint const& yOffset, GLvoid* const& data) const;
                        /**
                         * Allocate and fill the texture storage
                         * @param callFilter tell if the function has to apply filter or not for the given binding
                         */
                        void allocateAndFill(bool const& callFilter);
                        /**
                         * Texture2D specific filter
                         */
                        void applyFilter() const;
                        /**
                         * Attach the texture to a specific attachment point
                         * @param attachment the specific attachment point
                         */
                        void attach(GLenum const& attachment) const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy assigment allowed
                         * @param tex the texture to copy
                         */
                        Texture2D& operator=(Texture2D const& tex) = delete;
                        /**
                         * Move assigment of tex into this, leaving tex empty
                         * @param tex the texture to move into this
                         * @return the reference of himself
                         */
                        Texture2D& operator=(Texture2D && tex);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
                    static GLenum DEFAULT_TYPE; /**< The 2D texture default type enum */
            };

        };
    };
