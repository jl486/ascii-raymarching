#ifndef VECTOR3_H
#define VECTOR3_H

struct Vector3
{
    float x;
    float y;
    float z;

    float length();
    void normalize();
    
    Vector3 operator*(float fac);

    Vector3 operator+(Vector3 other);
    Vector3 operator-(Vector3 other);


private:
    float sqrt(float n);
};

#endif
