/**
 * @file      main.cpp
 * @brief     Demo A2
 * @date      2025-05-30
 */
#include <iostream>
#include "MatrixOp.h"

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
    const int R = 2, C = 3;

    MatrixOp A{R, C};
    MatrixOp B{R, C};
    MatrixOp Csum{R, C};

    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j) {
            A.set(i, j, i * C + j + 1);        
            B.set(i, j, 10 + i * C + j);          
        }

    A.add(&B, &Csum);

    std::cout << "Matriz A:\n";      printMatrix(A);
    std::cout << "Matriz B:\n";      printMatrix(B);
    std::cout << "A + B  (Csum):\n"; printMatrix(Csum);
}
