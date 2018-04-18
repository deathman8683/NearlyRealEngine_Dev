
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
    #include <string>
    #include <vector>
    #include <memory>
    #include <GL/glew.h>
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include "Command/NRE_Command.hpp"

    //typedef GLdouble NREfloat;
    typedef GLfloat NREfloat;

    /**
     * @namespace NRE
     * @brief The global NearlyRealEngine's namespace
     */
    namespace NRE {
        /**
         * @namespace Global
         * @brief Engine's Global Module with different constant and macro
         */
        namespace Global {

            static const NREfloat PI = 3.14159265359;   /**< PI constant with float precision */
            static const NREfloat EPSILON = 0.00001;    /**< Engine's epsilon for float comparison */

        };
    };

    #define toRad(x) (x * NRE::Global::PI / 180.0)
    #define toDeg(x) (x * 180.0 / NRE::Global::PI)
    #define almostEqual(a, b) (std::abs(a - b) < NRE::Global::EPSILON)
