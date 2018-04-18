
    /**
     * @file NRE_CubeMap.hpp
     * @brief Declaration of Engine's GL's Object : CubeMap
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_Buffer.hpp"

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
             * @class CubeMap
             * @brief GL's Object : A specialized buffer for cubemap managing
             */
            class CubeMap : public Buffer {
                private:

                public:
                    //## Constructor ##//
                    CubeMap();
                    CubeMap(bool const& generate);

                    //## Copy-Constructor ##//
                    CubeMap(CubeMap const& buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                    virtual ~CubeMap();

                    //## Getter ##//
                    virtual GLenum const getType() const = 0;

                    //## Setter ##//

                    //## Methods ##//
                    void generateID();
                    void deleteID();
                    void bind() const override;
                    void unbind() const override;
                    void allocate(GLint const& level, GLint const& internalFormat, GLsizei const& w, GLsizei const& h, GLenum const& format, bool const& callFilter) const;
                    void update(GLint const& level, GLint const& xOffset, GLint const& yOffset, GLsizei const& w, GLsizei const& h, GLenum const& format, std::vector<GLvoid*> const& data) const;
                    void allocateAndFill(GLint const& level, GLint const& internalFormat, GLsizei const& w, GLsizei const& h, GLenum const& format, std::vector<GLvoid*> const& data, bool const& callFilter) const;
                    virtual void applyFilter() const = 0;
                    void access() const;

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
