#pragma once

#include "Base.h"
#include "Vector4.h"

#include <vector>

class Wall
{
public:
	Wall(Vector4 normal, Vector4 y, Vector4 center);
	Vector4 normal;
	Vector4 center;
	
	Base base;
};

class World
{
private:
    std::vector<Wall> walls;
public:
    World();
    ~World();

    void update();
};