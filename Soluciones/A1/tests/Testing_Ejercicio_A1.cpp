/**
 * @file      Testing_Ejercicio_A1.cpp
 * @brief     Prueba de humo simple para MatrixOp (Google Test no requerido).
 * @date      2025-05-30
 */
#include <cassert>
#include "MatrixOp.h"

int main()
{
    MatrixOp A{2, 2};
    A.set(0, 0, 3.14);
    A.set(1, 1, 2.71);

    assert(A.get(0, 0) == 3.14);
    assert(A.get(1, 1) == 2.71);

    bool threw = false;
    try { A.get(5, 5); } catch (const std::out_of_range&) { threw = true; }
    assert(threw && "Debe lanzar excepción por índice inválido.");

    return 0;
}
