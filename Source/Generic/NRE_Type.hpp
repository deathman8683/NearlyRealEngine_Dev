
    #pragma once

    #include <cmath>
    #include <iostream>

    //typedef double NREfloat;
    typedef float NREfloat;

    namespace NRE {
        namespace Global {

            extern const NREfloat PI = 3.14159265359;
            extern const NREfloat EPSILON = 0.00001;
            
        };
    };

    #define toRad(x) (x * NRE::Global::PI / 180.0)
