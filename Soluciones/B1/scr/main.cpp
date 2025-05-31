/**
 * @file      main.cpp
 * @brief     Demo B1
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
    
    int val = 1;
    for(int i=0;i<2;++i)
        for(int j=0;j<2;++j)
            A.set(i,j,val++);     

    val = 5;
    for(int i=0;i<2;++i)
        for(int j=0;j<2;++j)
            B.set(i,j,val++);     

    MatrixOp C = A + B;
    MatrixOp D = A - B;

    std::cout << "A:\n"; printMatrix(A);
    std::cout << "B:\n"; printMatrix(B);
    std::cout << "C = A + B:\n"; printMatrix(C);
    std::cout << "D = A - B:\n"; printMatrix(D);

    std::cout << "C[0,0] = " << C.get(0,0) << '\n';
    std::cout << "D[1,1] = " << D.get(1,1) << '\n';
}
