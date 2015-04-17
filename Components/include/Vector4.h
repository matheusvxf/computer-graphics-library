#pragma once

#include <string>

class Vector4
{
private:
	double v[4];

public:
	Vector4();
    Vector4(double x, double y, double z);
	Vector4(double x, double y, double z, double w);
    void init(double x, double y, double z, double w);
	~Vector4();

	Vector4 operator+(const Vector4&);
    Vector4 operator+=(const Vector4&);
    Vector4 operator-(const Vector4&);
    Vector4 operator-();
    Vector4 operator-=(const Vector4&);
    Vector4 operator*(double s) const;
    Vector4 operator/(double s);
	double& operator[](int index);
	double operator[](int index) const;
	void dehomogenize();
    void scale(double s);
    double dot(const Vector4& b) const;
	Vector4 cross(const Vector4& b) const;
    double length();
    Vector4& normalize();
	void print(const std::string& s);
	std::string toString();

	static double dot(const Vector4& a, const Vector4& b);
	static Vector4 cross(const Vector4& a, const Vector4& b);
};

