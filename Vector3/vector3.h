#pragma once

struct Vector3 {
    float x;
    float y;
    float z;

    float length();
    void normalize();
    
    // binary operations
    Vector3 operator+(const Vector3 other) const;
    Vector3 operator-(const Vector3 other) const;

    Vector3 operator*(const float fac) const;

    // unary operations
    Vector3 operator-() const;

private:
    float sqrt(float n);
};
