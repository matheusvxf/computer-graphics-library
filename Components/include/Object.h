#pragma once

#include "Vector4.h"
#include "Matrix4.h"

class Object
{
public:
    enum ObjectType
    {
        Cube,
        Ball
    };
    ObjectType obj_type;
private:
    BOOLEAN spin_clockwise;

protected:
    double angleY;                   // rotation angle [degrees]
    double scale;
    double angleZ;

    Vector4 position;
    Vector4 velocity;
    Vector4 force;
    double mass;
    double friction;
    double dt;
    Matrix4 model2world;            // model matrix (transforms model coordinates to world coordinates)

public:
    Object();
    ~Object();

    virtual void render() = 0;

    virtual void update();
    virtual void reset();
    virtual void print();
    virtual std::string toString();

    Matrix4& getMatrix();
    Vector4& getPosition();
    void rotateY(double);      // spin cube [degrees]
    void rotateZ(double angle);
    void addScale(double sca);
    void updateMatrix();
    void spinToggle();
    void applyForce(const Vector4& force);
};

