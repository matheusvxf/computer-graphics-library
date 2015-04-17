#include "Ball.h"

#include <iostream>
#include <GL/glut.h>

static Vector4 gravity(0, -9.8, 0);

Ball::Ball()
{
    radius = 2.5;
    mass = 5;
	friction = 0.1;
    obj_type = Object::ObjectType::Ball;
    force = Vector4(rand() % 500, 5000, -5000);
}

Ball::~Ball()
{
}

void Ball::update()
{
    applyForce(gravity * mass);
    Object::update();
}

void Ball::render()
{
    Matrix4 glmatrix;
    glmatrix = model2world;
    glmatrix.transpose();
    glLoadMatrixd(glmatrix.getPointer());

    glBegin(GL_QUADS);

    glutSolidSphere(radius, 1024, 1024);

    glEnd();
}

void Ball::collide(const Vector4& point)
{
    Vector4 force;
    position = point;
    force = -(velocity).normalize() * 100;
    applyForce(force);
}

void Ball::collide(const Wall& wall){
	Vector4 force;
	double proj = (position - wall.center).dot(wall.normal);
	position -= wall.normal * proj;
	velocity -= wall.normal * proj * 150;
	force = Vector4(rand() % 5, rand() % 5, rand() % 5);
	applyForce(force);
}

void Ball::reset()
{
    Object::reset();
    force = Vector4(rand() % 500, 5000, -5000);
}