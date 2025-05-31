/**
 * @file      Testing_Ejercicio_A3.cpp
 * @brief     Prueba de humo para MatrixOp::apply.
 * @date      2025-05-30
 */
#include <cassert>
#include "MatrixOp.h"

double sub(double a, double b) { return a - b; }
double mul(double a, double b) { return a * b; }

int main()
{
    MatrixOp A{1, 4};
    MatrixOp B{1, 4};
    MatrixOp R1{1, 4};
    MatrixOp R2{1, 4};

    for (int j = 0; j < 4; ++j) {
        A.set(0, j, 2 * (j + 1));
        B.set(0, j, 2 * j + 1);
    }

    A.apply(&A, &B, &R1, sub);
    A.apply(&A, &B, &R2, mul);

    for (int j = 0; j < 4; ++j) {
        assert(R1.get(0, j) == 1);
    }
    assert(R2.get(0,0) ==  2);
    assert(R2.get(0,1) == 12);
    assert(R2.get(0,2) == 30);
    assert(R2.get(0,3) == 56);

    return 0;
}
