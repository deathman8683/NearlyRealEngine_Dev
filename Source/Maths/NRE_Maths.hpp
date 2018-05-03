
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

            NREfloat const toRad(NREfloat const& x);
            NREfloat const toDeg(NREfloat const& x);
            bool const almostEqual(NREfloat const& a, NREfloat const& b);
            NREfloat const lerp(NREfloat const& a, NREfloat const& b, NREfloat const& f);

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
