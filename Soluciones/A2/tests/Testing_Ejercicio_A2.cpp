/**
 * @file      Testing_Ejercicio_A2.cpp
 * @brief     Prueba de humo para MatrixOp::add
 * @date      2025-05-30
 */
#include <cassert>
#include "MatrixOp.h"

int main()
{
    MatrixOp A{1, 3};
    MatrixOp B{1, 3};
    MatrixOp R{1, 3};

    A.set(0,0, 2);  A.set(0,1, 4);  A.set(0,2, 6);
    B.set(0,0, 1);  B.set(0,1, 3);  B.set(0,2, 5);

    A.add(&B, &R);

    assert(R.get(0,0) == 3);
    assert(R.get(0,1) == 7);
    assert(R.get(0,2) == 11);

    // Verifica que detecte desajuste en dimensiones
    MatrixOp Wrong{2,2};
    bool threw = false;
    try { A.add(&Wrong, &R); } catch (const std::invalid_argument&) { threw = true; }
    assert(threw);

    return 0;
}
