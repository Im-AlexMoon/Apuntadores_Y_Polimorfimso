/**
 * @file      main.cpp
 * @brief     Demo B3
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
 
    IMatrix* m2 = new MatrixOp(2,2);
    auto* m2c = dynamic_cast<MatrixOp*>(m2);
    m2c->set(0,0,1); m2c->set(0,1,2);
    m2c->set(1,0,3); m2c->set(1,1,4);  

    std::cout << "Matriz 2×2:\n"; printMatrix(*m2c);
    std::cout << "Determinante 2×2 = " << m2->determinant() << "\n\n";

   
    IMatrix* m3 = new MatrixOp(3,3);
    auto* m3c = dynamic_cast<MatrixOp*>(m3);
    int v=1;
    for(int i=0;i<3;++i)
        for(int j=0;j<3;++j)
            m3c->set(i,j,v++);           

    std::cout << "Matriz 3×3:\n"; printMatrix(*m3c);
    std::cout << "Determinante 3×3 = " << m3->determinant() << "\n";

    delete m2;
    delete m3;
}
