#pragma once

#include "Object.h"
#include "World.h"

class Ball : public Object
{
    double radius;
public:
    Ball();
    ~Ball();
    void update();
    void render();
    void collide(const Vector4&);
	void collide(const Wall&);
    void reset();
};

