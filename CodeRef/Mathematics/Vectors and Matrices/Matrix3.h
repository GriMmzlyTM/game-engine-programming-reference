#pragma once
#include "Vector3.h"

struct Matrix3 {
private:
    constexpr static unsigned SIZE = 3;
    float m[SIZE][SIZE];


    void SetRow(unsigned row, const Vector3& values) {
        for(unsigned i = 0; i < SIZE; ++i)
            m[row][i] = values[i];
    }

public:

    Matrix3() = default;
    Matrix3(float n00, float n01, float n02,
            float n10, float n11, float n12,
            float n20, float n21, float n22) {
        SetRow(0, {n00, n01, n02});
        SetRow(1, {n10, n11, n12});
        SetRow(2, {n20, n21, n22});
    }
    
    Matrix3(Vector3& r0, Vector3& r1, Vector3& r2) {
        SetRow(0, r0);
        SetRow(1, r1);
        SetRow(2, r2);
    }

    float& operator()(int i, int j) {
        return m[j][i];
    }

    const float& operator()(int i, int j) const {
        return m[j][i];
    }

    Vector3& operator[](int j) {
        return *reinterpret_cast<Vector3*>(m[j]);
    }

    const Vector3& operator[](int j) const {
        return *reinterpret_cast<const Vector3*>(m[j]);
    }
};
