#include "../Test.h"
#include "../../Mathematics/Vectors and Matrices/Matrix3.h"

TEST(Matrix3, Should_Generate_Properly) {
    Matrix3 m(0, 1, 2, 3, 4, 5, 6, 7, 8);
    
    Vector3 r0(1, 2, 3);
    Vector3 r1(4, 5, 6);
    Vector3 r2(7, 8, 9);
    Matrix3 n(r0, r1, r2);

    std::cout << "done" << std::endl;
}