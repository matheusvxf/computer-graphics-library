#include "World.h"
#include "Utility.h"
#include "main.h"
#include "Ball.h"

Wall::Wall(Vector4 normal, Vector4 y, Vector4 center) :
	base(y.cross(normal), y, normal, center)
{
    this->normal = normal;
    this->center = center;
}

World::World()
{
    walls.push_back(Wall(Vector4(1, 0, 0), Vector4(0, 1, 0), Vector4(20, 0, 0)));
	walls.push_back(Wall(Vector4(-1, 0, 0), Vector4(0, 1, 0), Vector4(-20, 0, 0)));
	walls.push_back(Wall(Vector4(0, 1, 0), Vector4(1, 0, 0), Vector4(0, 20, 0)));
	walls.push_back(Wall(Vector4(0, -1, 0), Vector4(1, 0, 0), Vector4(0, 0, 0)));
    walls.push_back(Wall(Vector4(0, 0, 1), Vector4(0, 1, 0), Vector4(0, 0, 0)));
    walls.push_back(Wall(Vector4(0, 0, -1), Vector4(0, 1, 0), Vector4(0, 0, -40)));
}

World::~World()
{
}

void World::update()
{
    Vector4 pos;
    Ball* ball = dynamic_cast<Ball*>(Globals::curr_obj);

    if (ball != nullptr)
    {
        pos = ball->getPosition();
        foreach(walls, it)
        {
            if ((it->center - pos).dot(it->normal) < 0)
            { /* colision */
                ball->collide(*it);
            }
        }
    }
}
