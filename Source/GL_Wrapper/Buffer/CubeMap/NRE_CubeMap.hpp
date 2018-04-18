
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
                        /**
                         * Default Constructor
                         */
                        CubeMap();
                        /**
                         * Construct the cubemap and generate or not his id
                         * @param generate tell if the base class has to generate an id or not
                         */
                        CubeMap(bool const& generate);

                    //## Copy-Constructor ##//
                        /**
                         * No copy allowed
                         * @param buf the cubemap to copy
                         */
                        CubeMap(CubeMap const& buf) = delete;

                    //## Move-Constructor ##//
                        /**
                         * Move buf into this, leaving buf empty
                         * @param buf the cubemap to move
                         */
                        CubeMap(CubeMap && buf);

                    //## Convertor ##//

                    //## Deconstructor ##//
                        /**
                         * CubeMap Deconstructor
                         */
                        virtual ~CubeMap();

                    //## Getter ##//
                        /**
                         * Return the cubeMap type enum, used with derived class
                         * @return the cubeMap type enum
                         */
                        virtual GLenum const getType() const = 0;

                    //## Setter ##//

                    //## Methods ##//
                        /**
                         * Generate the buffer's id with different OpenGL command for different buffer
                         */
                        void generateID();
                        /**
                         * Delete the buffer's id with different OpenGL command for different buffer
                         */
                        void deleteID();
                        /**
                         * Bind the current buffer with his custom target and OpenGL command
                         */
                        void bind() const override;
                        /**
                         * Unbind the current buffer with his custom target and OpenGL command
                         */
                        void unbind() const override;
                        /**
                         * Allocate the 6 cubemap face with given parameters
                         * @param level          the level of the texture used in mipmap
                         * @param internalFormat the texture's pixels' internal's format
                         * @param w              the texture's width
                         * @param h              the texture's height
                         * @param format         the texture's pixels' format
                         * @param callFilter     tell if the function has to apply filter or not for the given binding
                         */
                        void allocate(GLint const& level, GLint const& internalFormat, GLsizei const& w, GLsizei const& h, GLenum const& format, bool const& callFilter) const;
                        /**
                         * Update the 6 cubemap texture with given parameters
                         * @param level   the level of the texture used in mipmap
                         * @param xOffset the buffers xOffset for particular region update
                         * @param yOffset the buffers yOffset for particular region update
                         * @param w       the updated region width
                         * @param h       the updated region height
                         * @param format  the texture's pixels' format
                         * @param data    an array with pixels for all 6 faces
                         */
                        void update(GLint const& level, GLint const& xOffset, GLint const& yOffset, GLsizei const& w, GLsizei const& h, GLenum const& format, std::vector<GLvoid*> const& data) const;
                        /**
                         * Allocate the 6 cubemap face with given parameters and fill them with an array of data
                         * @param level          the level of the texture used in mipmap
                         * @param internalFormat the texture's pixels' internal's format
                         * @param w              the texture's width
                         * @param h              the texture's height
                         * @param format         the texture's pixels' format
                         * @param data           an array with pixels for all 6 faces
                         * @param callFilter     tell if the function has to apply filter or not for the given binding
                         */
                        void allocateAndFill(GLint const& level, GLint const& internalFormat, GLsizei const& w, GLsizei const& h, GLenum const& format, std::vector<GLvoid*> const& data, bool const& callFilter) const;
                        /**
                         * Cubemap specific filter
                         */
                        virtual void applyFilter() const = 0;
                        /**
                         * Store calls for VAO managing
                         */
                        void access() const;

                    //## Access Operator ##//

                    //## Assignment Operator ##//
                        /**
                         * No copy assigment allowed
                         * @param buf the cubemap to copy
                         */
                        CubeMap& operator=(CubeMap const& buf) = delete;
                        /**
                         * Move assigment of buf into this, leaving buf empty
                         * @param buf the cubemap to move into this
                         * @return the reference of himself
                         */
                        CubeMap& operator=(CubeMap && buf);

                    //## Shortcut Operator ##//

                    //## Arithmetic Operator ##//

                    //## Comparison Operator ##//

                    //## BitWise Operator ##//

                    //## Shift Operator ##//

                private:
            };

        };
    };
