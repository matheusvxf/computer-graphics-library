#ifndef _MAIN_H_
#define _MAIN_H_

#include "World.h"
#include "Cube.h"
#include "Ball.h"

class World;

namespace Globals
{
    extern Cube cube;
    extern Ball ball;
    extern World world;
    extern Object* curr_obj;
};

#endif