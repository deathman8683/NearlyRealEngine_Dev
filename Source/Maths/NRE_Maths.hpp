
    /**
     * @file NRE_Maths.hpp
     * @brief Declaration of Engine's Maths's Functions
     * @author Louis ABEL
     * @version 1.0
     */

    #pragma once

    #include "../Generic/NRE_Type.hpp"

    namespace NRE {
        namespace Maths {

            /**
             * Compute the radian value from a degree value
             * @param  x the degree angle
             * @return   the converted radian angle
             */
            NREfloat const toRad(NREfloat const& x);
            /**
             * Compute the degree value from a radian value
             * @param  x the radian angle
             * @return   the converted degree angle
             */
            NREfloat const toDeg(NREfloat const& x);
            /**
             * Perform an almost equal test on 2 floating value
             * @param  a the first value to test
             * @param  b the second value to test
             * @return   the test result
             */
            bool const almostEqual(NREfloat const& a, NREfloat const& b);
            /**
             * Perform a linear interpolation
             * @param  a the first value to interpolate
             * @param  b the second value to interpolate
             * @param  f the scale factor
             * @return   the interpolated value
             */
            NREfloat const lerp(NREfloat const& a, NREfloat const& b, NREfloat const& f);
            /**
             * Compute the sign of a variable
             * @param  x the variable
             * @return   te computed sign (-1, 0, 1)
             */
            GLint const numSign(NREfloat const& x);
            /**
             * Compute the first integer in the bound
             * @param  x     the variable to compute
             * @param  delta the delta
             * @return       the computed integer
             */
            NREfloat const intBound(GLint const& x, NREfloat const& delta);
            /**
             * Compute the modulus of a variable
             * @param  x       the variable
             * @param  modulus the modulus
             * @return         the computed result
             */
            GLint const mod(GLint const& x, GLint const& modulus);

        };
    };

    #include "Point/2D/NRE_Point2D.hpp"
    #include "Vector/2D/NRE_Vector2D.hpp"
    #include "Matrix/2D/NRE_Matrix2x2.hpp"
    #include "Point/3D/NRE_Point3D.hpp"
    #include "Vector/3D/NRE_Vector3D.hpp"
    #include "Matrix/3D/NRE_Matrix3x3.hpp"
    #include "Point/4D/NRE_Point4D.hpp"
    #include "Vector/4D/NRE_Vector4D.hpp"
    #include "Matrix/4D/NRE_Matrix4x4.hpp"
    #include "Plane/NRE_Plane.hpp"
    #include "Frustum/NRE_Frustum.hpp"
