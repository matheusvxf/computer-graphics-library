#ifndef _MATRIX4_H_
#define _MATRIX4_H_

#include "DataType.h"
#include "Vector3.h"
#include "Vector4.h"

#include <string>

class Matrix4
{
private:
    class Matrix4row
    {
    private:
        Matrix4* owner;
        UINT8 row;
        
    public:
        Matrix4row(Matrix4* owner, UINT8 row);
        Matrix4row& operator=(const Vector4& vector);
        double operator[](UINT8 column) const;
        double& operator[](UINT8 column);
    };
protected:
    double m[4][4];   // matrix elements; first index is for rows, second for columns (row-major)

public:
    Matrix4();
    Matrix4& operator=(const Matrix4&);
    Matrix4 operator*(const Matrix4& m2) const;
    Matrix4& operator*=(const Matrix4& m);
    Vector4 operator*(const Vector4& v) const;
    Matrix4row operator[](UINT8 row);
    void setColumn(UINT8 column, const Vector4& v);
    double* getPointer();
    void identity();
    void transpose();
    void makeRotateX(double angle);
    void makeRotateY(double angle);
    void makeRotateZ(double angle);
    void makeRotate(double angle, const Vector3& axis);
    void makeScale(double sx, double sy, double sz);
    void makeTranslate(double sx, double sy, double sz);
    void print(std::string s);
    std::string toString();
};

#endif