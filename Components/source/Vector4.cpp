#include "Vector4.h"

#include <sstream>
#include <iostream>

#define X v[0]
#define Y v[1]
#define Z v[2]
#define W v[3]

Vector4::Vector4()
{
    init(0, 0, 0, 1);
}

Vector4::Vector4(double x, double y, double z)
{
    init(x, y, z, 1);
}

Vector4::Vector4(double x, double y, double z, double w)
{
    init(x, y, z, w);
}

void Vector4::init(double x, double y, double z, double w)
{
    X = x;
    Y = y;
    Z = z;
    W = w;
}

Vector4::~Vector4()
{
}

Vector4 Vector4::operator+(const Vector4& vector)
{
	return Vector4(X + vector[0], Y + vector[1], Z + vector[2]);
}

Vector4 Vector4::operator+=(const Vector4& vector)
{
    X += vector[0];
    Y += vector[1];
    Z += vector[2];
    return (*this);
}

Vector4 Vector4::operator-(const Vector4& vector){
	return Vector4(X - vector[0], Y - vector[1], Z - vector[2]);
}

Vector4 Vector4::operator-()
{
    return Vector4(-X, -Y, -Z);
}

Vector4 Vector4::operator-=(const Vector4& vector)
{
    X -= vector[0];
    Y -= vector[1];
    Z -= vector[2];
    return (*this);
}

Vector4 Vector4::operator*(double s) const
{
    Vector4 result = (*this);
    result.scale(s);
    return result;
}

Vector4 Vector4::operator/(double s)
{
    return (*this) * (1 / s);
}

double Vector4::operator[](int index) const{
	return v[index];
}

double& Vector4::operator[](int index){
	return v[index];
}

void Vector4::dehomogenize(){
	W = 1;
}

void Vector4::scale(double s)
{
    X = s * X;
    Y = s * Y;
    Z = s * Z;
}

double Vector4::dot(const Vector4& a, const Vector4& b)
{
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

double Vector4::dot(const Vector4& b) const
{
    return X * b[0] + Y * b[1] + Z * b[2];
}

Vector4 Vector4::cross(const Vector4& a, const Vector4& b)
{
	return Vector4(a[1] * b[2] - a[2] * b[1],
		a[2] * b[0] - a[0] * b[2],
		a[0] * b[1] - a[1] * b[0]);
}

Vector4 Vector4::cross(const Vector4& b) const
{
	return Vector4(Y * b[2] - Z * b[1],
		Z * b[0] - X * b[2],
		X * b[1] - Y * b[0]);
}

double Vector4::length()
{
    return sqrt(X * X + Y * Y + Z * Z);
}

Vector4& Vector4::normalize()
{
    scale(1 / this->length());
    return (*this);
}

void Vector4::print(const std::string& s){
	std::cout << s << " : " << this->toString();
}

std::string Vector4::toString(){
	std::stringstream buffer;
	buffer.precision(2);
	buffer << "[" << X << "," << Y << "," << Z << "," << W << "]" << std::fixed;
	return buffer.str();
}
