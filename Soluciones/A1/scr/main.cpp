/**
 * @file      main.cpp
 * @brief     Demostración A1.
 * @date      2025-05-30
 */
#include <iostream>
#include "MatrixOp.h"

int main()
{
    MatrixOp M{3, 3};

    for (int i = 0; i < M.getRows(); ++i)
        for (int j = 0; j < M.getCols(); ++j)
            M.set(i, j, i * M.getCols() + j + 1.0);

    std::cout << "Matriz M:\n";
    for (int i = 0; i < M.getRows(); ++i) {
        for (int j = 0; j < M.getCols(); ++j)
            std::cout << M.get(i, j) << ' ';
        std::cout << '\n';
    }
    std::cout << "Filas: " << M.getRows()
              << "  |  Columnas: " << M.getCols() << '\n';
}
