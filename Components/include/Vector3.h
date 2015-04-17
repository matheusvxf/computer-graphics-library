#pragma once

#include <string>

class Vector3
{
private:
    double v[3];
public:
	Vector3(double x, double y, double z);
	~Vector3();
	
	Vector3 operator+(const Vector3&);
	Vector3 operator-(const Vector3&);
    double& operator[](int index);
    double operator[](int index) const;
	void negate();
	void scale(double s);
	double dot(const Vector3&, const Vector3&);
	Vector3 cross(const Vector3&, const Vector3&);
	double length();
	void normalize();
	void print(const std::string&);
	std::string toString();
};

