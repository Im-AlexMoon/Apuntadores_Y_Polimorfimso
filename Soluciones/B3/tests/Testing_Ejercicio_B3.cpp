/**
 * @file      Testing_Ejercicio_B3.cpp
 * @brief     Pruebas de humo para determinant().
 * @date      2025-05-30
 */
#include <cassert>
#include "MatrixOp.h"

int main()
{
    MatrixOp A{2,2};
    A.set(0,0,4); A.set(0,1,2);
    A.set(1,0,7); A.set(1,1,5);
    assert(A.determinant() == 6);

    MatrixOp I{3,3};
    for(int k=0;k<3;++k) I.set(k,k,1);
    assert(I.determinant() == 1);

    MatrixOp B{4,4};
    bool threw=false;
    try{ B.determinant(); }catch(const std::logic_error&){ threw=true; }
    assert(threw);

    return 0;
}
