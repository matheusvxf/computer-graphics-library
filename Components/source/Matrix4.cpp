#include "Utility.h"
#include "Matrix4.h"

#include <iostream>
#include <sstream>
#include <cmath>

Matrix4::Matrix4row::Matrix4row(Matrix4* owner, UINT8 row)
{
    this->owner = owner;
    this->row = row;
}

Matrix4::Matrix4row& Matrix4::Matrix4row::operator=(const Vector4& vector)
{
    (*owner)[row][0] = vector[0];
    (*owner)[row][1] = vector[1];
    (*owner)[row][2] = vector[2];
    (*owner)[row][3] = vector[3];
    return *this;
}

double Matrix4::Matrix4row::operator[](UINT8 column) const
{
    return (*owner).m[row][column];
}

double& Matrix4::Matrix4row::operator[](UINT8 column)
{
    return (*owner).m[row][column];
}

Matrix4::Matrix4()
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            m[i][j] = 0;
        }
    }
}

Matrix4& Matrix4::operator=(const Matrix4& m2)
{
    if (this != &m2)
    {
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                m[i][j] = m2.m[i][j];
            }
        }
    }
    return *this;
}

Matrix4 Matrix4::operator*(const Matrix4& m) const
{
    Matrix4 result;

    for (register int i = 0; i < 4; ++i)
    {
        for (register int j = 0; j < 4; ++j)
        {
            for (register int k = 0; k < 4; ++k)
            {
                result.m[i][j] += this->m[i][k] * m.m[k][j];
            }
        }
    }

    return result;
}

Matrix4& Matrix4::operator*=(const Matrix4 &m)
{
    (*this) = (*this) * m;
    return *this;
}

Vector4 Matrix4::operator*(const Vector4& v) const
{
    Vector4 result;

    for (register int i = 0; i < 4; ++i)
    {
        for (register int j = 0; j < 4; ++j)
        {
            result[i] += this->m[i][j] * v[j];
        }
    }

    return result;
}

Matrix4::Matrix4row Matrix4::operator[](UINT8 row)
{
    return Matrix4row(this, row);
}

void Matrix4::setColumn(UINT8 column, const Vector4& v)
{
    m[0][column] = v[0];
    m[1][column] = v[1];
    m[2][column] = v[2];
    m[3][column] = v[3];
}

// return pointer to matrix elements
double* Matrix4::getPointer()
{
    return &m[0][0];
}

// set matrix to identity matrix
void Matrix4::identity()
{
    for (register UINT8 i = 0; i < 4; ++i)
    {
        for (register UINT8 j = 0; j < 4; ++j)
        {
            if (i == j)
                m[i][j] = 1.0;
            else
                m[i][j] = 0.0;
        }
    }
}

// transpose the matrix (mirror at diagonal)
void Matrix4::transpose()
{
    Matrix4 temp;
    for (register UINT8 i = 0; i < 4; ++i)
    {
        for (register UINT8 j = 0; j < 4; ++j)
        {
            temp.m[j][i] = m[i][j];
        }
    }
    *this = temp;  // copy temporary values to this matrix
}

void Matrix4::makeRotateX(double angle)
{
    angle = degree2rad(angle);
    identity();
    m[1][1] = cos(angle);
    m[1][2] = -sin(angle);
    m[2][1] = sin(angle);
    m[2][2] = cos(angle);
}

// Creates a rotation matrix which rotates about the y axis.
// angle is expected in degrees
void Matrix4::makeRotateY(double angle)
{
    angle = degree2rad(angle);
    identity();
    m[0][0] = cos(angle);
    m[0][2] = sin(angle);
    m[2][0] = -sin(angle);
    m[2][2] = cos(angle);
}

void Matrix4::makeRotateZ(double angle)
{
    angle = degree2rad(angle);
    identity();
    m[0][0] = cos(angle);
    m[0][1] = -sin(angle);
    m[1][0] = sin(angle);
    m[1][1] = cos(angle);
}

void Matrix4::makeRotate(double angle, const Vector3& axis)
{
    Vector3 u = axis;
    angle = degree2rad(angle);
    u.normalize();
    identity();
    m[0][0] = cos(angle) + u[0] * u[0] * (1 - cos(angle));
    m[0][1] = u[0] * u[1] * (1 - cos(angle)) - u[2] * sin(angle);
    m[0][1] = u[0] * u[2] * (1 - cos(angle)) + u[1] * sin(angle);
    m[1][0] = u[1] * u[0] * (1 - cos(angle)) + u[2] * sin(angle);
    m[1][1] = cos(angle) + u[1] * u[1] * (1 - cos(angle));
    m[1][2] = u[1] * u[2] * (1 - cos(angle)) - u[0] * sin(angle);
    m[2][0] = u[2] * u[0] * (1 - cos(angle)) - u[1] * sin(angle);
    m[2][1] = u[2] * u[1] * (1 - cos(angle)) + u[0] * sin(angle);
    m[2][2] = cos(angle) + u[2] * u[2] * (1 - cos(angle));
}

void Matrix4::makeScale(double sx, double sy, double sz)
{
    identity();
    m[0][0] = sx;
    m[1][1] = sy;
    m[2][2] = sz;
}

void Matrix4::makeTranslate(double sx, double sy, double sz)
{
    identity();
    m[0][3] = sx;
    m[1][3] = sy;
    m[2][3] = sz;
}

void Matrix4::print(std::string s)
{
    std::cout << s << " : " << std::endl << toString();
}

std::string Matrix4::toString()
{
    std::stringstream buffer;
    buffer.precision(2);
    for (register UINT8 i = 0; i < 4; ++i)
    {
        buffer << "|";
        for (register UINT8 j = 0; j < 4; ++j)
        {
            buffer << m[i][j] << "," << std::fixed;
        }
        buffer << m[i][3] << "|" << std::endl << std::fixed;
    }
    return buffer.str();
}