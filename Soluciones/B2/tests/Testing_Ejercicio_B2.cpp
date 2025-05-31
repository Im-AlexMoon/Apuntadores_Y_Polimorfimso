/**
 * @file      Testing_Ejercicio_B2.cpp
 * @brief     Prueba de humo para maxValue<T>().
 * @date      2025-05-30
 */
#include <cassert>
#include "MatrixOp.h"

int main()
{
    MatrixOp M{1,5};
    double values[5] = { -3.0, 7.5, 2.1, 7.5, 0.0 };
    for(int j=0;j<5;++j)
        M.set(0,j, values[j]);

    double maxM = maxValue<double>(M.data(), M.size());
    assert(maxM == 7.5);

    int ints[4] = {1, 9, 3, 4};
    int maxi = maxValue<int>(ints, 4);
    assert(maxi == 9);

    bool threw = false;
    try { maxValue<double>(nullptr, 3); }
    catch(const std::invalid_argument&) { threw = true; }
    assert(threw);

    return 0;
}
