/**
 * @file      main.cpp
 * @brief     Demo B2 – maxValue<T>() junto con operadores + y -.
 * @date      2025-05-30
 */
#include <iostream>
#include "MatrixOp.h"

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
    MatrixOp A{2,2}, B{2,2};
    
    A.set(0,0,1); A.set(0,1,2);
    A.set(1,0,3); A.set(1,1,9);

    int val = 4;
    for(int i=0;i<2;++i)
        for(int j=0;j<2;++j)
            B.set(i,j,val++);

    MatrixOp C = A + B;
    MatrixOp D = A - B;

    std::cout << "A:\n"; printMatrix(A);
    std::cout << "Máximo de A: " << maxValue<double>(A.data(), A.size()) << '\n';

    std::cout << "B:\n"; printMatrix(B);
    std::cout << "C = A + B:\n"; printMatrix(C);
    std::cout << "D = A - B:\n"; printMatrix(D);
}
