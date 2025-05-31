/**
 * @file      Testing_Ejercicio_B1.cpp
 * @brief     Prueba de humo para B1
 * @date      2025-05-30
 */
#include <cassert>
#include "MatrixOp.h"

int main()
{
    MatrixOp A{1,3}, B{1,3};
   
    for(int j=0;j<3;++j){
        A.set(0,j, 2*(j+1));
        B.set(0,j, 1);
    }

    MatrixOp C = A + B;      
    MatrixOp D = A - B;      

    assert(C.get(0,0) == 3 && C.get(0,2) == 7);
    assert(D.get(0,1) == 3);

    MatrixOp Wrong{2,2};
    bool threw=false;
    try{ A + Wrong; }catch(const std::invalid_argument&){ threw=true; }
    assert(threw);

    return 0;
}
