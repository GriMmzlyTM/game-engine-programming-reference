#pragma once
#include <complex>

/**

*/
struct Vector3 {
    float x, y, z;

    Vector3() = default;
    Vector3(float a, float b, float c) : x(a), y(b), z(c) {}

    Vector3& operator *=(float s) {
        x *= s;
        y *= s;
        z *= s;
        return (*this);
    }

    Vector3& operator /=(float s) {
        s = 1.0f / s;
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }

    Vector3& operator +=(float s) {
        x += s;
        y += s;
        z += s;
        return *this;
    }

    Vector3& operator -=(float s) {
        x -= s;
        y -= s;
        z -= s;
        return *this;
    }

    float& operator [](int i) {
        return (&x)[i];
    }

    
    const float& operator [](int i) const {
        return (&x)[i];
    }

};

inline Vector3 operator +(const Vector3& v1, const Vector3& v2) {
    return {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
}

inline Vector3 operator -(const Vector3& v1, const Vector3& v2) {
    return {v1.x - v2.x, v1.y - v2.y, v1.z - v2.z};
}

inline Vector3 operator *(const Vector3& v, float s) {
    return {v.x * s, v.y * s, v.z * s};
}

inline Vector3 operator /(const Vector3& v, float s) {
    s = 1.0f / s;
    return {v.x * s, v.y * s, v.z * s};
}

inline Vector3 operator -(const Vector3& v) {
    return {-v.x, -v.y, -v.z};
}

inline float Magnitude(const Vector3& v) {
    return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

inline Vector3 Normalize(const Vector3& v) {
    return v / Magnitude(v);
}
