
    #pragma once

    #define GLEW_STATIC
    
    #ifdef GLEW_STATIC
        #define GLEWAPI extern
    #else
        #ifdef GLEW_BUILD
            #define GLEWAPI extern __declspec(dllexport)
        #else
            #define GLEWAPI extern __declspec(dllimport)
        #endif
    #endif

    #include <cmath>
    #include <cassert>
    #include <iostream>

    //typedef double NREfloat;
    typedef float NREfloat;

    namespace NRE {
        namespace Global {

            static const NREfloat PI = 3.14159265359;
            static const NREfloat EPSILON = 0.00001;

        };
    };

    #define toRad(x) (x * NRE::Global::PI / 180.0)
    #define almostEqual(a, b) (std::abs(a - b) < NRE::Global::EPSILON)
