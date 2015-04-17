#include "Vector3.h"

#include <sstream>
#include <iostream>

#define X v[0]
#define Y v[1]
#define Z v[2]

Vector3::Vector3(double x, double y, double z)
{
    X = x;
    Y = y;
    Z = z;
}

Vector3::~Vector3()
{
}

Vector3 Vector3::operator+(const Vector3& vector)
{
	return Vector3(X + vector[0], Y + vector[1], Z + vector[2]);
}

Vector3 Vector3::operator-(const Vector3& vector){
    return Vector3(X - vector[0], Y - vector[1], Z - vector[2]);
}

double Vector3::operator[](int index) const
{
    return v[index];
}

double& Vector3::operator[](int index)
{
    return v[index];
}

void Vector3::negate(){
    X = -X;
	Y = -Y;
	Z = -Z;
}

void Vector3::scale(double s){
    X = s * X;
	Y = s * Y;
	Z = s * Z;
}

double Vector3::dot(const Vector3& a, const Vector3& b){
	return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

Vector3 Vector3::cross(const Vector3& a, const Vector3& b)
{
	return Vector3(a[1] * b[2] - a[2] * b[1],
		a[2] * b[0] - a[0] * b[2],
		a[0] * b[1] - a[1] * b[0]);
}

double Vector3::length(){
	return sqrt(X * X + Y * Y + Z * Z);
}

void Vector3::normalize(){
	scale(1 / this->length());
}

void Vector3::print(const std::string& s){
	std::cout << s << " : " << this->toString();
}

std::string Vector3::toString(){
	std::stringstream buffer;
	buffer << "[" << X << "," << Y << "," << Z << "]";
	return buffer.str();
}
