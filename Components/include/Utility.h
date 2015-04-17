#pragma once

#include "Config.h"

#define M_PI 3.14159265358979323846

#if (UTILITY_MACRO == TRUE)

#define degree2rad(angle) (angle / 180 * M_PI)
#define foreach(v, it) for(decltype(v.begin()) it = v.begin(); it != v.end(); ++it)

#else

/*******************************************************************************
*
*	Function		degree2rad
*		
*	Convert from degrees to radians
*
*	angle[in]:
*
*	Return	the angle in radians
*
*******************************************************************************/
double degree2rad(double angle);

#endif /* UTILITY_MACRO */