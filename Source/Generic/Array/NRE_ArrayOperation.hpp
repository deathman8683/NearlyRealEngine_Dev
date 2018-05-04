
    /**
     * @file NRE_ArrayOperation.hpp
     * @brief Declaration of Engine's Array's Function
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../NRE_Type.hpp"
    #include "../../Maths/NRE_Maths.hpp"

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace Array
         * @brief Engine's Array's generic function
         */
        namespace Array {

            /**
             * Compute the index of a 4D cell in a 1D array
             * @param  p    the point with 4D index
             * @param  size the 4D array size
             * @return      the computed index
             */
            GLuint const get1DIndexFrom4D(Maths::Point4D<GLuint> const& p, Maths::Vector4D<GLuint> const& size);
            /**
             * Compute the index of a 4D cell in a 1D array
             * @param  x    the first dimension index
             * @param  y    the second dimension index
             * @param  z    the third dimension index
             * @param  w    the fourth dimension index
             * @param  size the 4D array size
             * @return      the computed index
             */
            GLuint const get1DIndexFrom4D(GLuint const& x, GLuint const& y, GLuint const& z, GLuint const& w, Maths::Vector4D<GLuint> const& size);
            /**
             * Compute the index of a 3D cell in a 1D array
             * @param  p    the point with 3D index
             * @param  size the 3D array size
             * @return      the computed index
             */
            GLuint const get1DIndexFrom3D(Maths::Point3D<GLuint> const& p, Maths::Vector3D<GLuint> const& size);
            /**
             * Compute the index of a 3D cell in a 1D array
             * @param  x    the first dimension index
             * @param  y    the second dimension index
             * @param  z    the third dimension index
             * @param  size the 3D array size
             * @return      the computed index
             */
            GLuint const get1DIndexFrom3D(GLuint const& x, GLuint const& y, GLuint const& z, Maths::Vector3D<GLuint> const& size);
            /**
             * Compute the index of a 2D cell in a 1D array
             * @param  p    the point with 2D index
             * @param  size the 2D array size
             * @return      the computed index
             */
            GLuint const get1DIndexFrom2D(Maths::Point2D<GLuint> const& p, Maths::Vector2D<GLuint> const& size);
            /**
             * Compute the index of a 2D cell in a 1D array
             * @param  x    the first dimension index
             * @param  y    the second dimension index
             * @param  size the 2D array size
             * @return      the computed index
             */
            GLuint const get1DIndexFrom2D(GLuint const& x, GLuint const& y, Maths::Vector2D<GLuint> const& size);

        };
    };
