#include "Object.h"
#include "DataType.h"

#include <iostream>
#include <string>
#include <sstream>

Object::Object()
{
    mass = 10.0;
    friction = 1;
    dt = 1.0 / 60.0;
    angleY = 0.0;
    angleZ = 0.0;
    scale = 1.0;
    spin_clockwise = FALSE;
}

Object::~Object()
{
}

void Object::update()
{
    Vector4 acceleration;
    force -= velocity * friction;
    acceleration = force / mass;
    velocity += acceleration * dt;
    position += velocity * dt;
    force.init(0, 0, 0, 1);
    model2world.setColumn(3, position);
}

Matrix4& Object::getMatrix()
{
    return model2world;
}

void Object::rotateY(double deg)   // deg is in degrees
{
    angleY = angleY + (spin_clockwise ? -deg : deg);
    if (angleY > 360.0 || angleY < -360.0)
        angleY = 0.0;
    updateMatrix();
}

void Object::rotateZ(double deg)
{
    angleZ += deg;
    if (angleZ > 360.0 || angleY < -360.0)
        angleZ = 0.0;
    updateMatrix();
}

void Object::addScale(double sca)
{
    scale += sca;
    if (scale <= 0.1)
        scale = 0.1;
    updateMatrix();
}

void Object::updateMatrix()
{
    Matrix4 m_scale, m_rotateZ;
    model2world.makeRotateY(angleY);   // This creates the matrix to rotate the Object
    m_scale.makeScale(scale, scale, scale);
    m_rotateZ.makeRotateZ(angleZ);
    model2world *= m_rotateZ * m_scale;
}

void Object::spinToggle()
{
    spin_clockwise = !spin_clockwise;
}

void Object::applyForce(const Vector4& force)
{
    this->force += force;
}

Vector4& Object::getPosition()
{
    return this->position;
}

void Object::reset()
{
    position.init(0, 0, 0, 1);
    force = velocity = position;
    angleY = 0.0;
    angleZ = 0.0;
    scale = 1.0;
}

void Object::print()
{
    std::cout << toString() << std::endl;
}

std::string Object::toString()
{
    std::stringstream buffer;
    buffer << "position: " << this->position.toString() << std::endl;
    buffer << "matrix: " << std::endl << this->model2world.toString();
    return buffer.str();
}