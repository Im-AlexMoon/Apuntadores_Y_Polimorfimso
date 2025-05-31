/**
 * @file      main.cpp
 * @brief     Demo A3
 * @date      2025-05-30
 */
#include <iostream>
#include "MatrixOp.h"

double sub(double a, double b) { return a - b; }
double mul(double a, double b) { return a * b; }

void printMatrix(const MatrixOp& M)
{
    for (int i = 0; i < M.getRows(); ++i) {
        for (int j = 0; j < M.getCols(); ++j)
            std::cout << M.get(i, j) << ' ';
        std::cout << '\n';
    }
}

int main()
{
    constexpr int R = 2, C = 3;
    MatrixOp A{R, C}, B{R, C}, Csub{R, C}, Cmul{R, C};

    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j) {
            A.set(i, j, i * C + j + 1);      
            B.set(i, j, 10 + i * C + j);   
        }

    A.apply(&A, &B, &Csub, sub);
    A.apply(&A, &B, &Cmul, mul);

    std::cout << "A:\n";       printMatrix(A);
    std::cout << "B:\n";       printMatrix(B);
    std::cout << "A - B:\n";   printMatrix(Csub);
    std::cout << "A * B:\n";   printMatrix(Cmul);
}
