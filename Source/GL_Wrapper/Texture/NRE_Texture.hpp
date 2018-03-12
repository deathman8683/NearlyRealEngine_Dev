
    /**
     * @file NRE_Texture.hpp
     * @brief Declaration of Engine's GL's Object : Texture
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../../SDL_Wrapper/Surface/NRE_Surface.hpp"

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
             * @class Texture
             * @brief GL's Object : A simple texture
             */
            class Texture : public SDL::Surface {
                private:
                    GLuint id;

                public:
                    //## Constructor ##//
                    Texture();
                    Texture(std::string const& path);

                    //## Copy-Constructor ##//
                    Texture(Texture const& tex);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    ~Texture();

                    //## Getter ##//
                    GLuint const& getID() const;

                    //## Setter ##//
                    void setID(GLuint const& id);

                    //## Methods ##//
                    void generateID();
                    void deleteID();
                    void reload();
                    void bind() const;
                    void unbind() const;
                    void load();
                    void applyFilter();

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
