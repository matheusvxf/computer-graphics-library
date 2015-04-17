#include "Cube.h"
#include "Matrix4.h"

#include <GL/glut.h>
#include <iostream>
#include <sstream>

using namespace std;

Cube::Cube()
{
    halfEdgeSize = 5.0;
    obj_type = Object::ObjectType::Cube;
}

void Cube::update()
{
    Object::update();
}

void Cube::render()
{
    // Tell OpenGL what ModelView matrix to use:
    Matrix4 glmatrix;
    glmatrix = model2world;
    glmatrix.transpose();
    glLoadMatrixd(glmatrix.getPointer());

    // Draw all six faces of the cube:
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);		// This makes the cube green; the parameters are for red, green and blue. 
    // To change the color of the other faces you will need to repeat this call before each face is drawn.
    // Draw front face:
    glNormal3f(0.0, 0.0, 1.0);
    glVertex3f(-halfEdgeSize, halfEdgeSize, halfEdgeSize);
    glVertex3f(halfEdgeSize, halfEdgeSize, halfEdgeSize);
    glVertex3f(halfEdgeSize, -halfEdgeSize, halfEdgeSize);
    glVertex3f(-halfEdgeSize, -halfEdgeSize, halfEdgeSize);

    // Draw left side:
    glNormal3f(-1.0, 0.0, 0.0);
    glVertex3f(-halfEdgeSize, halfEdgeSize, halfEdgeSize);
    glVertex3f(-halfEdgeSize, halfEdgeSize, -halfEdgeSize);
    glVertex3f(-halfEdgeSize, -halfEdgeSize, -halfEdgeSize);
    glVertex3f(-halfEdgeSize, -halfEdgeSize, halfEdgeSize);

    // Draw right side:
    glNormal3f(1.0, 0.0, 0.0);
    glVertex3f(halfEdgeSize, halfEdgeSize, halfEdgeSize);
    glVertex3f(halfEdgeSize, halfEdgeSize, -halfEdgeSize);
    glVertex3f(halfEdgeSize, -halfEdgeSize, -halfEdgeSize);
    glVertex3f(halfEdgeSize, -halfEdgeSize, halfEdgeSize);

    // Draw back face:
    glNormal3f(0.0, 0.0, -1.0);
    glVertex3f(-halfEdgeSize, halfEdgeSize, -halfEdgeSize);
    glVertex3f(halfEdgeSize, halfEdgeSize, -halfEdgeSize);
    glVertex3f(halfEdgeSize, -halfEdgeSize, -halfEdgeSize);
    glVertex3f(-halfEdgeSize, -halfEdgeSize, -halfEdgeSize);

    // Draw top side:
    glNormal3f(0.0, 1.0, 0.0);
    glVertex3f(-halfEdgeSize, halfEdgeSize, halfEdgeSize);
    glVertex3f(halfEdgeSize, halfEdgeSize, halfEdgeSize);
    glVertex3f(halfEdgeSize, halfEdgeSize, -halfEdgeSize);
    glVertex3f(-halfEdgeSize, halfEdgeSize, -halfEdgeSize);

    // Draw bottom side:
    glNormal3f(0.0, -1.0, 0.0);
    glVertex3f(-halfEdgeSize, -halfEdgeSize, -halfEdgeSize);
    glVertex3f(halfEdgeSize, -halfEdgeSize, -halfEdgeSize);
    glVertex3f(halfEdgeSize, -halfEdgeSize, halfEdgeSize);
    glVertex3f(-halfEdgeSize, -halfEdgeSize, halfEdgeSize);
    glEnd();
}