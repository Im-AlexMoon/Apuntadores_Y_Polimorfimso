/**
 * @file      main.cpp
 * @brief     Demo global (A1–A4)
 * @date      2025-05-30
 */
#include <iostream>
#include "MatrixOp.h"

//  A3
double sub(double a,double b){ return a-b; }
double mul(double a,double b){ return a*b; }

void printMatrix(const MatrixOp& M)
{
    for (int i = 0; i < M.getRows(); ++i){
        for (int j = 0; j < M.getCols(); ++j)
            std::cout << M.get(i,j) << ' ';
        std::cout << '\n';
    }
}

int main()
{
    constexpr int N = 4;
    MatrixOp A{N,N}, B{N,N}, Cadd{N,N}, Csub{N,N};

    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j){
            A.set(i,j, i*N + j + 1);
            B.set(i,j, 100 + i*N + j);
        }

    // A2: suma
    A.add(&B,&Cadd);

    // A3: resta
    A.apply(&A,&B,&Csub, sub);

    std::cout << "Matriz A:\n";        printMatrix(A);
    std::cout << "Matriz B:\n";        printMatrix(B);
    std::cout << "A + B:\n";           printMatrix(Cadd);
    std::cout << "A - B:\n";           printMatrix(Csub);

    // A4: imprimir la diagonal principal de A
    std::cout << "Diagonal de A: ";
    A.forEachDiagonal(&MatrixOp::printAt);
    std::cout << '\n';
}
