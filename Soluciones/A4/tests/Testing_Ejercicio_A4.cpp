/**
 * @file      Testing_Ejercicio_A4.cpp
 * @brief     Verifica a forEachDiagonal 
 * @date      2025-05-30
 */
#include <cassert>
#include <sstream>
#include <iostream>
#include "MatrixOp.h"

int main()
{
    MatrixOp M{3,3};
    for(int i=0;i<3;++i)
        for(int j=0;j<3;++j)
            M.set(i,j, (i+1)*10 + j);   

    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    M.forEachDiagonal(&MatrixOp::printAt);
    std::cout.rdbuf(old);              

    assert(buffer.str() == "10 21 32 ");

    return 0;
}
