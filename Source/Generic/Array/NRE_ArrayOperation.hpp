
    /**
     * @file NRE_<Class>.hpp
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

            GLuint const get1DIndexFrom4D(Maths::Point4D<GLuint> const& p, Maths::Vector4D<GLuint> const& size);
            GLuint const get1DIndexFrom4D(GLuint const& x, GLuint const& y, GLuint const& z, GLuint const& w, Maths::Vector4D<GLuint> const& size);
            GLuint const get1DIndexFrom3D(Maths::Point3D<GLuint> const& p, Maths::Vector3D<GLuint> const& size);
            GLuint const get1DIndexFrom3D(GLuint const& x, GLuint const& y, GLuint const& z, Maths::Vector3D<GLuint> const& size);
            GLuint const get1DIndexFrom2D(Maths::Point2D<GLuint> const& p, Maths::Vector2D<GLuint> const& size);
            GLuint const get1DIndexFrom2D(GLuint const& x, GLuint const& y, Maths::Vector2D<GLuint> const& size);

        };
    };
