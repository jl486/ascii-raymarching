#include "vector3.h"

float Vector3::length() {
    return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

void Vector3::normalize() {
    // n = v / ||v||
    float vector_length = this->length();
    this->x = this->x / vector_length;
    this->y = this->y / vector_length;
    this->z = this->z / vector_length;
}

Vector3 Vector3::operator*(float fac) const {
    Vector3 out;
    out.x = this->x * fac;
    out.y = this->y * fac;
    out.z = this->z * fac;

    return out;
}

Vector3 Vector3::operator+(Vector3 other) const {
    Vector3 out;
    out.x = this->x + other.x;
    out.y = this->y + other.y;
    out.z = this->z + other.z;

    return out;
}

Vector3 Vector3::operator-(Vector3 other) const {
    Vector3 out;
    out.x = this->x - other.x;
    out.y = this->y - other.y;
    out.z = this->z - other.z;

    return out;
}

Vector3 Vector3::operator-() const {
    return { -this->x, -this->y, -this->z };
}

float Vector3::sqrt(const float n) {
    const float halfn = 0.5f * n;

    // get bits of floating-point value
    union {
        float n;
        int i;
    } u;

    u.n = n;

    u.i = 0x5f3759df - (u.i >> 1); // gives initial guess for Newton's method
    u.n = n * u.n * (1.5f - halfn * u.n * u.n); // Newton's method round one

    return u.n;
}

