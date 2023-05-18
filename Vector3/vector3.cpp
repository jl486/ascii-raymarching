#include "vector3.h"

float Vector3::length()
{
    return sqrt(x * x + y * y + z * z);
}

void Vector3::normalize()
{
    float vector_length = length();
    x = x / vector_length;
    y = y / vector_length;
    z = z / vector_length;
}

Vector3 Vector3::operator*(float fac)
{
    Vector3 out;
    out.x = x * fac;
    out.y = y * fac;
    out.z = z * fac;

    return out;
}

Vector3 Vector3::operator+(Vector3 other)
{
    Vector3 out;
    out.x = x + other.x;
    out.y = y + other.y;
    out.z = z + other.z;

    return out;
}

Vector3 Vector3::operator-(Vector3 other)
{
    Vector3 out;
    out.x = x - other.x;
    out.y = y - other.y;
    out.z = z - other.z;

    return out;
}

float Vector3::sqrt(const float n)
{
    const float halfn = 0.5f * n;

    union // get bits for floating value
    {
        float n;
        int i;
    } u;

    u.n = n;
    u.i = 0x5f3759df - (u.i >> 1); // gives initial guess y0

    return n * u.n * (1.5f - halfn * u.n * u.n); // Newton step, repeating increases accuracy
}

